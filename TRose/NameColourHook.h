#ifndef NAMECOLOUR_H
#define NAMECOLOUR_H

#include "CodeHook.h"

class CGameOBJ;

typedef int (__stdcall *PF_GETNAMECOLOUR)(CGameOBJ* player, int curColour);

static _declspec(naked) void ASMGetOtherNameColourForward(){
	static const char* retAddr = reinterpret_cast<char*>(0x00487D94);
	_asm {
		MOV EDX, DWORD PTR SS:[ESP+0x10]
		PUSH EDX
		PUSH ESI
		CALL EAX
		MOV DWORD PTR SS:[ESP+0x10], EAX
		JMP retAddr
	};
}

static _declspec(naked) void ASMGetSelfNameColourForward(){
	static const char* retAddr = reinterpret_cast<char*>(0x004881B2);
	_asm {
		PUSH ECX
		MOV ECX, DWORD PTR DS:[0x6936A8]
		PUSH ECX
		CALL EAX
		PUSH 1
		PUSH EAX
		MOV EAX, DWORD PTR DS:[0x693504]
		LEA EDX, DWORD PTR SS:[ESP+0x38]
		JMP retAddr
	};
}

class NameColourHook {
public:
	static void Apply(PF_GETNAMECOLOUR targetFunc){
		CodeHook::NOP((unsigned char*)0x00487D59, 5);
		CodeHook::ApplyJmpForwardHook((unsigned char*)0x00487D5E, (unsigned char*)&ASMGetOtherNameColourForward, (unsigned char*)targetFunc, 0);
		CodeHook::ApplyJmpForwardHook((unsigned char*)0x004881A6, (unsigned char*)&ASMGetSelfNameColourForward, (unsigned char*)targetFunc, 2);
	}
};

#endif
