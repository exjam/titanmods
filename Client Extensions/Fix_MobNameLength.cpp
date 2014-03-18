#include "main.h"

void __declspec(naked) ASMFixMobName(){
	static int jmpRet = 0x00487A2F;
	_asm {
		MOV ECX,ESI
		MOV DWORD PTR SS:[ESP+0x1C],-50
		MOV DWORD PTR SS:[ESP+0x20],-0x12
		MOV DWORD PTR SS:[ESP+0x24],150
		MOV DWORD PTR SS:[ESP+0x28],0
		JMP jmpRet
	}
}

HookOnLoad(0x00487A15, ASMFixMobName, 1);