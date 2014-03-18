#include "main.h"
#include "..\Shared\Code.hpp"
#include "..\Shared\RunOnLoad.hpp"

void _stdcall doKillTrigger(classUSER* user, unsigned long hash){
	CustomAvatarData* data = CustomAvatarData::Get(user);

	data->cKilledTrigger = true;
	user->Do_QuestTRIGGER(hash, -1);
	data->cKilledTrigger = false;
}

void _stdcall doDeadTrigger(classUSER* user, unsigned long hash){
	CustomAvatarData* data = CustomAvatarData::Get(user);

	data->cDeadTrigger = true;
	user->Do_QuestTRIGGER(hash, -1);
	data->cDeadTrigger = false;
}

bool _stdcall OnGetSwitch(classUSER* user, int switchid) {
	CustomAvatarData* data = CustomAvatarData::Get(user);
	if(switchid == 10000 && data->cKilledTrigger == true)
		return true;
	else if(switchid == 10001 && data->cDeadTrigger == true)
		return true;

	return false;
}

static _declspec(naked) void ASMKillTrigger(){
	static int jret = 0x1008A252;
	_asm {
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x18]
		PUSH ECX
		CALL doKillTrigger
		JMP jret
	}
}

static _declspec(naked) void ASMDeadTrigger(){
	static int jret = 0x1008A285;
	_asm {
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x4]
		SUB ECX,0xA0   
		PUSH ECX
		CALL doDeadTrigger
		JMP jret
	}
}

static _declspec(naked) void ASMCheckQuestSwitch(){
	static int jJumpOver = 0x1009B09C;
	static int jCheckNormal = 0x1009B082;
	_asm {
		PUSHAD
		MOVSX EAX, WORD PTR DS:[ECX+0x8]
		PUSH EAX					//SwitchID
		MOV EAX,DWORD PTR SS:[EBP+0xC]
		MOV EAX,DWORD PTR DS:[EAX+0x8]
		PUSH EAX					//classUSER
		CALL OnGetSwitch
		TEST AL, AL	
		JE jCheck					// False -> Check normal switch
		POPAD
		MOV EAX, 1					// True
		JMP jJumpOver				// Return
jCheck:
		POPAD
		MOVSX EDX,WORD PTR DS:[ECX+0x8]
		PUSH EDX
		JMP jCheckNormal
	}
}

void _stdcall DoNopsLol() {
	// NOP "PUSH -1"
	Code::NOP((unsigned char*)0x1008A238, 2);
	Code::NOP((unsigned char*)0x1008A265, 2);
}

RunOnLoad(DoNopsLol)
HookOnLoad(0x1008A249, ASMKillTrigger, 4);
HookOnLoad(0x1008A276, ASMDeadTrigger, 10);
HookOnLoad(0x1009B07D, ASMCheckQuestSwitch, 0);
