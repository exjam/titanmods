#include "main.h"

short gSkillID = 0;

void __declspec(naked) ASMSummonMaxHP(){
	static int jmpRet = 0x004DE031;
	_asm {
		MOV gSkillID, CX
		MOV ECX, ESI
		MOV DWORD PTR DS:[ESI+0x5C], EAX
		JMP jmpRet
	}
}

void __declspec(naked) ASMCheckLastSkill(){
	static int jmpRet = 0x004FA4DB;
	_asm {
		MOV AX, gSkillID
		TEST AX, AX
		MOV gSkillID, 0
		JMP jmpRet
	}
}

HookOnLoad(0x004DE02C, ASMSummonMaxHP, 0);
HookOnLoad(0x004FA4D4, ASMCheckLastSkill, 2);