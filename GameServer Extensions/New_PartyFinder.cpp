#include "main.h"
#include "Packets.h"
#include "CustomPartyData.h"
#include <SHO_GS/CParty.h>
#include <SHO_GS\classPACKET.h>
#include <SHO_GS\CPacket.h>
#include <SHO_GS\CZoneFILE.h>
#include <SHO_GS\CZoneTHREAD.h>

#define PAK_PARTY_ITEM 0x0
#define PAK_PARTY_MODE 0x1
#define PAK_PARTY_CLEAR 0x2

void GetPartyList(classUSER* user){
	CustomAvatarData* data = CustomAvatarData::Get(user);
	clock_t dt = clock() - data->mPartyListUpdate;
	if(dt < 10000) return;
	data->mPartyListUpdate = clock();

	classPACKET* cpak = Packet_AllocNLock();
	if(!cpak) return;

	CPacket* pak = (CPacket*)cpak;
	pak->CreateNew(PAK_PARTYLIST);
	pak->Add<byte>(PAK_PARTY_CLEAR);
	user->SendPacket(cpak);

	int parties = g_pPartyBUFF->m_iUsedSlot;
	int usrlevel = user->Get_LEVEL();

	for(int i = 0, found = 0; i < 0x2000, found < parties; ++i){
		CParty* party = g_pPartyBUFF->GetData(i);
		if(!party) continue;

		++found;
		if(gCustomPartyData[i].mPrivate == 1) continue;

		int average = party->GetAverageLEV();
		int partylv = party->GetPartyLEV();
		if(!user->Check_PartyJoinLEVEL(usrlevel, average, partylv)) continue;

		classUSER* owner = party->GetPartyOWNER();	
		if(!owner) continue;

		pak->CreateNew(PAK_PARTYLIST);
		pak->Add<unsigned char>(PAK_PARTY_ITEM);
		pak->Add<short>(	partylv);
		pak->Add<short>(	owner->m_nZoneNO);
		pak->Add<int>(average);
		pak->Add<int>(party->GetMemberCNT());
		pak->AddString(owner->Get_NAME());
		user->SendPacket(cpak);
	}

	Packet_ReleaseNUnlock(cpak);
}

void SetPartyMode(CPacket* pak, classUSER* user){
	unsigned char isPrivate = pak->Get<unsigned char>(1);

	CParty* party = user->GetPARTY();
	if(!party) return;

	int idx = IDXByParty(party);
	if(idx < 0 || idx > 0x2000 || !user->Quest_IsPartyLEADER()) return;

	gCustomPartyData[idx].mPrivate = isPrivate;

	classPACKET* cpak = Packet_AllocNLock();
	if(!cpak) return;

	CPacket* npak = (CPacket*)cpak;
	npak->CreateNew(PAK_PARTYLIST);
	npak->Add<unsigned char>(PAK_PARTY_MODE);
	npak->Add<unsigned char>(isPrivate);
	party->SendToPartyMembers(cpak);
	Packet_ReleaseNUnlock(cpak);
}

void ProcPartyPacket(CPacket* pak, classUSER* user){
	unsigned char cmd = pak->Get<unsigned char>(0);
	if(cmd == PAK_PARTY_ITEM)
		GetPartyList(user);
	else if (cmd == PAK_PARTY_MODE)
		SetPartyMode(pak, user);
}

void __stdcall Party_GetCurrentMODE(classUSER* user){
	CParty* party = user->GetPARTY();
	if(!party) return;

	int idx = IDXByParty(party);
	if(idx < 0 || idx > 0x2000) return;

	classPACKET* cpak = Packet_AllocNLock();
	if(!cpak) return;

	CPacket* pak = (CPacket*)cpak;
	pak->CreateNew(PAK_PARTYLIST);
	pak->Add<unsigned char>(PAK_PARTY_MODE);
	pak->Add<unsigned char>(gCustomPartyData[idx].mPrivate);
	user->SendPacket(cpak);
	Packet_ReleaseNUnlock(cpak);
}

bool CanParty(int hi, int lo){
	int dl = hi - lo;

	if(hi <= 30 && dl <= 12)
		return true;
	else if(hi > 30 && dl <= 25)
		return true;

	return false;
}

int __stdcall Party_GetAvgLevel(CParty* party){
	int value = 0;
	int members = party->GetMemberCNT();

	for(int i = 0; i < members; ++i){
		if(!party->m_pPartyUSERs[i]) continue;

		classUSER* user = party->m_pPartyUSERs[i]->m_pUSER;
		if(!user) continue;

		value += user->Get_LEVEL();
	}

	return value / members;
}

void __declspec(naked) ASMParty_GetCurrentMODE() {
	static int RetJmp = 0x100AE33F;
	static int call1 = 0x10004100;
	_asm {
		MOV EAX,DWORD PTR SS:[EBP+0x8]
		PUSH EAX
		CALL Party_GetCurrentMODE
		CALL call1
		JMP RetJmp
	}
}

HookOnLoad(0x100AE33A, ASMParty_GetCurrentMODE, 0);
