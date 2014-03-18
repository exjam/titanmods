#include "main.h"
#include "..\Shared\RunOnLoad.hpp"
#include <SHO_GS\classPACKET.h>
#include <SHO_GS\CPacket.h>
#include <SHO_GS\CZoneTHREAD.h>

void SendMSG(classUSER* user, int type, const char* text, bool zone, unsigned int colour){
	classPACKET* cpak = Packet_AllocNLock();
	if(!cpak) return;

	CPacket* pak = (CPacket*)cpak;
	pak->CreateNew(PAK_MESSAGE);
	pak->Add<unsigned char>(type);
	pak->AddString(text);
	pak->Add<unsigned int>(colour);
	pak->Add<unsigned short>(user->Get_INDEX());
	if(!zone)
		user->SendPacket(cpak);
	else if(CZoneTHREAD* zone = user->GetZONE())
		zone->SendShout(user, cpak, 0);

	Packet_ReleaseNUnlock(cpak);
}
