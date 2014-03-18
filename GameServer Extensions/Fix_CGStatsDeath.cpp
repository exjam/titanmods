#include "main.h"

static _declspec(naked) void ASMStatCalc(){
	static int UpdateAbility = 0x10009BE0;
	static int jret = 0x1008CA59;
	_asm {
		PUSHAD
		MOV ECX,DWORD PTR SS:[EBP-0x4]	// classUSER
		ADD ECX, 0xA0
		CALL UpdateAbility
		POPAD
		PUSH EDX
		MOV ECX,EBP
		PUSH EAX
		LEA EDX,DWORD PTR DS:[0x1008CA72]		
		JMP jret
	}
}

static _declspec(naked) void ASMStatCalcResurrect(){
	static int UpdateAbility = 0x10009BE0;
	static int jret = 0x1006E43F;
	_asm {
		MOV ECX,DWORD PTR SS:[EBP-0x4]	// CObjAVT
		CALL UpdateAbility
		POP ESI
		ADD ESP, 0x8
		CMP EBP,ESP
		JMP jret
	}
}

HookOnLoad(0x1006E439, ASMStatCalcResurrect, 1);
HookOnLoad(0x1008CA4F, ASMStatCalc, 5);
