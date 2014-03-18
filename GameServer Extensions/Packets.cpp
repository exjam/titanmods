#include "main.h"
#include "PvP.h"
#include "Packets.h"
#include "SendMessage.h"

#include "..\Shared\RunOnLoad.hpp"
#include <SHO_GS\classPACKET.h>
#include <SHO_GS\CPacket.h>
#include <SHO_GS\CZoneTHREAD.h>
#include <SHO_GS\CQuestDATA.h>

void ProcAllyPacket(CPacket* pakr, classUSER* user){
	const char* text = pakr->GetString(0);
	if(text[0] == 0) return;

	CZoneTHREAD* zone = user->GetZONE();
	if(!zone || user->m_nZoneNO < 70) return;
	
	classPACKET* cpak = Packet_AllocNLock();
	if(!cpak) return;

	CPacket* pak = (CPacket*)cpak;
	pak->CreateNew(PAK_ALLYCHAT);
	pak->Add<short>(user->Get_INDEX());
	pak->AddString(user->Get_NAME());
	pak->AddString(text);

	for(classDLLNODE<CGameOBJ*>* pObj = zone->m_ObjLIST.m_pHEAD; pObj; pObj = pObj->m_pNEXT){
		CGameOBJ* object = pObj->DATA;
		if(!object || !object->IsUSER()) continue;
		if(object->Get_TEAM() != user->Get_TEAM()) continue;

		classUSER* ally = (classUSER*)object;
		ally->SendPacket(cpak);
	}

	Packet_ReleaseNUnlock(cpak);
}

void ClearPvpIpList(int npc){
	for(unsigned int i = 0; i < gPvPQuests.Size(); i++){
		PvPQuest* quest = gPvPQuests[i];
		if(quest->mNPC != npc) continue;

		for(unsigned int j = 0; j < quest->mPlayers.Size(); ++j){
			PvPPlayer* player = quest->mPlayers[j];
			if(player->mIP)
				delete [] player->mIP;
		}

		quest->mPlayers.Clear();
	}
}

bool RemoveUserFromQuest(PvPQuest* quest, classUSER* mUser){
	if(g_pQuestDATA->CheckQUEST(mUser, quest->mGiveUpBlue, false, mUser->m_iLastEventNpcIDX, 0, -1) != QST_RESULT_SUCCESS &&
	   g_pQuestDATA->CheckQUEST(mUser, quest->mGiveUpRed,  false, mUser->m_iLastEventNpcIDX, 0, -1) != QST_RESULT_SUCCESS)
	   return false;

	bool removed = false;
	for(unsigned int i = 0; i < quest->mPlayers.Size(); ++i){
		PvPPlayer* other = quest->mPlayers[i];
		if(other->mID != mUser->m_dwDBID) continue; 
		if(!other->mIP) continue;
		//if(_strcmpi(other->mIP, ip)) continue; 
		
		delete [] other->mIP;
		other->mIP = NULL;
		removed = true;
	}

	return removed;
}


