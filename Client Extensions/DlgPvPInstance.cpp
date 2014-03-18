#include "main.h"
#include "PvP.h"
#include "CTListItemPvPGame.hpp"
#include "CTListItemPvPInstance.hpp"
#include <TRose\RoseAPI.h>
#include <TRose\IT_MGR.h>
#include <TRose\SendPacket.h>
#include <TRose\DrawImpl.h>
#include <TRose\D3DMatrix.h>
#include <TRose\StringManager.h>
#include <ExLIB\Array.hpp>
#include <ExLIB\List.hpp>
#include <ExLIB\String.hpp>

CTPvPInstance* gPvPInstance;

CTPvPInstance::CTPvPInstance(){
	SetDialogType(DLG_TYPE_PVPINSTANCE);
}

CTPvPInstance::~CTPvPInstance(){
}

bool CTPvPInstance::Create(const char* xmlFile){
	if(CTDialog::Create(xmlFile)){
		mJoin = Find(IID_BTN_JOIN);
		mRed = Find(IID_BTN_RED);
		mBlue = Find(IID_BTN_BLUE);

		return true;
	}

	return false;
}

void CTPvPInstance::Update(POINT ptMouse){
	if(!IsVision())	return;

	CTDialog::Update(ptMouse);

	if(mInstance->mStatus == GAME_STATUS_BUSY){
		if(mInstance->IsRed() || mInstance->IsBlue()){
			mJoin->Show();
			mRed->Hide();
			mBlue->Hide();
		} 
		else{
			mJoin->Hide();
			mRed->Hide();
			mBlue->Hide();
		}
	}else if(mInstance->mStatus == GAME_STATUS_FULL || mInstance->mStatus == GAME_STATUS_CANCEL || mInstance->mStatus == GAME_STATUS_CLOSED){ 
		mJoin->Hide();
		mRed->Hide();
		mBlue->Hide();
	}else if(mInstance->mStatus == GAME_STATUS_SIGNUP){ 
		if(mInstance->HasFlag()){
			mJoin->Hide();
			mRed->Hide();
			mBlue->Hide();
		}else{
			mJoin->Hide();
			mRed->Show();
			mBlue->Show();
		}
	}
}

void CTPvPInstance::Draw(){
	if(!IsVision())	return;

	if(!CanShowPVP()){
		Hide();
		return;
	}

	CTDialog::Draw();

	POINT pt = GetPosition();
	ResetTransform((float)pt.x,(float)pt.y);

	if(!StringManager::Instance())
		return;

	const char* zoneName = StringManager::Instance()->GetZoneName(mInstance->mGame->mMapID);

	tagRECT pos;
	SetRect(&pos, 54, 35, 192, 51);
	drawFont(GameDATA->m_hFONT[FONT_NORMAL], 1, &pos, COLOUR_WHITE, FONT_POS_CENTER, String("%1 (%2)").arg(mInstance->mGame->mName).arg(mInstance->mID));
	SetRect(&pos, 54, 60, 192, 76);
	drawFont(GameDATA->m_hFONT[FONT_NORMAL], 1, &pos, COLOUR_WHITE, FONT_POS_CENTER, zoneName);
	SetRect(&pos, 54, 85, 100, 101);

	if(mInstance->mIsNewb && mInstance->mGame->mType == CTF){
		drawFont(GameDATA->m_hFONT[FONT_NORMAL], 1, &pos, COLOUR_BABYRED, FONT_POS_CENTER, String("%1/7").arg(mInstance->mPlayersRed));
		SetRect(&pos, 146, 85, 192, 101);
		drawFont(GameDATA->m_hFONT[FONT_NORMAL], 1, &pos, COLOUR_BABYBLUE, FONT_POS_CENTER, String("%1/7").arg(mInstance->mPlayersBlue));
	}else{
		drawFont(GameDATA->m_hFONT[FONT_NORMAL], 1, &pos, COLOUR_BABYRED, FONT_POS_CENTER, String("%1/%2").arg(mInstance->mPlayersRed).arg(mInstance->mGame->mMaxPlayers));
		SetRect(&pos, 146, 85, 192, 101);
		drawFont(GameDATA->m_hFONT[FONT_NORMAL], 1, &pos, COLOUR_BABYBLUE, FONT_POS_CENTER, String("%1/%2").arg(mInstance->mPlayersBlue).arg(mInstance->mGame->mMaxPlayers));
	}

	SetRect(&pos, 54, 110, 192, 126);
	drawFont(GameDATA->m_hFONT[FONT_NORMAL], 1, &pos, COLOUR_WHITE, FONT_POS_CENTER, gGameStatus[mInstance->mStatus]);
}

unsigned int CTPvPInstance::Process(UINT uiMsg, WPARAM wParam, LPARAM lParam){
	if(!IsVision()) return 0;

	unsigned int controlID = CTDialog::Process(uiMsg, wParam, lParam);

	if(uiMsg == WM_LBUTTONUP){
		switch(controlID){
			case IID_BTN_CLOSE:
				Hide();
				break;
			case IID_BTN_RED:
				{
					if (CGameOBJ* self = CObjMGR::GetSelf()){
						if(mInstance->mID >= 4 && self->GetLevel() > 110){
							IT_MGR::Instance()->OpenMsgBox("Your character level is too high to play in this instance.", MsgBox::BT_OK, true, 0, NULL, NULL, 0);
							break;
						}
					}

					if(HasGameQuest()){
						IT_MGR::Instance()->OpenMsgBox("You must give up your other PvP game before you can sign up.", MsgBox::BT_OK, true, 0, NULL, NULL, 0);
						break;
					}

					String quest = String(mInstance->mGame->mJoinRed).arg(mInstance->mID);
					if(::QF_checkQuestCondition(quest.Str()))
						SendPacket::Instance()->DoTrigger(3, 0, 0, quest.Str());
				}
				break;
			case IID_BTN_BLUE:
				{
					if(CGameOBJ* self = CObjMGR::GetSelf()){
						if(mInstance->mID >= 4 && self->GetLevel() > 110){
							IT_MGR::Instance()->OpenMsgBox("Your character level is too high to play in this instance.", MsgBox::BT_OK, true, 0, NULL, NULL, 0);
							break;
						}
					}

					if(HasGameQuest()){
						IT_MGR::Instance()->OpenMsgBox("You must give up your other PvP game before you can sign up.", MsgBox::BT_OK, true, 0, NULL, NULL, 0);
						break;
					}

					String quest = String(mInstance->mGame->mJoinBlue).arg(mInstance->mID);
					if(::QF_checkQuestCondition(quest.Str()))
						SendPacket::Instance()->DoTrigger(3, 0, 0, quest.Str());
				}
				break;
			case IID_BTN_JOIN:
				{
					String quest = String(mInstance->mGame->mJoinBattle).arg(mInstance->mID);
					if(::QF_checkQuestCondition(quest.Str()))
						SendPacket::Instance()->DoTrigger(3,0,0, quest.Str());
				}
				break;
		}
	}

	return controlID;
}

void CTPvPInstance::Show(){
	if(GetPosition().x == 0 && GetPosition().y == 0){
		POINT pt;
		pt.x = (getScreenWidth() / 2) - (GetWidth() / 2);
		pt.y = (getScreenHeight() / 2) - (GetHeight() / 2);
		MoveWindow(pt);
	}

	CTDialog::Show();
}