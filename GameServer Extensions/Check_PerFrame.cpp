#include "main.h"
#include "PvP.h"
#include "SendMessage.h"
#include "Achievements.h"
#include "CustomPartyData.h"

#include "..\Shared\RunOnLoad.hpp"
#include <SHO_GS\classPACKET.h>
#include <SHO_GS\CPacket.h>
#include <SHO_GS\GS_CThreadLOG.h>
#include <SHO_GS\CZoneLIST.h>
#include <SHO_GS\CObjNPC.h>
#include <SHO_GS\CObjMNG.h>
#include <SHO_GS\CObjMOB.h>

void CheckQuickSwap(classUSER* pUser);
void CheckBridge(classUSER* pUser);

/*
Start		"Fight Cheer"27
Death:		"Lose"553 |	"Laugh"26
End:		"Upset"550		"Dance"560		"Applause"21

*/

extern STBVALUE** g_TblSTATUS;

void ClearBadBuffs(classUSER* user){
	for(int i = 0; i <= 60 ; ++i){
		if(!g_TblSTATUS[i]) continue;
		if(g_TblSTATUS[i][3].GetINT() != 1) continue;

		int status = g_TblSTATUS[i][1].GetINT();
		user->m_IngSTATUS.ExpireSTATUS((eING_TYPE)status);
	}
}

void AddDuelScore(classUSER* victim, CustomAvatarData* vData){		
	classUSER* killer = GetDuelEnemy(victim);
	if(!killer) return;

	CustomAvatarData* kData = CustomAvatarData::Get(killer);
	kData->pDuel.mScore++;
	vData->pDuel.mIsDead = false;

	SendMSG(killer, CHAT_TYPE_WHISPER, String("[SCORE] %1: %2 - %3: %4").arg(killer->Get_NAME()).arg(kData->pDuel.mScore).arg(victim->Get_NAME()).arg(vData->pDuel.mScore));
	SendMSG(victim, CHAT_TYPE_WHISPER, String("[SCORE] %1: %2 - %3: %4").arg(victim->Get_NAME()).arg(vData->pDuel.mScore).arg(killer->Get_NAME()).arg(kData->pDuel.mScore));

	bool end = false;
	if(kData->pDuel.mMode == 0 && kData->pDuel.mScore == 1){
		end = true;
	}else if(kData->pDuel.mMode == 1 && kData->pDuel.mScore == 2){
		end = true;
	}else if(kData->pDuel.mMode == 2 && kData->pDuel.mScore == 3){	
		if(vData->pDuel.mScore == 0 && !kData->mAchievements.HasAchievement(100)){
			Achievement* ach = gAchievementList.GetByID(100);
			if(ach)
				UnlockAchievement(killer, ach);
		}

		end = true;
	}

	// Stop attacking
	victim->SetCMD_STOP();
	killer->SetCMD_STOP();

	// Death/Kill motions
	MotionValue value;
	value.m_wIsSTOP = 1;
	if(end){
		EndDuel(killer, victim, 0);

		short iRandNUM = rand() % 6; // 0 - 5 -> +65 [65 - 70]   6 -> next
		if(iRandNUM == 6){
			 iRandNUM = rand() % 3; // 0 - 3 -> +77 [77 - 80]
			 iRandNUM += 77;
		}else{
			iRandNUM += 65;
		}

		victim->Send_gsv_SET_MOTION(value.m_wValue, 553); // final lose
		killer->Send_gsv_SET_MOTION(value.m_wValue, iRandNUM); // random of 65-70 and 77-80
	}else{
		victim->Send_gsv_SET_MOTION(value.m_wValue, 30); // lose
		killer->Send_gsv_SET_MOTION(value.m_wValue, 26); // laught
	}

	// Remove de-buffs
	ClearBadBuffs(victim);
	ClearBadBuffs(killer);

	// Full heal
	victim->Set_HP(victim->Get_MaxHP());
	victim->Set_MP(victim->Get_MaxMP());
	killer->Set_HP(killer->Get_MaxHP());
	killer->Set_MP(killer->Get_MaxMP());

	// Update for party members
	victim->Send_gsv_SET_HPnMP(1);
	killer->Send_gsv_SET_HPnMP(1);

	// Update to self
	victim->Set_AbilityValueNSend(16, victim->Get_HP());
	victim->Set_AbilityValueNSend(17, victim->Get_MP());
	killer->Set_AbilityValueNSend(16, killer->Get_HP());
	killer->Set_AbilityValueNSend(17, killer->Get_MP());

	// Set spawn protect
	victim->m_IngSTATUS.UpdateIngSTATUS(victim, 57, 30, 1, 0, 0);
}

void CheckPvPQuestCancel(classUSER* user){
	if(!g_pZoneLIST) return;

	for(unsigned int i = 0; i < gPvPQuests.Size(); ++i){
		PvPQuest* quest = gPvPQuests[i];
		CObjNPC* npc = g_pZoneLIST->Get_LocalNPC(quest->mNPC);

		if(!npc || npc->Get_ObjVAR(0) != 4) continue; // Cancel?
		if(!user->m_Quests.Get_SWITCH(quest->mSwitch)) continue; // Has Switch?

		classPACKET* cpak = Packet_AllocNLock();
		if(!cpak) continue;

		CPacket* pak = (CPacket*)cpak;
		pak->CreateNew(0x684);
		pak->Add<unsigned char>(3);
		pak->Add<unsigned char>(0);
		pak->Add<unsigned int>(quest->mQuitRed);
		user->Recv_cli_QUEST_REQ((t_PACKET*)cpak);
		Packet_ReleaseNUnlock(cpak);
	}
}

