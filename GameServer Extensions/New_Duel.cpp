#include "main.h"
#include "PvP.h"
#include "Packets.h"
#include "SendMessage.h"

#include "..\Shared\RunOnLoad.hpp"
#include <SHO_GS\classPACKET.h>
#include <SHO_GS\CPacket.h>
#include <SHO_GS\CObjMNG.h>
#include <SHO_GS\CObjMOB.h>
#include <SHO_GS\CZoneTHREAD.h>
#include <SHO_GS\CLIB_GameSRV.h>
#include <SHO_GS\CZoneLIST.h>

enum {
	DUEL_REQ,
	DUEL_REPLY,
	DUEL_END,

	DUEL_DENY = 0,
	DUEL_ACCEPT = 1,
	DUEL_BUSY = 2,
};

classUSER* GetDuelEnemy(classUSER* player) {
	CustomAvatarData* data = CustomAvatarData::Get(player);
	if(!data->pDuel.mInDuel) return 0;

	CGameOBJ* obj = g_pObjMGR->Get_CharOBJ(data->pDuel.mRequestID, false);
	if(!obj) return 0;
	if(!obj->IsUSER()) return 0;

	CustomAvatarData* enemyData = CustomAvatarData::Get(obj);
	if(!enemyData->pDuel.mInDuel) return 0;

	classUSER* enemy = static_cast<classUSER*>(obj);
	return enemy;
}

bool AreDuelling(CGameOBJ* char1, CGameOBJ* char2){
	if(!char1 || !char2) return false;
	if(!char1->IsUSER() || !char2->IsUSER()) return false;

	CustomAvatarData* data1 = CustomAvatarData::Get(char1);
	CustomAvatarData* data2 = CustomAvatarData::Get(char2);
	if(!data1->pDuel.mInDuel || !data2->pDuel.mInDuel) return false;
	if(data1->pDuel.mRequestID != char2->Get_INDEX()) return false;
	if(data2->pDuel.mRequestID != char1->Get_INDEX()) return false;

	return true;
}


void EndDuel(classUSER* winner, classUSER* loser, int method){
	if(!winner || !loser) return;

	SendMSG(winner, CHAT_TYPE_WHISPER, String("You have defeated %1 in a duel.").arg(loser->Get_NAME()));
	SendMSG(loser, CHAT_TYPE_WHISPER, String("You have been defeated by %1 in a duel.").arg(winner->Get_NAME()));

	if(method == 0) // by Score
		SendMSG(winner, CHAT_TYPE_ALL, String("[Duel] %1 has defeated %2 in a duel!").arg(winner->Get_NAME()).arg(loser->Get_NAME()), true, 0xFFFFFF13);
	else if(method == 1) // by Zone Change
		SendMSG(winner, CHAT_TYPE_ALL, String("[Duel] %1 has defeated %2 in a duel! (forfeit)").arg(winner->Get_NAME()).arg(loser->Get_NAME()), true, 0xFFFFFF13);
	else if(method == 2) // by Logout
		SendMSG(winner, CHAT_TYPE_ALL, String("[Duel] %1 has defeated %2 in a duel! (disconnect)").arg(winner->Get_NAME()).arg(loser->Get_NAME()), true, 0xFFFFFF13);

	CustomAvatarData* wimData = CustomAvatarData::Get(winner);
	CustomAvatarData* loseData = CustomAvatarData::Get(loser);

	// Log to database
	LogDuel(method + 1, winner, loser, wimData->pDuel.mZulie * 2);

	// End duel (removes circle)
	classPACKET* cpak = Packet_AllocNLock();
	if(!cpak) return;

	CPacket* pak = (CPacket*)cpak;
	pak->CreateNew(PAK_DUEL);
	pak->Add<unsigned char>(DUEL_END);
	winner->SendPacket(cpak);
	loser->SendPacket(cpak);

	// Reward zulie
	if(wimData->pDuel.mZulie > 0){
		winner->Add_CurMONEY(wimData->pDuel.mZulie * 2);
		winner->Send_gsv_SET_MONEYONLY(0x71D);
	}

	// Restore pk settings
	if(CZoneTHREAD* zone = winner->GetZONE()){
		pak->CreateNew(0x70F);
		pak->Add<dword>(zone->GetGlobalFLAG());
		winner->SendPacket(cpak);
	}

	if(CZoneTHREAD* zone = loser->GetZONE()){
		pak->CreateNew(0x70F);
		pak->Add<dword>(zone->GetGlobalFLAG());
		loser->SendPacket(cpak);
	}

	Packet_ReleaseNUnlock(cpak);

	// Get surrounding characters and apply applause
	CVec2 pos2;
	pos2.x = wimData->pDuel.mCenterX;
	pos2.y = wimData->pDuel.mCenterY;

	if(CZoneTHREAD* zone = winner->GetZONE()){
		for(auto obj = zone->m_ObjLIST.m_pHEAD; obj; obj = obj->m_pNEXT){
			CGameOBJ* gameobj = obj->DATA;
			if(!gameobj) continue;
			if(!gameobj->IsUSER()) continue;
			if(gameobj == winner || gameobj == loser) continue;

			if(Distance(gameobj->m_PosCUR, pos2) < 2000.0f){
				classUSER* user = static_cast<classUSER*>(gameobj);
				if(user->Is_Stop())
					user->Send_gsv_SET_MOTION(0, 25);
			}
		}
	}

	// Reset duel data
	loseData->pDuel.Reset();
	wimData->pDuel.Reset();

	// Send update to both players to clear the DuelENEMY id
	SendPlayerDATA(winner, loser);
}


