#include "main.h"
#include <math.h>
#include "..\Shared\Code.hpp"
#include "..\Shared\RunOnLoad.hpp"
#include <SHO_GS\CGameObj.h>

float Distance(CVec2 p1, CVec2 p2) {
	return sqrt(pow((p1.x - p2.x),2) + pow((p1.y - p2.y),2));
}

bool _stdcall IsValidPickup(CGameOBJ* item, classUSER* user) {
	if(user->GetZONE() != item->GetZONE()){
		user->IsHacking("Cross-Map Pickup",__FILE__,__LINE__);
		return false;
	}

	if(Distance(user->m_PosCUR, item->m_PosCUR) > 2000.0f)
		return false;

	return true;
}

void _declspec(naked) ASMPickupFix(){ 
	static int PickUpFail = 0x1008C3DC;
	static int PickUpWin = 0x1008C290;
	_asm {
		MOV EAX, DWORD PTR SS:[EBP-0x4]		//classUSER
		PUSH EAX
		MOV ECX, DWORD PTR SS:[EBP-0xC]		//pITEM
		PUSH ECX
		CALL IsValidPickup
		TEST AL, AL
		JE megaFAIL
		MOV ECX, DWORD PTR SS:[EBP-0x4]	
		ADD ECX, 0xA0
		JMP PickUpWin
megaFAIL:
		JMP PickUpFail
	}
}

HookOnLoad(0x1008C287, ASMPickupFix, 4);
