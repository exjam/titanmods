#ifndef BUFFTOOLTIPHOOK_H
#define BUFFTOOLTIPHOOK_H

class Tooltip;

#include "CodeHook.h"
#include "Tooltip.h"

typedef void (__stdcall *PF_BTTHOOK)(Tooltip* tooltip, int buffRemainTime);

class BuffTimeHolder {
public:
	static int mRemainTime;
};

static _declspec(naked) void ASMSBTTHookForward(){
	static char* call1 = (char*)0x00484DC0;
	static char* retAddr = (char*)0x00481238;

	_asm {
		MOV EDX, BuffTimeHolder::mRemainTime
		LEA ECX, DWORD PTR SS:[ESP+0x54]
		PUSH EDX
		PUSH ECX
		CALL EAX
		MOV ESI, DWORD PTR SS:[ESP+0x3C]
		LEA ECX, DWORD PTR SS:[ESP+0x54]
		CALL call1
		JMP retAddr
	}
}

static _declspec(naked) void ASMSaveRemainTime(){
	static char* retAddr = (char*)0x00481186;
	_asm {
		MOV BuffTimeHolder::mRemainTime, ECX
		CMP ECX, 0x2710
		JMP retAddr
	}
}

class BuffTooltipHook {
public:
	static void Apply(PF_BTTHOOK targetFunc){
		CodeHook::ApplyJmpHook((unsigned char*)0x00481180, (unsigned char*)&ASMSaveRemainTime, 1);
		CodeHook::ApplyJmpForwardHook((unsigned char*)0x0048122B, (unsigned char*)&ASMSBTTHookForward, (unsigned char*)targetFunc, 3);
	}

private:
};

#endif