void __stdcall Check_PerFrame(CObjAVT* pAVT){
	classUSER* pUSER = static_cast<classUSER*>(pAVT);
	CustomAvatarData* data = CustomAvatarData::Get(pUSER);
/*
	if(data->mLastCheck == 0){ // Spawn
		#pragma message("REMEMBER TO REMOVE SPAWN SHIT")
		#pragma message("REMEMBER TO REMOVE SPAWN SHIT")
		#pragma message("REMEMBER TO REMOVE SPAWN SHIT")
		#pragma message("REMEMBER TO REMOVE SPAWN SHIT")
		#pragma message("REMEMBER TO REMOVE SPAWN SHIT")
		#pragma message("REMEMBER TO REMOVE SPAWN SHIT")
		pUSER->Set_AbilityValueNSend( 86, 350 );
		pUSER->Set_AbilityValueNSend( 87, 10000 );
	}
*/
	if(data->mLastCheck == 0)
		Send_PvP_Vars_Login(pUSER);

	AchievementCheck(pUSER, data);

	if(data->pDuel.mInDuel){
		if(data->pDuel.mIsDead){
			AddDuelScore(pUSER, data);
		}else{
			CVec2 Pos2;
			Pos2.x = data->pDuel.mCenterX;
			Pos2.y = data->pDuel.mCenterY;
			if(classUSER* pEnemy = GetDuelEnemy(pUSER)){
				if(Distance(pUSER->m_PosCUR, Pos2) > 2500.0f)
					EndDuel(pEnemy, pUSER, 1);
				else if(Distance(pUSER->m_PosCUR, Pos2) > 1600.0f)
					pUSER->SetCMD_MOVE(pUSER->m_PosCUR, Pos2, 0);
			}
		}
	}

	clock_t dt = clock() - data->mLastCheck;
	if(dt < 5000) return;
	data->mLastCheck = clock();	

	CheckPvPQuestCancel(pUSER);

	if(pUSER->C_Cheater()) return;
	CheckQuickSwap(pUSER);
	CheckBridge(pUSER);
}

void __declspec(naked) ASMCheck_PerFrame(){
	static int retAddr = 0x1008FB02;
	static int callAddr = 0x1004A910;
	_asm {
		CALL callAddr
		PUSH EAX

		MOV ECX,DWORD PTR SS:[EBP-4]
		PUSH ECX
		CALL Check_PerFrame

		POP EAX
		JMP retAddr
	};
}

HookOnLoad(0x1008FAFD, ASMCheck_PerFrame, 0);

/*
void __declspec(naked) ASMCheck_PerFrame(){
	static int retAddr = 0x1006F1B6;
	_asm {
		PUSH EBP
		MOV EBP, ESP
		SUB ESP, 0x60
		PUSH ECX
		PUSH ECX
		CALL Check_PerFrame
		POP ECX
		JMP retAddr
	};
}

HookOnLoad(0x1006F1B0, ASMCheck_PerFrame, 1);

A_Cheater = RIGHT & 0x0300			256, 768				001100000000
B_Cheater = RIGHT & 0x0A00			768, 2048				101000000000	Only full GMs
C_Cheater = RIGHT & 0x0F00			256, 768, 1024, 2048	111100000000	All GMs
GM_Cheater = RIGHT & 0x0B00			256, 768, 2048			101100000000
TWGM_Cheater = RIGHT & 0x0E80		128, 768, 1024, 2048	111010000000
*/

void CheckQuickSwap(classUSER* user){
	for(int i = 1; i < MAX_EQUIP_IDX; ++i){
		tagITEM* equip = user->Get_EquipItemPTR(i);
		if(equip->IsEmpty() || user->Check_EquipCondition(*equip, i)) continue;

		//if (pUser->m_Inventory.GetEmptyInvenSlotCount(INV_WEAPON) != 0)
		user->Change_EQUIP_ITEM(i, 0);
		user->Send_gsv_WHISPER("SERVER", "Some equipment has been removed because its requirements were not met. Check your inventory.");  
	}
}

void CheckBridge(classUSER* pUser){
    CParty* party = pUser->GetPARTY();
	if(!party) return;

	classUSER* lowUsr, * highUsr;
    int low = 211, high = 0;
	int lowID, highID;

    for(int i = 0; i < 7; ++i){
		if(!party->m_pPartyUSERs[i]) continue;
		classUSER* member = party->m_pPartyUSERs[i]->m_pUSER;
		if(!member) continue;

		int level = member->Get_LEVEL();
		if(level < low){ 
			low = level; 
			lowUsr = member; 
			lowID = party->m_pPartyUSERs[i]->m_dwDBID;  
		}

		if(level > high){ 
			high = level; 
			highUsr = member; 
			highID = party->m_pPartyUSERs[i]->m_dwDBID; 
		}
    }

	if(CanParty(high, low)) return;

	if(party->GetPartyOWNER() == highUsr){
		lowUsr->Send_gsv_WHISPER("SERVER", "You were kicked for exceeding the party level limit.");    
		party->Kick_MEMBER(lowID);
	}else{ 
		highUsr->Send_gsv_WHISPER("SERVER", "You were kicked for exceeding the party level limit.");    
		party->Kick_MEMBER(highID);
    }
}