void ProcQuestPacket(CPacket* pak, classUSER* user){
	if(pak->Get<unsigned char>(0) == 2){ //Delete
		int qid = pak->Get<int>(2);
		for(unsigned int i = 0; i < gPvPQuests.Size(); i++){
			PvPQuest* quest = gPvPQuests[i];
			if(user->m_Quests.Get_SWITCH(quest->mSwitch) == 0) continue;
			if(qid != quest->mQuest1 && qid != quest->mQuest2) continue;

			pak->CreateNew(0x684);
			pak->Add<unsigned char>(3);
			pak->Add<unsigned char>(0);
			pak->Add<unsigned int>(quest->mQuitRed);

			RemoveUserFromQuest(quest, user);
			break;
		}
	}else if (pak->Get<unsigned char>(0) == 3){ //Start Quest
		unsigned long hash = pak->Get<unsigned long>(2);
		char* ip = user->Get_IP();
		int id = user->m_dwDBID;
		int team = 0;

		for(unsigned int i = 0; i < gPvPQuests.Size(); ++i){
			PvPQuest* quest = gPvPQuests[i];

			if(hash == quest->mJoinRed) team = 1;
			if(hash == quest->mJoinBlue) team = 2;
			if(hash == quest->mQuitRed) team = 3;
			if(hash == quest->mQuitBlue) team = 4;

			if(team == 1 || team == 2){
				if(g_pQuestDATA->CheckQUEST(user, hash, false, user->m_iLastEventNpcIDX, 0, -1) != QST_RESULT_SUCCESS) continue;
				
				int sameTeamCount = 0;
				for(unsigned int i = 0; i < quest->mPlayers.Size(); ++i){
					PvPPlayer* other = quest->mPlayers[i];
					if(!other->mIP) continue;
					if(_strcmpi(other->mIP, ip)) continue;
					
					if(other->mTeam != team){
						SendMSG(user, CHAT_TYPE_SYSTEM, "Your IP has already been registered to the opposite team.", false, 0xFFFFFFFF);
						return;
					}

					if(other->mID == id){
						SendMSG(user, CHAT_TYPE_SYSTEM, "You have already been registered to this instance.", false, 0xFFFFFFFF);
						return;
					}

					if(other->mTeam == team) ++sameTeamCount;
					if(sameTeamCount == 2){
						SendMSG(user, CHAT_TYPE_SYSTEM, "Two players are already using your IP in this game.", false, 0xFFFFFFFF);
						return;
					}
				}

				PvPPlayer* player = new PvPPlayer();
				player->mIP = _strdup(ip);
				player->mTeam = team;
				player->mID = id;
				quest->mPlayers.PushBack(player);
				break;
			}else if(team == 3 || team == 4){
				RemoveUserFromQuest(quest, user);
				break;
			}
		}
	}

	user->Recv_cli_QUEST_REQ((t_PACKET*)pak);
}

bool __stdcall HandlePacket(t_PACKET* packet, classUSER* user){	
	CPacket* pak = (CPacket*)packet;
	switch(pak->Command()){
		case PAK_PARTYLIST:
			ProcPartyPacket(pak, user);
			return true;
		case PAK_DUEL:
			ProcDuelPacket(pak, user);
			return true;
		case PAK_ALLYCHAT:
			ProcAllyPacket(pak, user);
			return true;
		case 0x730:
			ProcQuestPacket(pak, user);
			return true;
	};

	return false;
}

void __declspec(naked) packetHook(){
	static int packJumpError = 0x1008F545;
	static int packJumpOver = 0x1008F599;

	__asm {
		MOV ECX,DWORD PTR SS:[EBP+0x8]
		MOVSX EDX,WORD PTR DS:[ECX]
		PUSHAD
		MOV EDX,DWORD PTR SS:[EBP+0x8]
		MOV ECX,DWORD PTR SS:[EBP-0x4]
		PUSH ECX
		PUSH EDX
		CALL HandlePacket
		CMP AL, 1
		JE LblOver
		POPAD
		JMP packJumpError
LblOver:
		POPAD
		MOV EAX, 1
		JMP packJumpOver
	}
}

HookOnLoad(0x1008F53F, packetHook, 1);

bool _stdcall CanMove(CPacket* pak, classUSER* user){
	classUSER* enemy = GetDuelEnemy(user);
	if(!enemy) return true;

	CVec2 pos, pos2;
	CustomAvatarData* data = CustomAvatarData::Get(user);

	pos = pak->Get<CVec2>(2);
	pos2.x = data->pDuel.mCenterX;
	pos2.y = data->pDuel.mCenterY;

	if(Distance(pos, pos2) < 1400.0f) return true;

	SendMSG(user, CHAT_TYPE_SYSTEM, "You cannot move outside the Duel area.", false, 0xFFFFFFFF);
	return false;
}

void __declspec(naked) ASMMovePlayer(){
	static int jmpOver = 0x1007A1DD;
	static int jNormal = 0x1007A148;

	__asm {
		PUSHAD

		MOV EAX,DWORD PTR SS:[EBP-0x4]
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP+0x8]
		PUSH ECX
		CALL CanMove
		TEST AL, AL

		POPAD

		JE jOVER

		MOV ECX,DWORD PTR SS:[EBP+0x8]
		FLD DWORD PTR DS:[ECX+0xC]

		JMP jNormal
jOVER:
		MOV AL, 1
		JMP jmpOver
	}
}

HookOnLoad(0x1007A142, ASMMovePlayer, 1);
