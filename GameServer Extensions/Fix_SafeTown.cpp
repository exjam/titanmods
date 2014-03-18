#include "main.h"
#include "..\Shared\Code.hpp"
#include "..\Shared\RunOnLoad.hpp"
#include <SHO_GS\CZoneFILE.h>
#include <SHO_GS\CZoneTHREAD.h>

bool _stdcall IsValidSafeTown(CZoneTHREAD* zone){
	int zoneid = zone->Get_ZoneNO();
	if(zoneid ==  1) return true;
	if(zoneid ==  2) return true;
	if(zoneid == 22) return true;
	if(zoneid == 24) return true;
	if(zoneid == 51) return true;
	if(zoneid == 61) return true;

	return false;
}

static _declspec(naked) void ASMFixRevivePosHax(){
	static int jgood = 0x10079AF4;
	static int jbad = 0x10079B43;

	_asm {
		PUSHAD
		PUSH EAX
		CALL IsValidSafeTown
		TEST AL, AL
		JE bad
		POPAD
		MOV EDX,DWORD PTR SS:[EBP-0x4]
		MOV EAX,DWORD PTR SS:[EBP-0x4]
		JMP jgood
bad: 
		POPAD
		JMP jbad
	}
}

HookOnLoad(0x10079AEF, ASMFixRevivePosHax, 1);
