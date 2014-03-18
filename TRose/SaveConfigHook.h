#ifndef SAVECONFIG_H
#define SAVECONFIG_H

#include "CodeHook.h"

typedef void (__stdcall *PF_ONSAVECONFIGFUNC)();

static _declspec(naked) void ASMOnSaveConfigForward(){
	static const char* retAddr = (char*)0x00407A2C;
	static const char* func1 = (char*)0x005018B0;
	_asm {
		CALL EAX
		MOV ECX, DWORD PTR SS:[ESP+0x20C]
		CALL func1
		JMP retAddr
	}
}

class SaveConfigHook {
public:
	static void Apply(PF_ONSAVECONFIGFUNC targetFunc){
		CodeHook::ApplyJmpForwardHook((unsigned char*)(0x00407A20), (unsigned char*)&ASMOnSaveConfigForward, (unsigned char*)targetFunc, 2);
	}
};

#endif
