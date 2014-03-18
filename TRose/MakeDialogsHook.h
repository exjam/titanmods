#ifndef MAKEDIALOGHOOk_H
#define MAKEDIALOGHOOk_H

#include "CodeHook.h"

typedef void (__stdcall *PF_MAKEDIALOGS)();
static void _declspec(naked) ASMMakeDialogForward(){
	static const char* retAdrr = (char*)0x00490065;
	static const char* call1 = (char*)0x00500B32;
	_asm {
		PUSH ECX
		PUSH EDX
		CALL EAX
		POP EDX
		POP ECX
		PUSH 0x130
		MOV ESI, ECX
		CALL call1
		JMP retAdrr
	}
}

class MakeDialogHook {
public:
	static void Apply(PF_MAKEDIALOGS targetFunc){
		CodeHook::ApplyJmpForwardHook((unsigned char*)0x00490059, (unsigned char*)&ASMMakeDialogForward, (unsigned char*)targetFunc, 2);
	}
};

#endif
