#ifndef LOADCONFIG_H
#define LOADCONFIG_H

#include "CodeHook.h"

typedef void (__stdcall *PF_ONLOADCONFIGFUNC)();

static _declspec(naked) void ASMOnLoadConfigForward(){
	static const char* retAddr = (char*)0x00407E9C;
	static const char* func1 = (char*)0x005018B0;
	_asm {
		PUSH ECX
		CALL EAX
		POP ECX
		POP ESI
		POP EBX
		CALL func1
		ADD ESP, 0x44
		JMP retAddr
	}
}

class LoadConfigHook {
public:
	static void Apply(PF_ONLOADCONFIGFUNC targetFunc){
		CodeHook::ApplyJmpForwardHook((unsigned char*)(0x00407E92), (unsigned char*)&ASMOnLoadConfigForward, (unsigned char*)targetFunc, 2);
	}
};

#endif
