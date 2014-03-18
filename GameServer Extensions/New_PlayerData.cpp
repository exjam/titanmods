#include "main.h"
#include "pvp.h"

#include <SHO_GS\classUSER.h>
#include <SHO_GS\CUserDATA.h>
#include <SHO_GS\CObjAvt.h>
#include <SHO_GS\classPACKET.h>
#include <SHO_GS\CPacket.h>
#include <SHO_GS\CZoneTHREAD.h>
#include <SHO_GS\CObjMNG.h>
#include <SHO_GS\CZoneLIST.h>
#include <SHO_GS\CObjEVENT.h>

int GetRankByWins(int wins){
	int ranks[] = { 1, 3, 7, 15, 30, 55, 90, 135, 190, 255, 325, 400, 490, 600 };
	for(int i = 0; i < 14; ++i){
		if(wins < ranks[i])
			return i;
	}

	return 14;
}

void SetPlayerDATA(classUSER* pPlayer, classPACKET* cpak);
bool HasQuestAndTime(classUSER* pUSER, int QuestID);

// Flag can update during the game, quest not.
void _stdcall OnSwitch(int var, tagQuestData* data){
	if(var != 51) return; // CTF "Has Flag" = switch 51

	int* val = (int*)(((char*)data) - 0x27F);
	CUserDATA* udata = (CUserDATA*)val;
	classUSER* user = static_cast<classUSER*>(udata);

	SendPlayerToZone(user);
}

// Value changes -> Send to zone
void _stdcall SendPlayerToZone(classUSER* player){
	if(!player->IsUSER()) return;

	CZoneTHREAD* zone = player->GetZONE();
	if(!zone) return;

	classPACKET* cpak = Packet_AllocNLock();
	if(!cpak) return;

	SetPlayerDATA(player, cpak);
	zone->SendPacketToSectors(player, cpak);
	Packet_ReleaseNUnlock(cpak);
}

// Player to Player (on display spawn)
void _stdcall SendPlayerDATA(CGameOBJ* newObj, CGameOBJ* lstObj) {
	if(!newObj->IsUSER() || !lstObj->IsUSER()) return;

	classUSER* player1 = (classUSER*)lstObj;
	classUSER* player2 = (classUSER*)newObj;

	classPACKET* cpak = Packet_AllocNLock();
	if(!cpak) return;

	SetPlayerDATA(player1, cpak);
	player2->SendPacket(cpak);

	SetPlayerDATA(player2, cpak);
	player1->SendPacket(cpak);

	Packet_ReleaseNUnlock(cpak);
}

// Join Zone -> Send to Self
void _stdcall OnJoinZone(classUSER* player){
	if(!player->IsUSER()) return;

	if(classPACKET* cpak = Packet_AllocNLock()){
		SetPlayerDATA(player, cpak);
		player->SendPacket(cpak);
		Packet_ReleaseNUnlock(cpak);
	}

	if(player->m_nZoneNO == 77 || player->m_nZoneNO == 78 || player->m_nZoneNO == 79 || player->m_nZoneNO == 84)
		SendFlagDataToPlayer(player, player->m_nZoneNO);

	// Update index after respawning
	// issue: both dead -> both respawn : not an issue.
	// Player 1 respawns; updates IDX
	// Player 2 respawns; updates new idx too
	classUSER* enemy = GetDuelEnemy(player);
	if(!enemy) return;

	CustomAvatarData* data = CustomAvatarData::Get(enemy);

	if(player->GetZONE() != enemy->GetZONE()){
		EndDuel(enemy, player, 1);
		return;
	}

	data->pDuel.mRequestID = player->Get_INDEX();
	player->m_IngSTATUS.UpdateIngSTATUS(player, 57, 30, 1, 0, 0);
}

