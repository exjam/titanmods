#include "main.h"
#include "DuelInvite.h"
#include "Controls.h"
#include "Network.h"
#include <TRose\RoseAPI.h>
#include <TRose\IT_MGR.h>
#include <TRose\SendPacket.h>
#include <TRose\DrawImpl.h>
#include <TRose\D3DMatrix.h>
#include <TRose\StringManager.h>
#include <TRose\CObjCHAR.h>
#include <ExLIB\Array.hpp>
#include <ExLIB\List.hpp>
#include <ExLIB\String.hpp>

CTDuelInvite* gDuelInvite;

CTDuelInvite::CTDuelInvite(){
	SetDialogType(DLG_TYPE_DUELINVITE);
	SetModal();
}

CTDuelInvite::~CTDuelInvite(){
}

bool CTDuelInvite::Create(const char* xmlFile){
	if(CTDialog::Create(xmlFile)){
		if(CTComboBox* comboBox = (CTComboBox*)Find(IID_BTN_COMBOMODE)){
			comboBox->AddItem(" Best of 1");
			comboBox->AddItem(" Best of 3");
			comboBox->AddItem(" Best of 5");
			comboBox->SetSelectedItem(1);
		}

		return true;
	}
	
	return false;
}

void CTDuelInvite::Update(POINT ptMouse){
	if(!IsVision()) return;
	
	CTDialog::Update(ptMouse);
}

void CTDuelInvite::Draw(){
	if(!IsVision()) return;
		
	CTDialog::Draw();
}

int CTDuelInvite::GetNumber(){
	CTEditBox* editBox = ((CTEditBox*)Find(IID_BTN_EDITBOX));
	if(!editBox) return 0;

	char* text = editBox->get_text();
	if(text == NULL) return 0;

	return atoi(text);
}

unsigned int CTDuelInvite::Process(UINT uiMsg, WPARAM wParam, LPARAM lParam){
	if (!IsVision()) return 0;

	unsigned int controlID = CTDialog::Process(uiMsg, wParam, lParam);

	if(uiMsg == WM_LBUTTONUP){
		switch(controlID){
			case IID_BTN_OK:	// OK
				{
					CUserInputState* inputState = CUserInputState::Instance();
					CGameOBJ* self = CObjMGR::GetSelf();

					if(!inputState || !self) break;

					int duelZulie = GetNumber();
					if(duelZulie > 1000000){
						Hide();
						IT_MGR::Instance()->OpenMsgBox("You can only bet up to 1,000,000 zulie.", MsgBox::BT_OK, false, 0, NULL, NULL, 0);
						break;
					}

					int zulie = self->GetStat(40);
					if(zulie < duelZulie){
						Hide();
						IT_MGR::Instance()->OpenMsgBox("You do not have enough zulie.", MsgBox::BT_OK, false, 0, NULL, NULL, 0);
						break;
					}

					int zoneNO = CTERRAIN::Instance()->m_nZoneNO;
					if(zoneNO >= 70 || ((zoneNO != 6 && zoneNO != 29) && CGameDATA::Instance()->m_iPvPState != PVP_CANT)){
						Hide();
						IT_MGR::Instance()->OpenMsgBox("You cannot duel in this PVP Zone.", MsgBox::BT_OK, false, 0, NULL, NULL, 0);
						break;
					}

					short mode = 1;
					if(CTComboBox* comboBox = (CTComboBox*)Find(IID_BTN_COMBOMODE)){
						mode = comboBox->GetSelectedItemID();
					}

					int target = inputState->m_iCurrentTarget;
					if(!target){
						Hide();
						IT_MGR::Instance()->OpenMsgBox("Select a player.", MsgBox::BT_OK, false, 0, NULL, NULL, 0);
						break;
					}

					int serverIndex = CObjMGR::Instance()->Get_ServerObjectIndex(inputState->m_iCurrentTarget);

					Packet* pak = new Packet(PAK_DUEL);
					pak->Add<byte>(0);	// Request
					pak->Add<int>(serverIndex);
					pak->Add<int>(duelZulie);
					pak->Add<int>(mode);
					SendPacket::Instance()->Send(pak);

					if(CObjCHAR* object = CObjMGR::Instance()->Get_ClientCharOBJ(serverIndex, false))
						IT_MGR::Instance()->AppendChatMsg(String("Sent duel invite to %1.").arg(object->GetName()), CHAT_TYPE_SYSTEM);

					delete pak;
					Hide();
				}
				break;
			case IID_BTN_CANCEL:
				Hide();
				break;
		}
	}else if(uiMsg == WM_LBUTTONUP){
		if(CTEditBox* editBox = ((CTEditBox*)Find(IID_BTN_EDITBOX)))
			editBox->SetFocus( true );
	}

	return controlID;
}

void CTDuelInvite::Show(){
	POINT pt;
	pt.x = (getScreenWidth() / 2) - (GetWidth() / 2);
	pt.y = (getScreenHeight() / 2) - (GetHeight() / 2);
	MoveWindow(pt);

	CTDialog::Show();
}