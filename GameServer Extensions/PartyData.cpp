#include "main.h"
#include "CustomPartyData.h"
#include "..\Shared\Console.hpp"
#include "..\Shared\RunOnLoad.hpp"
#include <SHO_GS/CParty.h>
#include <SHO_GS\classPACKET.h>
#include <SHO_GS\CPacket.h>

CustomPartyData gCustomPartyData[0x2000]; // party buffer = 0x2000

int IDXByParty(CParty* pParty) {
	int idx = int(((char*)pParty) - *((char**)(((char*)g_pPartyBUFF) + 0x30))) / 0x5C;
	if (idx > 0x2000) { return 0; }
	return idx;
}

void __stdcall OnCreateParty(CParty* party){
	gCustomPartyData[IDXByParty(party)].InitParty();
}

void __stdcall OnDeleteParty(CParty* party){
	gCustomPartyData[IDXByParty(party)].EndParty();
}

void __declspec(naked) ASMOnCreateParty(){
	static int retAddr = 0x100AD30F;
	_asm {
		PUSH EAX
		PUSH ECX

		PUSH ECX
		CALL OnCreateParty

		POP ECX
		POP EAX
		MOV DWORD PTR DS:[EAX + 0x2A18], ECX
		JMP retAddr
	}
}

void __declspec(naked) ASMOnDeleteParty(){
	static int retAddr = 0x100ADDF3;
	_asm {
		PUSH EAX
		PUSH EAX
		CALL OnDeleteParty
		POP EAX
		MOVZX ECX, WORD PTR DS:[EAX+0x26]
		MOV EDX, DWORD PTR SS:[EBP-0x4]
		JMP retAddr
	}
}

void __declspec(naked) ASMParty_GetAvgLevel() {
	static int RetJmp = 0x10010E34;
	_asm {
		MOV EAX,DWORD PTR SS:[EBP-0x4]
		PUSH EAX
		CALL Party_GetAvgLevel
		JMP RetJmp
	}
}

HookOnLoad(0x10010E2E, ASMParty_GetAvgLevel, 1);
HookOnLoad(0x100AD309, ASMOnCreateParty, 1);
HookOnLoad(0x100ADDEC, ASMOnDeleteParty, 2);