extern STBVALUE** g_TblZONE;

void ProcDuelPacket(CPacket* pak, classUSER* user){
	short zone = user->m_nZoneNO;
	if(zone < 1 || zone >= 70) return;
	if(zone != 6 && zone != 29 && g_TblZONE[zone][18].GetINT() != PVP_CANT) return;

	unsigned char cmd = pak->Get<unsigned char>(0);
	int requestid = pak->Get<int>(1);

	CGameOBJ* obj = g_pObjMGR->Get_CharOBJ(requestid, true);
	if(!obj) return;
	if(obj == user) return;
	if(!obj->IsUSER() || user->GetZONE() != obj->GetZONE()) return;

	classUSER* requester = static_cast<classUSER*>(obj);
	CustomAvatarData* reqData = CustomAvatarData::Get(requester);
	CustomAvatarData* sendData = CustomAvatarData::Get(user);

	if(sendData->pDuel.mInDuel || reqData->pDuel.mInDuel){
		classPACKET* cpak = Packet_AllocNLock();
		if(!cpak) return;

		CPacket* pak = (CPacket*)cpak;
		pak->CreateNew(PAK_DUEL);
		pak->Add<unsigned char>(DUEL_REPLY);
		pak->Add<unsigned char>(2);
		pak->AddString(requester->Get_NAME());
		user->SendPacket(cpak);
		Packet_ReleaseNUnlock(cpak);

		return;
	}

	if(cmd == DUEL_REQ){
		int zulie = pak->Get<int>(5);
		if(zulie < 0 || zulie > 1000000 || user->GetCur_MONEY() < zulie)
			return;

		short mode = pak->Get<short>(9);
		if(mode < 0 || mode > 2)
			mode = 0;

		sendData->pDuel.mRequestID = requestid;
		sendData->pDuel.mZulie = zulie;
		sendData->pDuel.mMode = mode;

		classUSER* pRecv = static_cast<classUSER*>(obj);
		classPACKET* cpak = Packet_AllocNLock();
		if(!cpak) return;

		CPacket* pak = (CPacket*)cpak;
		pak->CreateNew(PAK_DUEL);
		pak->Add<unsigned char>(DUEL_REQ);
		pak->Add<int>(user->Get_INDEX());
		pak->Add<int>(zulie);
		pak->AddString(user->Get_NAME());
		pak->Add<short>(mode);
		pRecv->SendPacket(cpak);
		Packet_ReleaseNUnlock(cpak);
	}else if (cmd == DUEL_REPLY){
		unsigned char reply = pak->Get<unsigned char>(5);
		if(reqData->pDuel.mRequestID != user->Get_INDEX()) return;

		//Send reply
		if(classPACKET* cpak = Packet_AllocNLock()){
			CPacket* pak = (CPacket*)cpak;
			pak->CreateNew(PAK_DUEL);
			pak->Add<unsigned char>(DUEL_REPLY);
			pak->Add<unsigned char>(reply);
			pak->AddString(user->Get_NAME());
			requester->SendPacket(cpak);
			Packet_ReleaseNUnlock(cpak);
		}

		//Didn't accept so cancel and quit
		if(reply != DUEL_ACCEPT){
			reqData->pDuel.Reset();
			return;
		}

		//Stop moving n stuff
		user->SetCMD_STOP();
		requester->SetCMD_STOP();

		//Too far, cancel & quit
		if(Distance(user->m_PosCUR, requester->m_PosCUR) > 1400.0f){
			SendMSG(user, CHAT_TYPE_WHISPER, "You are too far away to duel this character.", false, 0xFFFFFFFF);
			SendMSG(requester, CHAT_TYPE_WHISPER, "You are too far away to duel this character.", false, 0xFFFFFFFF);

			reqData->pDuel.Reset();
			return;
		}

		//Check zulie
		int zulie = reqData->pDuel.mZulie;
		if(zulie > 0){
			if(user->GetCur_MONEY() >= zulie && requester->GetCur_MONEY() >= zulie){
				user->Sub_CurMONEY(zulie);
				user->Send_gsv_SET_MONEYONLY(0x71D);
				requester->Sub_CurMONEY(zulie);
				requester->Send_gsv_SET_MONEYONLY(0x71D);
			}else{
				//Not enough zulie;
				reqData->pDuel.Reset();
				return;
			}
		}

		//Start duel
		LogDuel(0, user, requester, zulie);

		float x = (user->m_PosCUR.x +  requester->m_PosCUR.x) / 2.0f;
		float y = (user->m_PosCUR.y +  requester->m_PosCUR.y) / 2.0f;

		reqData->pDuel.mInDuel = true;
		reqData->pDuel.mRequestID = user->Get_INDEX();
		reqData->pDuel.mScore = 0;
		reqData->pDuel.mCenterX = x;
		reqData->pDuel.mCenterY = y;

		sendData->pDuel.mZulie = reqData->pDuel.mZulie;
		sendData->pDuel.mInDuel = true;
		sendData->pDuel.mRequestID = requester->Get_INDEX();
		sendData->pDuel.mScore = 0;
		sendData->pDuel.mMode = reqData->pDuel.mMode;
		sendData->pDuel.mCenterX = x;
		sendData->pDuel.mCenterY = y;

		if(classPACKET* cpak = Packet_AllocNLock()){
			CPacket* pak = (CPacket*)cpak;
			pak->CreateNew(PAK_DUEL);
			pak->Add<unsigned char>(DUEL_REPLY);
			pak->Add<unsigned char>(DUEL_ACCEPT);
			pak->AddString(requester->Get_NAME());
			user->SendPacket(cpak);

			pak->CreateNew(0x70F);
			pak->Add<unsigned int>(1);
			user->SendPacket(cpak);
			requester->SendPacket(cpak);
			Packet_ReleaseNUnlock(cpak);
		}

		SendPlayerDATA(user, requester);

		MotionValue pValue;
		pValue.m_wIsSTOP = 1;
		user->Send_gsv_SET_MOTION(pValue.m_wValue, 27);
		requester->Send_gsv_SET_MOTION(pValue.m_wValue, 27);
	}
}

