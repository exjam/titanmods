#include "main.h"
#include "PartyList.h"
#include "Network.h"
#include <TRose\FriendListItem.h>
#include <ExLIB\Array.hpp>

void __stdcall AddFriend(CFriendListItem* friendListItem){
	CZListBox* listBox = (CZListBox*)ControlInPane(DLG_TYPE_COMMUNITY, 20, 2, 26);
	if(!listBox) return;
	
	for(int i = 0; i < listBox->GetSize(); i++){
		if(strcmp(friendListItem->GetName(), ((CFriendListItem*)listBox->GetItem(i))->GetName()) < 0){
			if(i >= listBox->GetSize())
				listBox->Add(friendListItem);
			else
				listBox->InsertItem(i, friendListItem);

			listBox->SetValue(listBox->GetSize() - 1);

			return;
		}
	}
}

static _declspec(naked) void ASMAddFriend(){
	static int jRet = 0x004A3EDB;
	_asm {
		PUSHAD
		PUSH EAX
		CALL AddFriend
		POPAD
		JMP jRet
	};
}

HookOnLoad(0x004A3ECA, ASMAddFriend, 12);
	
#pragma region MaTTs_code

unsigned char gPartyIsPrivate;
Tooltip* gPartyToolTip;
bool gDrawToolTip;
int gStatus = 0;
const char* gStatusText[7];
clock_t gPartyListUpdate;

void RefreshPartyList(){
	Packet* pak = new Packet(PAK_PARTYLIST);
	pak->Add<byte>(PAK_PARTY_REFRESH);
	SendPacket::Instance()->Send(pak);
	delete pak;
}

void __stdcall CommunityDraw(){
	gDrawToolTip = false;
	CTDialog* dlgCommunity = IT_MGR::Instance()->FindDlg(DLG_TYPE_COMMUNITY);

	if(!dlgCommunity->IsVision()) return;

	_asm {
		MOV ECX, dlgCommunity
		ADD ECX, 0x20
		CALL DWORD PTR DS:[0x0062E628]		// CTDialog::Draw
	}

	if(gDrawToolTip)
		gPartyToolTip->Draw();
}

void __stdcall CommunityProcess(int ControlID, UINT uiMsg){
	CTComboBox* comboBox = (CTComboBox*)ControlInPane(DLG_TYPE_COMMUNITY, 20, 2, 53);
	short status = comboBox->GetSelectedItemID();

	if(status != gStatus){
		gStatus = status;

		Packet* pak = new Packet(0x7E1);
		pak->Add<byte>(0x08);

		if(gStatus == 6)
			pak->Add<byte>(0x80);
		else
			pak->Add<byte>(gStatus);

		SendPacket::Instance()->Send(pak, true);
		delete pak;

		IT_MGR::Instance()->AppendChatMsg(String("Your status has been changed to %1").arg(gStatusText[gStatus]), CHAT_TYPE_SYSTEM);
	}

	if(ControlID == 79 && uiMsg == WM_LBUTTONUP){
		clock_t dt = clock() - gPartyListUpdate;
		if(dt >= 10000) {
			gPartyListUpdate = clock();
			RefreshPartyList();
		}
	}

	clock_t dt = clock() - gPartyListUpdate;

	if(dt < 30000)
		return;

	gPartyListUpdate = clock();	
	RefreshPartyList();
}


void __declspec(naked) ASMCommunityProcess(){
	static int retAddr = 0x004A4073;
	_asm {
		CALL DWORD PTR DS:[0x62E620]
		MOV ESI, DWORD PTR SS:[ESP+0x14]
		PUSHAD
		PUSH ESI
		PUSH EAX
		CALL CommunityProcess
		POPAD
		JMP retAddr
	}
}

void __stdcall ApplyCommunityHooks(){
	int communityDraw = (unsigned int)&CommunityDraw;
	Code::Write<unsigned int>(0x00636648, communityDraw);
	Code::JmpHook(0x004A406D, &ASMCommunityProcess, 1);
}

RunOnLoad(ApplyCommunityHooks)

int MaxMembers(int partyLevel){
	int maxMembers = (partyLevel / 5) + 4;

	if(maxMembers > 7)
		maxMembers = 7;

	return maxMembers;
}

#pragma endregion