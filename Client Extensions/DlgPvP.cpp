#include "main.h"
#include "PvP.h"
#include "Controls.h"

#include "CTAcceptGiveUP.hpp"
#include "CTListItemPvPGame.hpp"
#include "CTListItemPvPInstance.hpp"
#include <TRose\RoseAPI.h>
#include <TRose\CObjMGR.h>
#include <TRose\CGameOBJ.h>

#include <TRose\IT_MGR.h>
#include <TRose\SendPacket.h>
#include <TRose\DrawImpl.h>
#include <TRose\D3DMatrix.h>
#include <ExLIB\Array.hpp>
#include <ExLIB\List.hpp>
#include <ExLIB\String.hpp>

CTPvP* gPvPDialog;

CTPvP::CTPvP(){
	SetDialogType(DLG_TYPE_PVP);
	mMinimized = false;
}

CTPvP::~CTPvP(){
	if(CTPane* panel = (CTPane*)Find(100)){
		if(CZListBox* listBox = (CZListBox*)panel->m_Children.Find(20))
			listBox->Clear();
	}

	if(CTPane* panel = (CTPane*)Find(200)){
		if(CZListBox* listBox = (CZListBox*)panel->m_Children.Find(30))
			listBox->Clear();
	}
}

void CTPvP::Draw(){
	if(!IsVision())	return;

	if(!CanShowPVP()){ 
		Hide();

		return; 
	}

	CTDialog::Draw();

	CGameOBJ* self = CObjMGR::GetSelf();

	if(!self) 
		return;

	POINT pt = this->GetPosition();
	ResetTransform((float)pt.x, (float)pt.y);

	int icon = GetRank() + 2735;

	if(icon > 2741)
		icon += 1;

	DrawImpl::Instance()->Draw2D(GetPosition().x + 228, GetPosition().y + 44, IMAGE_RES_ITEM, icon, 0xFFFFFFFF);

	ResetTransform((float)pt.x, (float)pt.y);

	tagRECT pos;
	SetRect(&pos, 81, 46, 81 + 131, 46 + 17);

	if(GetRank() == 0)
		drawFont(GameDATA->m_hFONT[FONT_NORMAL_BOLD], 1, &pos, COLOUR_RED, FONT_POS_CENTER, "Unranked");
	else
		drawFont(GameDATA->m_hFONT[FONT_NORMAL_BOLD], 1, &pos, COLOUR_YELLOW, FONT_POS_CENTER, gGameRank[GetRank()]);

	SetRect(&pos, 81, 66, 81 + 37,66 + 17);
	drawFont(GameDATA->m_hFONT[FONT_NORMAL], 1, &pos, COLOUR_WHITE, FONT_POS_CENTER, String("%1").arg(self->GetStat(86)));
	SetRect(&pos, 175, 66, 175 + 37,66 + 17);
	drawFont(GameDATA->m_hFONT[FONT_NORMAL], 1, &pos, COLOUR_WHITE, FONT_POS_CENTER, String("%1").arg(self->GetStat(87)));
	ResetTransform((float)pt.x, (float)pt.y);

	if(!mMinimized)
		SetRect(&pos, 15, 410, 15 + 195, 410 + 17);
	else
		SetRect(&pos, 15, 295, 15 + 195, 295 + 17);
	
	if(PvPInstance* instance = HasGameQuest()){
		if(instance->IsBlue())
			drawFont(GameDATA->m_hFONT[FONT_NORMAL], 1, &pos, COLOUR_WHITE, FONT_POS_LEFT, String("%1 - Instance %2 - Blue").arg(instance->mGame->mName).arg(instance->mID));
		else if(instance->IsRed())
			drawFont(GameDATA->m_hFONT[FONT_NORMAL], 1, &pos, COLOUR_WHITE, FONT_POS_LEFT, String("%1 - Instance %2 - Red").arg(instance->mGame->mName).arg(instance->mID));
		else if(instance->HasFlag())
			drawFont(GameDATA->m_hFONT[FONT_NORMAL], 1, &pos, COLOUR_WHITE, FONT_POS_LEFT, String("%1 - Instance %2 - Quit").arg(instance->mGame->mName).arg(instance->mID));
	}
}

