#include "main.h"
#include <SHO_GS\classUSER.h>
#include <SHO_GS\CClan.h>
#include <SHO_GS\classPACKET.h>
#include <SHO_GS\CPacket.h>
#include <SHO_GS\CThreadGUILD.h>
#include <SHO_GS\CZoneTHREAD.h>

void __stdcall AddAbility(int index, int value, CUserDATA* data){
	if(index != 92) return;

	classUSER* user = static_cast<classUSER*>(data);

	g_pThreadGUILD->m_CS.Lock();

	int points = user->GetClanCONTRIBUTE();
	user->SetClanCONTRIBUTE(points + value);

	char* name = user->Get_NAME();
	if(classPACKET* cpak = Packet_AllocNLock()){
		CPacket* pak = (CPacket*)cpak;
		pak->CreateNew(PAK_CONTRIBUTION);
		pak->Add<int>(value);
		pak->AddString(name);
		user->SendPacket(cpak);
		Packet_ReleaseNUnlock(cpak);
	}

	g_pThreadGUILD->Query_AdjustClanMember(name, value, 0); // Name, +Contribution, +Position
	g_pThreadGUILD->m_CS.Unlock();
}

void __declspec(naked)  ASMUpdateAbility() {
	static int retAddr = 0x1007156C;
	_asm {
		PUSH ECX						// data
		MOV ECX,DWORD PTR SS:[EBP+0xC]
		PUSH ECX						// value
		MOV DWORD PTR SS:[EBP-0x8], EAX
		PUSH EAX						// index
		CALL AddAbility
		MOV ECX, DWORD PTR SS:[EBP-0x8]
		JMP retAddr
	}
}

HookOnLoad(0x10071566, ASMUpdateAbility, 1);

void __stdcall FixClanLogCrash(){
	Code::NOP((unsigned char*)0x100A214D, 13);
	Code::NOP((unsigned char*)0x100A216B, 13);
	Code::NOP((unsigned char*)0x100A2129, 13);
	Code::NOP((unsigned char*)0x100A2189, 13);
}

RunOnLoad(FixClanLogCrash);