bool _stdcall NotALLIED(CGameOBJ* obj, CGameOBJ* other){
	return AreDuelling(obj, other);
}

void __declspec(naked) ASMIsAllied(){
	static int  jNORM = 0x1006C931;
	static int  jOVER = 0x1006C95F;
	static int  cGetFLAG = 0x10011250;
	_asm {
		CALL cGetFLAG
		PUSH EAX						//x

		///////////////////////////////
		MOV ECX,DWORD PTR SS:[EBP-4]
		SUB ECX,0x34
		PUSH ECX // obj 2

		MOV ECX,DWORD PTR SS:[EBP+0x8]
		SUB ECX,0x34
		PUSH ECX // obj 1 CAI_OBJ

		CALL NotALLIED
		///////////////////////////////
		TEST AL, AL
		JE jNormal
	
		POP EAX							//-x
		MOV AL, 0
		JMP jOVER
jNormal:
		POP EAX							//-x
		JMP jNORM
	}
}

HookOnLoad(0x1006C92C, ASMIsAllied, 0);

dword _stdcall GetZoneFlagOnZone(CGameOBJ* obj, CZoneTHREAD* zone) {
	if(obj && obj->IsUSER()){
		CustomAvatarData* data = CustomAvatarData::Get(obj);
		if(data->pDuel.mInDuel)
			return 1;
	}

	return zone->GetGlobalFLAG();
}

void __declspec(naked) ASMGetFlagOnZoneChange(){
	static int  jRet = 0x10089896;
	_asm {
		PUSH ECX
		MOV ECX,DWORD PTR SS:[EBP-0x4]
		PUSH ECX
		CALL GetZoneFlagOnZone
		JMP jRet
	}
}

HookOnLoad(0x10089891, ASMGetFlagOnZoneChange, 0);

bool _stdcall CanDoPartySkill(CObjCHAR* caster, CObjCHAR* target){
	// Cast to self
	if(caster == target) 
		return true;

	// Cast on summons
	if(target->IsUSER() == false){
		if(CAI_OBJ* pAiObj = target->Get_CALLER()){
			// Cast on your own summon
			CObjCHAR* summoner = static_cast<CObjCHAR*>(pAiObj);
			if(summoner == caster)
				return true;
			
			// Cast on a summon in the party (-> while not in duel)
			if(caster->GetPARTY() && summoner->IsUSER()) {
				CustomAvatarData* data = CustomAvatarData::Get(summoner);
				if(data->pDuel.mInDuel == false && caster->GetPARTY() == summoner->GetPARTY())
					return true;
			}
		}
	}else{
		if(caster->GetPARTY() && caster->GetPARTY() == target->GetPARTY()){
			// Cast on USER in SAME PARTY as caster while NOT IN DUEL and PARTY isnot NULL
			CustomAvatarData* data = CustomAvatarData::Get(target);
			if(!data->pDuel.mInDuel)
				return true;
		}
	}

	return false;
}

void __declspec(naked) ASMBlockPartySkills(){
	static int  jRet = 0x100683D1;
	_asm {
		MOV EDX,DWORD PTR SS:[EBP+0x8]
		PUSH EDX
		MOV EDX,DWORD PTR SS:[EBP-0x4]
		PUSH EDX
		CALL CanDoPartySkill
		MOV BYTE PTR SS:[EBP-0x5],AL
		JMP jRet
	}
}

HookOnLoad(0x100680F5, ASMBlockPartySkills, 0);