unsigned int CTPvP::Process(UINT uiMsg, WPARAM wParam, LPARAM lParam){
	if(!IsVision())	return 0;

	unsigned int controlID = CTDialog::Process(uiMsg, wParam, lParam);

	if(uiMsg == WM_LBUTTONUP){
		switch(controlID){
			case IID_BTN_CLOSE:
				Hide();
				break;
			case IID_BTN_MAXIMIZE:
				Find(IID_BTN_MINIMIZE)->Show();
				Find(IID_BTN_MAXIMIZE)->Hide();
				Find(IID_PANEL_TOP)->Show();
				Find(IID_PANEL_BOTTOM)->SetOffset(0,233);
				MoveWindow(mPosition);
				mMinimized = false;
				break;
			case IID_BTN_MINIMIZE:
				Find(IID_BTN_MINIMIZE)->Hide();
				Find(IID_BTN_MAXIMIZE)->Show();
				Find(IID_PANEL_TOP)->Hide();
				Find(IID_PANEL_BOTTOM)->SetOffset(0, 118);
				MoveWindow(mPosition);
				mMinimized = true;
				break;
			case IID_BTN_GIVEUP:
				{
					if(PvPInstance* current = HasGameQuest()){
						CTCommand* command = new CTAcceptGiveUP(String(current->mGame->mGiveUp).arg(current->mID).Str());
						IT_MGR::Instance()->OpenMsgBox("Do you really want to give up this game?", MsgBox::BT_OKCANCEL, true, 0, command, NULL, 0);
					}
					break;
				}
			case IID_BTN_ICONIZE:
				IT_MGR::Instance()->AddDialogIcon(GetDialogType());
				break;
		}
	}

	return controlID;
}

void CTPvP::Show(){
	CGameOBJ* self = CObjMGR::GetSelf();
	if(!self) return;

	if(self->GetLevel() < 70){
		IT_MGR::Instance()->OpenMsgBox("You must be level 70 to unlock this feature.", MsgBox::BT_OK, true, 0, NULL, NULL, 0);
		return;
	}

	if(GetPosition().x == 0 && GetPosition().y == 0){
		POINT pt;
		pt.x = (getScreenWidth() / 2) - (GetWidth() / 2);
		pt.y = (getScreenHeight() / 2) - (GetHeight() / 2);
		MoveWindow(pt);
	}

	CTDialog::Show();

	if(mMinimized == false){
		Find(IID_BTN_MINIMIZE)->Show();
		Find(IID_PANEL_TOP)->Show();
		Find(IID_BTN_MAXIMIZE)->Hide();
	}else{
		Find(IID_BTN_MINIMIZE)->Hide();
		Find(IID_PANEL_TOP)->Hide();
		Find(IID_BTN_MAXIMIZE)->Show();
	}
}

void CTPvP::InitGameList(){
	if(!gGameList){
		gGameList = new List<PvPGame*>;

		CTPane* topPanel = (CTPane*)gPvPDialog->Find(IID_PANEL_TOP);
		CZListBox* topList = (CZListBox*)topPanel->m_Children.Find(IID_LIST_TOP);
		CTScrollBar* topScroll = (CTScrollBar*)topPanel->m_Children.Find(IID_SCROLL_TOP);

		CTPane* bottomPanel = (CTPane*)gPvPDialog->Find(IID_PANEL_BOTTOM);
		CZListBox* bottomList = (CZListBox*)bottomPanel->m_Children.Find(IID_LIST_BOTTOM);
		CTScrollBar* bottomScroll = (CTScrollBar*)bottomPanel->m_Children.Find(IID_SCROLL_BOTTOM);
		
		topList->Add(new CTListItemPvPGame(DRAGON_HUNT));
		topList->Add(new CTListItemPvPGame(CONQUEST));
		topList->Add(new CTListItemPvPGame(CTF));
		topList->Add(new CTListItemPvPGame(KOTH));
		topList->SetSelected(0);
		topScroll->MoveHome();

		bottomList->Clear();
		PvPGame* gameItem =  gGameList->at(0);
		for(unsigned int i = 0; i < gameItem->mInstanceList->size(); ++i)
			bottomList->Add(new CTListItemPvPInstance(gameItem->mInstanceList->at(i)));

		bottomList->SetSelected(0);
		bottomScroll->MoveHome();
	}
}