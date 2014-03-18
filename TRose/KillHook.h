#ifndef KILLHOOK_H
#define KILLHOOK_H

#include "CodeHook.h"

class CGameOBJ;
typedef void (__stdcall *PF_ONKILLFUNC)(CGameOBJ* murderer, CGameOBJ* victim);

static _declspec(naked) void ASMOnKillForward(){
	static const char* OnKillJNZ = reinterpret_cast<char*>(0x0046C502);
	static const char* OnKillJMP = reinterpret_cast<char*>(0x0046C4A2);
	_asm {
		PUSH ESI
		PUSH EDI
		CALL EAX
		MOV EAX, DWORD PTR DS:[0x6936A8]
		MOV AX, WORD PTR DS:[EAX+0x18]
		CMP AX, WORD PTR DS:[EDI+0x18]
		JNZ gogoJNZ
		JMP OnKillJMP
gogoJNZ:
		JMP OnKillJNZ
	}
}

class KillHook {
public:
	static void Apply(PF_ONKILLFUNC targetFunc){
		CodeHook::ApplyJmpForwardHook(reinterpret_cast<unsigned char*>(0x0046C498), (unsigned char*)&ASMOnKillForward, reinterpret_cast<unsigned char*>(targetFunc), 0);
	}
};

#endif
