#include "main.h"
#include "PartyList.h"
#include "Network.h"
#include <TRose\StringManager.h>

void __stdcall PartyOptShow(CTDialog* dlgPartyOpt){
	if(CTCheckBox* checkBox = (CTCheckBox*)dlgPartyOpt->Find(41)){
		if(gPartyIsPrivate == 1)
			checkBox->SetCheck();
		else
			checkBox->SetUncheck();
	}
}

void __declspec(naked) ASMPartyOptShow(){
	static int jmpRet = 0x004C4F53;
	_asm {
		PUSHAD
		PUSH ECX
		CALL PartyOptShow
		POPAD
		CALL DWORD PTR DS:[0x62E6A0]
		JMP jmpRet
	}
}

HookOnLoad(0x004C4F4D, ASMPartyOptShow, 1);

void __stdcall PartyOptSubmit(CTDialog* dlgPartyOpt){
	if(CTCheckBox* checkBox = (CTCheckBox*)dlgPartyOpt->Find(41)){	
		Packet* pak = new Packet(PAK_PARTYLIST);
		pak->Add<byte>(PAK_PARTY_MODE);
		pak->Add<byte>(checkBox->IsCheck() ? PARTY_PRIVATE : PARTY_PUBLIC );
		SendPacket::Instance()->Send(pak);
		delete pak;
	}
}

void __declspec(naked) ASMPartyOptSubmit(){
	static int jmpRet = 0x004C4E5E;
	_asm {
		PUSHAD
		PUSH ECX
		CALL PartyOptSubmit
		POPAD
		MOV EDI,DWORD PTR DS:[0x62E6A0]
		JMP jmpRet
	}
}

HookOnLoad(0x004C4E58, ASMPartyOptSubmit, 1);

void __stdcall DrawPartyOpt(){
	drawFont(GameDATA->m_hFONT[FONT_NORMAL], true, 38, 211, 0xFF000000, "Private Party");
}

void __declspec(naked) ASMPartyOptDraw(){
	static int jmpOut = 0x004C542E;
	_asm {
		CALL ESI
		ADD ESP, 0x18
		CALL DrawPartyOpt
		JMP jmpOut
	}
}

HookOnLoad(0x004C5429, ASMPartyOptDraw, 0);