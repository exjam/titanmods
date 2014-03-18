#include "main.h"
#include "pvp.h"

#include "..\Shared\RunOnLoad.hpp"

void __stdcall UserDisconnect(classUSER* pUser){
	if(classUSER* pEnemy = GetDuelEnemy(pUser))
		EndDuel(pEnemy, pUser, 2);

	CustomAvatarData* data = CustomAvatarData::Get(pUser);
	
	if(!data) return;
	delete data;
	*(int*)(((char*)pUser) + 0x2A40) = 0;
}

void __declspec(naked) ASMUserDisconnect(){
	static int retAddr = 0x100971D3;
	_asm {
		MOV EDX, DWORD PTR SS:[EBP - 0xC]
		MOV ECX, DWORD PTR DS:[EDX + 0x4]
		PUSH ECX
		CALL UserDisconnect
		MOV EDX, DWORD PTR SS:[EBP - 0xC]
		MOV ECX, DWORD PTR DS:[EDX + 0x4]
		JMP retAddr
	}
}

HookOnLoad(0x100971CD, ASMUserDisconnect, 1);