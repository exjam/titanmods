#include "main.h"
#include "pvp.h"
#include "CrashChecker.h"

#include "..\Shared\RunOnLoad.hpp"
#include <SHO_GS\classUSER.h>
#include <SHO_GS\CZoneTHREAD.h>
#include <SHO_GS\CZoneLIST.h>
#include <SHO_GS\CPacket.h>
#include <SHO_GS\classPacket.h>
#include <SHO_GS\CUserLIST.h>
#include <SHO_GS\GS_CThreadLOG.h>
#include <SHO_GS\CLIB_GameSRV.h>

char* m_szDelimiters = " ,\t\n";
char* m_szEndDelimiters = "\t\n";

void _stdcall ParseCommand(classUSER* user, char* msg){
	if(!msg) return;
	if(msg[0] != '/') return;
	if(strlen(msg) < 2) return;

	char* arguments[20];
	char buffer[255];
	int argcount = 1;
	
	memset(arguments, 0, sizeof(char*) * 20);
	strcpy_s(buffer, 255, msg);
	arguments[0] = buffer + 1;

	for(char* pch = strchr(buffer, ' '); pch; pch = strchr(pch, ' ')){
		*pch = 0;
		if(pch[1] == 0) break;
		if(pch[1] == ' '){ ++pch; continue; }

		++pch;
		arguments[argcount] = pch;
		++argcount;
	}

	int isGM = user->C_Cheater();
	int isFullGM = user->B_Cheater();

	if(!isGM) return;

	if(!_strcmpi(arguments[0], "scale")){
		if(!arguments[1] || !arguments[2]) return;

		float scale = (float)atof(arguments[2]);
		if(scale < 0.01f || scale > 5.0f) return;

		classUSER* target = g_pUserLIST->Find_CHAR(arguments[1]);
		if(!target) target = user;

		CustomAvatarData* data = CustomAvatarData::Get(target);
		data->mData.mScale = scale;
		SendPlayerToZone(target);

		return;
	}else if(!_strcmpi(arguments[0], "set")){
		if(!arguments[1] || !arguments[2]) return;
		
		classUSER* target = g_pUserLIST->Find_CHAR(arguments[2]);
		if(!_strcmpi(arguments[1], "hair") && arguments[3]){
			target->m_sHairIDX.m_nItemNo = atoi(arguments[3]);
		}else if(!_strcmpi(arguments[1], "face") && arguments[3]){
			target->m_sFaceIDX.m_nItemNo = atoi(arguments[3]);
		}else if(!_strcmpi(arguments[1], "sex") && arguments[3]){
			target->SetCur_SEX(atoi(arguments[3]));
		}else if(!_strcmpi(arguments[1], "exp" ) && arguments[3]){
			target->SetCur_EXP(atoi(arguments[3]));
		}else if(!_strcmpi(arguments[1], "union") && arguments[3]){
			target->SetCur_UNION(atoi(arguments[3]));
		}else if(!_strcmpi(arguments[1], "stats")){
			target->Reward_InitSTATUS();
			target->AddCur_BonusPOINT(10);
		}else if(!_strcmpi(arguments[1], "godlike")){
			target->Set_AbilityValueNSend(10, 1000);
			target->Set_AbilityValueNSend(11, 1000);
			target->Set_AbilityValueNSend(12, 1000);
			target->Set_AbilityValueNSend(13, 1000);
			target->Set_AbilityValueNSend(14, 1000);
			target->Set_AbilityValueNSend(15, 1000);
			target->Cal_BattleAbility();
			target->Update_SPEED();
			target->UpdateAbility();
		}else if(!_strcmpi(arguments[1], "resetskills")){
			target->Reward_InitSKILL();
		}else if(!_strcmpi(arguments[1], "skill") && arguments[3]){
			int skill = atoi(arguments[3]);
			short idx = target->Skill_FindEmptySlot(atoi(arguments[3]));
			if(idx >= 0)
				target->Skill_LEARN(idx, skill, 0);

			target->Cal_BattleAbility();
			target->Update_SPEED();
		}

		return;
	}else if(!_strcmpi(arguments[0], "/achievement")){
		if(!arguments[1] || !arguments[2] || !arguments[3]) return;

		classUSER* target = g_pUserLIST->Find_CHAR(arguments[2]);
		if(!target) return;

		CustomAvatarData* data = CustomAvatarData::Get(target);
		if(!_strcmpi(arguments[1], "add" ))
			data->mAchievements.SetAchievement(atoi(arguments[3]), true);
		else if(!_strcmpi(arguments[1], "del"))
			data->mAchievements.SetAchievement(atoi(arguments[3]), false);

		return;
	}

	if(!isFullGM) return;

	if(!_strcmpi(arguments[0], "/saveall")){
		g_pUserLIST->Save_AllUSER();
	}else if(!_strcmpi(arguments[0], "/saveandblock")){
		g_pServer->Send_ANNOUNCE(0, "Server Maintenance");
		DoExit();
	}else if(!_strcmpi(arguments[0], "/addfilter")){
		if(!arguments[1]) return;

		gFilter.PushBack(_strdup(arguments[1]));
		String str = String("Added chat filter '%1'.").arg(arguments[1]);
		user->Send_gsv_WHISPER("SERVER", str);
		Log(MSG_INFO, str);
	}else if(!_strcmpi(arguments[0], "/clearfilter")){
		for(unsigned int i = 0; i < gFilter.Size(); ++i)
			delete [] gFilter[i];

		gFilter.Clear();
	}
}

void __declspec(naked) ASMHookCommand(){
	static int jmpRet = 0x1008E57B;
	static int call1 = 0x1008D6E0;
	__asm {
		PUSH ECX

		MOV ECX,DWORD PTR SS:[EBP+0x8]
		PUSH ECX
		MOV ECX,DWORD PTR SS:[EBP-0x4]
		PUSH ECX
		CALL ParseCommand

		POP ECX

		MOV ECX,DWORD PTR SS:[EBP+0x8]
		PUSH ECX
		MOV ECX,DWORD PTR SS:[EBP-0x4]
		CALL call1

		JMP jmpRet
	}
}

HookOnLoad(0x1008E56F, ASMHookCommand, 7);
