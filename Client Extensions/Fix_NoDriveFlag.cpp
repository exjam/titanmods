#include "main.h"
#include <TRose/STB.h>
#include <TRose/IT_MGR.h>

bool _stdcall NoDriveFlagCheck(){
	STBVALUE** tableZone = STB::GetZoneSTB();
	if(tableZone[CTERRAIN::Instance()->m_nZoneNO][30].mIntVal == 0)	return true;
	
	IT_MGR::Instance()->AppendChatMsg("You cannot use the drive skill in this zone!", CHAT_TYPE_SYSTEM);

	return false;
}

void _declspec(naked) ASMNoDriveFlagCheck(){
	static int jFailRET = 0x0043F7DE;
	static int jSucRET = 0x0043F5A4;
	_asm {
		CALL NoDriveFlagCheck
		TEST AL, AL
		JE omgFAil
		MOV ECX, DWORD PTR DS:[0x699920]
		JMP jSucRET
omgFail:
		JMP jFailRET
	};
}

HookOnLoad(0x0043F59E, ASMNoDriveFlagCheck, 1);