#include "main.h"
#include "..\Shared\Code.hpp"
#include "..\Shared\RunOnLoad.hpp"

static _declspec(naked) void ASMSelfParty(){
	static int jother = 0x100D4BA9;
	static int jret = 0x100D4E7F;
	_asm {
		CMP EAX,DWORD PTR SS:[EBP-0x4]
		JNZ Other
		JMP jret
Other:
		JMP jother
	}
}

// Invite, Log off, Accept
static _declspec(naked) void ASMPartyCrash(){
	static int jfail = 0x1008B7C6;
	static int jret = 0x1008B5A1;
	_asm {
		CMP DWORD PTR SS:[EBP-0x8],0
		JE Failure
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x8]
		ADD ECX,0xD4
		JMP jret
	Failure:
		JMP jfail
	}
}

HookOnLoad(0x1008B471, ASMSelfParty, 0);
HookOnLoad(0x1008B597, ASMPartyCrash, 5);
