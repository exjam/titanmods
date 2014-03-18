#include "main.h"

void __declspec(naked) ASMDescription(){
	static int jmpRet = 0x0044021F;
	_asm {
		SHR ECX,5
		MOV EDX, DWORD PTR DS:[EDI+0x14]
		SUB EDX, 2
		PUSH EDX
		JMP jmpRet
	}
}

HookOnLoad(0x0044021A, ASMDescription, 0);