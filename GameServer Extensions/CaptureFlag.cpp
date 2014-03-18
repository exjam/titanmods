#include "main.h"
#include "pvp.h"

#include <SHO_GS\classUSER.h>
#include <SHO_GS\classPACKET.h>
#include <SHO_GS\CPacket.h>
#include <SHO_GS\CZoneTHREAD.h>
#include <SHO_GS\CZoneLIST.h>
#include <SHO_GS\CObjEVENT.h>

// To ZONE (on data change)
void _stdcall SendFlagData(CGameOBJ* evt){
	if(!evt) return;
	CZoneTHREAD* zone = evt->GetZONE();
	if(!zone) return;

	int zoneid = zone->Get_ZoneNO();
	CObjEVENT* red  = g_pZoneLIST->Get_EventOBJ(zoneid, StrToHashKey(String("%1@34x33_1").arg(zoneid)));
	CObjEVENT* blue = g_pZoneLIST->Get_EventOBJ(zoneid, StrToHashKey(String("%1@32x31_2").arg(zoneid)));
	if(!red || !blue) return;

	classPACKET* cpak = Packet_AllocNLock();
	if(!cpak) return;

	CPacket* pak = (CPacket*)cpak;
	pak->CreateNew(PAK_FLAGSTATUS);
	pak->Add<short>(red->Get_ObjVAR(0));
	pak->Add<short>(blue->Get_ObjVAR(0));
	zone->SendPacketToZONE((t_PACKET*)cpak);
	Packet_ReleaseNUnlock(cpak);
}

// To PLAYER (on join zone)
void SendFlagDataToPlayer(classUSER* user, int zone){
	CObjEVENT* red  = g_pZoneLIST->Get_EventOBJ(zone, StrToHashKey(String("%1@34x33_1").arg(zone)));
	CObjEVENT* blue = g_pZoneLIST->Get_EventOBJ(zone, StrToHashKey(String("%1@32x31_2").arg(zone)));
	if(!red || !blue) return;

	classPACKET* cpak = Packet_AllocNLock();
	if(!cpak) return;

	CPacket* pak = (CPacket*)cpak;
	pak->CreateNew(PAK_FLAGSTATUS);
	pak->Add<short>(red->Get_ObjVAR(0)); //red
	pak->Add<short>(blue->Get_ObjVAR(0)); //blue
	user->SendPacket(cpak);
	Packet_ReleaseNUnlock(cpak);
}

void _declspec(naked) ASMUpdateEventVar() {
	static int jRet = 0x1001699D;
	static int cSendStatus = 0x100ABFA0;
	_asm {
		MOV ECX,DWORD PTR SS:[EBP-0x4]
		CALL cSendStatus
		MOV ECX,DWORD PTR SS:[EBP-0x4]
		ADD ECX, 0x38
		PUSH ECX
		CALL SendFlagData
		JMP jRet
	};
}

HookOnLoad(0x10016985, ASMUpdateEventVar, 0);
