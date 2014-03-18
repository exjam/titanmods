#ifndef SENDPACKETHOOK_H
#define SENDPACKETHOOK_H

#include "CodeHook.h"

typedef bool (__stdcall *PF_ONSENDPACKETFUNC)(class Packet* pak);

static _declspec(naked) void ASMOnSendPacketForward(){
	static const char* PacketEncryption = reinterpret_cast<char*>(0x00405020);
	_asm{
		MOV EDX, EAX
			POP EAX
			PUSH EAX
			PUSH ECX
			PUSH ESI
			CALL EDX
			POP ECX
			CALL PacketEncryption
			POP ESI
			RETN 0x04
	}
}

class SendPacketHook {
public:
	static void Apply(PF_ONSENDPACKETFUNC targetFunc){
		CodeHook::ApplyJmpForwardHook((unsigned char*)0x00402D5E, (unsigned char*)&ASMOnSendPacketForward, (unsigned char*)targetFunc, 0);
	}
};

#endif