void SetPlayerDATA(classUSER* player, classPACKET* cpak){
	CPacket* pak = (CPacket*)cpak;
	CustomAvatarData* data = CustomAvatarData::Get(player);

	data->mData.mPvPRank = GetRankByWins(player->Get_AbilityValue(86));
	data->mData.mGameTeam = 0;

	data->mData.mArmor    = player->m_sArmorIDX;
	data->mData.mBoots    = player->m_sBootsIDX;
	data->mData.mGauntlet = player->m_sGauntletIDX;
	data->mData.mHelmet   = player->m_sHelmetIDX;
	data->mData.mBack = player->m_sKnapsackIDX;
	if(classUSER* enemy = GetDuelEnemy(player)){
		data->mData.mDuelEnemy = enemy->Get_INDEX();
		data->mData.mDuelCenterX = data->pDuel.mCenterX;
		data->mData.mDuelCenterY = data->pDuel.mCenterY;
	}else{
		data->mData.mDuelEnemy = 0;
		data->mData.mDuelCenterX = 0.0f;
		data->mData.mDuelCenterY = 0.0f;
	}

	if(player->m_nZoneNO >= 70){
		data->mData.mCtfFlag = (player->m_Quests.Get_SWITCH(51) && 
								 (HasQuestAndTime(player, 520) || HasQuestAndTime(player, 521) || 
								  HasQuestAndTime(player, 522) || HasQuestAndTime(player, 523) || 
								  HasQuestAndTime(player, 524) || HasQuestAndTime(player, 525) || 
								  HasQuestAndTime(player, 526) || HasQuestAndTime(player, 527)))
								 ? 1 : 0;

		for(unsigned int i = 0; i < gPvPQuests.Size(); ++i){
			PvPQuest* pQuest = gPvPQuests[i];
			if(HasQuestAndTime(player, pQuest->mQuest1)){
				data->mData.mGameTeam = 1;
				break;
			}else if(HasQuestAndTime(player, pQuest->mQuest2)){
				data->mData.mGameTeam = 2;
				break;
			} 
		}
	}

	pak->CreateNew(PAK_PLAYERDATA);
	pak->Add<WORD>(player->Get_INDEX());
	pak->Add<NewData>(data->mData);
}

bool HasQuestAndTime(classUSER* user, int quest) {
	unsigned char idx = user->Quest_GetRegistered(quest);
	return (idx < 10) && (user->m_Quests.m_QUEST[idx].GetRemainTIME() > 0);
}

void __declspec(naked) ASMSendPlayerDATAx() {
	static int jRet = 0x1004FC64;
	static int call1 = 0x10004120;
	_asm {
		CALL call1
		ADD ESP, 4

		MOV ECX,DWORD PTR SS:[EBP+0x8]
		ADD ECX,0xA0
		PUSH ECX
		MOV ECX,DWORD PTR SS:[EBP-0xC]
		MOV ECX,DWORD PTR DS:[ECX]
		PUSH ECX
		CALL SendPlayerDATA

		JMP jRet
	}
}

HookOnLoad(0x1004FC5C, ASMSendPlayerDATAx, 3);

void _declspec(naked) ASMOnSetSwitch() {
	static int jRet = 0x1000CBF4;
	_asm {
		 MOV ECX,DWORD PTR SS:[EBP-0x4]
		 ADD ESP,4

		 PUSHAD
		 PUSH ECX						// Data
		 PUSH DWORD PTR SS:[EBP+0x8]	// Switch
		 CALL OnSwitch
		 POPAD

		 CMP EBP,ESP
		 JMP jRet
	};
}

HookOnLoad(0x1000CBEF, ASMOnSetSwitch, 0);

void _declspec(naked) ASMOnJoinZone() {
	static int jRet = 0x10089926;
	_asm {
		MOV ECX,DWORD PTR SS:[EBP-0x4]
		SUB ECX,0xA0

		PUSHAD
		PUSH ECX
		CALL OnJoinZone
		POPAD

		POP ESI
		ADD ESP,0xC
		CMP EBP,ESP
		JMP jRet
	};
}

HookOnLoad(0x10089920, ASMOnJoinZone, 0);
