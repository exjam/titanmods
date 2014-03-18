#include "main.h"
#include <SHO_GS\classUSER.h>
#include <SHO_GS\classPACKET.h>
#include <SHO_GS\CPacket.h>

void _stdcall VendMessage(classUSER* buyer, classUSER* seller, tagITEM* item, __int64 zuly){
	unsigned short wType = item->GetTYPE();
	unsigned short wItemNO = item->GetItemNO();
	
	if(wType > 14 || wType < 1) 
		return;

	tagBaseITEM bItem;
	bItem.m_cType = wType;
	bItem.m_nItemNo = wItemNO;
	if(tagBaseITEM::IsEnableDupCNT(wType)){
		bItem.m_uiQuantity = item->GetQuantity();
	}else{
		bItem.m_cGrade = item->GetGrade();
		if(item->GetOption()){
			bItem.m_bIsAppraisal = item->IsAppraisal();
			bItem.m_nGEM_OP = item->IsAppraisal() ? item->GetOption() : 1; // hide real stat for packet haxors
		}else{
			bItem.m_bIsAppraisal = true;
			bItem.m_nGEM_OP = 0;
		}
	}

	if(classPACKET* cpak = Packet_AllocNLock()){
		CPacket* pak = (CPacket*)cpak;
		pak->CreateNew(PAK_VENDMSG);
		pak->Add<unsigned short>(bItem.m_wHeader);
		pak->Add<unsigned int>(bItem.m_dwBody);
		pak->Add<__int64>(zuly);
		pak->Add<unsigned char>(0);
		pak->AddString(seller->Get_NAME());
		buyer->SendPacket(cpak);

		pak->CreateNew(PAK_VENDMSG);
		pak->Add<unsigned short>(bItem.m_wHeader);
		pak->Add<unsigned int>(bItem.m_dwBody);
		pak->Add<__int64>(zuly);
		pak->Add<unsigned char>(1);
		pak->AddString(buyer->Get_NAME());
		seller->SendPacket(cpak);
		Packet_ReleaseNUnlock(cpak);
	}
}

static _declspec(naked) void ASMSellMessage(){
	static int When_TagItemLOG = 0x10066220;
	static int jRETN = 0x100842E1;
	_asm {
		CALL When_TagItemLOG

		MOV EAX,DWORD PTR SS:[EBP-0x54] // dwMoney1
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x58] // dwMoney2
		PUSH ECX
		LEA EDX,DWORD PTR SS:[EBP-0x4C]	// pITEM
		PUSH EDX
		MOV ECX,DWORD PTR SS:[EBP-0x8]	// pSELLER
		PUSH ECX
		MOV EAX,DWORD PTR SS:[EBP-0x4]	// pBUYER
		PUSH EAX
		CALL VendMessage

		JMP jRETN
	}
}

HookOnLoad(0x100842DC, ASMSellMessage, 0);