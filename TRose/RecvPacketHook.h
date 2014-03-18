#ifndef RECVPACKETHOOK_H
#define RECVPACKETHOOK_H

#include "CodeHook.h"

class Packet;

typedef bool (__stdcall *PF_ONRECVPACKETFUNC)(Packet* pak);

static _declspec(naked) void ASMOnRecvPacketForward(){
	_asm{
		PUSH DWORD PTR SS:[ESP+0x08]
		CALL EAX
		POP EDI
		RETN 0x04
	}
}

class RecvPacketHook {
public:
	static void Apply(PF_ONRECVPACKETFUNC targetFunc){
		CodeHook::ApplyJmpForwardHook((unsigned char*)(0x00402D8E), (unsigned char*)&ASMOnRecvPacketForward, (unsigned char*)targetFunc, 0);
	}
};

#endif
