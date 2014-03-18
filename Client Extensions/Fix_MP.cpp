#include "main.h"

int gCurrent = 0;
int gAdd = 0;
int gPercentage = 0;

void __stdcall SaveVars(int percentage, int add, int current){
	gCurrent = current;
	gAdd = add;
	gPercentage = percentage;
}

void _declspec(naked) ASMSaveVars(){
	static int retAddr = 0x004DC189;
	_asm {
		PUSHAD
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ECX+0x58]
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ECX+0x5C]
		PUSH EAX
		CALL SaveVars
		POPAD

		MOV EDX,DWORD PTR SS:[ESP+0x18]
		ADD EDX,0x12C
		JMP retAddr
	}
}

unsigned int __stdcall RegenMP(){
	return gAdd + (gCurrent * gPercentage) / 100;
}

void _declspec(naked) ASMRegenMP(){
	static int retAddr = 0x00466814;
	_asm {
		PUSH ESI
		CALL RegenMP
		POP ESI
		MOV EDX,DWORD PTR DS:[ESI]
		PUSH EAX
		MOV ECX,ESI
		JMP retAddr
	}
}

void _stdcall FixMP(){
	Code::JmpHook(0x004DC17F, &ASMSaveVars, 5);			// Bonfire
	Code::JmpHook(0x0046680F, &ASMRegenMP, 0);			// Bonfire
	Code::Write<unsigned short>(0x00466D32, 0x4CEB);	// Useitem
	Code::Write<unsigned short>(0x00466D49, 0x35EB);	// Useitem
}

RunOnLoad(FixMP)