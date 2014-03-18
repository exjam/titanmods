#ifndef SENDPACKET_H
#define SENDPACKET_H

#include <Shared/Templates.hpp>

class Packet;

#include "tagHotICON.h"

class SendPacket {
public:
	void Send(Packet* pSendPacket, bool sendToWorld = false){  
		return CallMemberFunction<SendPacket, void, Packet*, bool>(0x004EFBB0, this, pSendPacket, sendToWorld);  
	}
	void DoTrigger(unsigned char type, unsigned char questSlot, int questID, char* trigger){  
		return CallMemberFunction<SendPacket, void, unsigned char, unsigned char, int, char*>(0x004FC1E0, this, type, questSlot, questID, trigger);  
	}
	void SendLocal(char* message){  
		return CallMemberFunction<SendPacket, void, char*>(0x004FB9B0, this, message);  
	}
	void SendShout(char* message){  
		return CallMemberFunction<SendPacket, void, char*>(0x004FBB10, this, message);  
	}
	void SendSetHotIcon(unsigned char idx, tagHotICON HotICON){  
		return CallMemberFunction<SendPacket, void, unsigned char, tagHotICON>(0x004FBEA0, this, idx, HotICON);  
	}

	static SendPacket* Instance(){
		return reinterpret_cast<SendPacket*>((*reinterpret_cast<unsigned char**>(0x699920))+0x3C);
	}
};

/*	FixMemberFuncAddress(0x004EFBB0, &SendPacket::Send);
	FixMemberFuncAddress(0x004FC1E0, &SendPacket::DoTrigger);
	FixMemberFuncAddress(0x004FB9B0, &SendPacket::SendLocal);
	FixMemberFuncAddress(0x004FBB10, &SendPacket::SendShout);
	FixMemberFuncAddress(0x004FBEA0, &SendPacket::SendSetHotIcon);
*/

#endif
