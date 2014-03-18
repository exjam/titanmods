#include "main.h"
#include "..\Shared\Code.hpp"
#include "..\Shared\RunOnLoad.hpp"

bool _stdcall CanShout(classUSER* user){
	if(user->C_Cheater())
		return true;

	CustomAvatarData* data = CustomAvatarData::Get(user);
	clock_t dt = clock() - data->mLastShout;
	if(dt < 30000) return false;

	data->mLastShout = clock();
	return true;
}

void _declspec(naked) ASMShoutFix(){ 
	static int Fail = 0x1008E79A;
	static int Win = 0x1008E714;
	_asm {
		MOV WORD PTR SS:[EBP-0x10],6

		MOV EAX, DWORD PTR DS:[ESP+0x20]		// Length
		MOVZX EAX, WORD PTR DS:[EAX]
		CMP EAX, 0x84
		JA megaFAIL

		PUSHAD
		MOV EAX,DWORD PTR SS:[EBP-0x4]			// Time
		PUSH EAX
		CALL CanShout
		TEST AL, AL
		POPAD

		JE megaFAIL
		JMP Win
megaFAIL:
		JMP Fail
	}
}

HookOnLoad(0x1008E70E, ASMShoutFix, 1);
