#include "main.h"
#include "CTListItemPvPGame.hpp"
#include "CTListItemPvPInstance.hpp"

CTListItemPvPGame::CTListItemPvPGame(GameType gameType){
	switch(gameType){
		case DRAGON_HUNT:
			mGame = InitDragonHunt(3);
			break;
		case CONQUEST:
			mGame = InitConquest(1);
			break;
		case CTF:
			mGame = InitCTF(4);
			break;
		case KOTH:
			mGame = InitKOTH(4);
			break;
	}

	gGameList->push_back(mGame);
	SetHeight(24);
	SetWidth(250);
	SetEnable(true);
	Show();
}

CTListItemPvPGame::~CTListItemPvPGame(){
}

unsigned int CTListItemPvPGame::Process(UINT uiMsg, WPARAM wParam, LPARAM lParam){
	if(!IsVision())	return 0;

	CMousePos pos;
	pos.mousePos = (long)lParam;

	if(IsInside(pos.x, pos.y)){
		if(uiMsg == WM_LBUTTONUP){
			((CZListBox*)GetParent())->DeselectAll();
			SetSelected();

			if(CTPane* panel = ((CTPane*)gPvPDialog->Find(200))){
				if(CZListBox* listBox = (CZListBox*)panel->m_Children.Find(30)){
					listBox->Clear();

					for(int i = 0; i < mGame->mInstanceList->size(); ++i){
						CTListItemPvPInstance* instance = new CTListItemPvPInstance(mGame->mInstanceList->at(i));
						listBox->Add(instance);
					}

					listBox->SetSelected(0);

					if(CTScrollBar* scrollBar = (CTScrollBar*)panel->m_Children.Find(31))
						scrollBar->MoveHome();
				}
			}

			return 1;
		}else if(uiMsg == WM_LBUTTONDBLCLK){
			if(mGame->mType == DRAGON_HUNT)
				IT_MGR::Instance()->AppendChatMsg("Both teams have their own sets of Dragon Eggs. Once all of a team's Dragon Eggs have been destroyed, their team Dragon will spawn. The winning team is whoever defeats the opposing team's Dragon first.", CHAT_TYPE_QUEST);
			else if(mGame->mType == CONQUEST)
				IT_MGR::Instance()->AppendChatMsg("To win a game of Crystal Conquest, you must capture and control hills on the map, determined by crystals. Once a team controls a hill, their team score will gradually increase. If an enemy is within a certain radius of a crystal, the score will not increase from that hill.", CHAT_TYPE_QUEST);
			else if(mGame->mType == CTF)
				IT_MGR::Instance()->AppendChatMsg("Both teams each have a flag and the objective is to capture the other team's flag, located at the team's base, and bring it safely back to their own base to earn a point. If the flag carrier is killed, the flag will return to base. First team to capture 3 flags will win the game.", CHAT_TYPE_QUEST);
			else if(mGame->mType == KOTH)
				IT_MGR::Instance()->AppendChatMsg("In King of the Hill there is a single hill in the middle of the map. You need to remain on top of the hill to increase your team's score, if none of your team are in the hill you won't get any score. If an enemy is inside the hill with you, you won't gain any score. First team to reach 100 score will win the battle.", CHAT_TYPE_QUEST);

			return 1;
		}
	}

	return 0;
}

void CTListItemPvPGame::Draw(){
	if(!IsVision())	return;

	POINT pt = this->GetPosition();
	ResetTransform((float)pt.x,(float)pt.y);

	tagRECT pos;
	SetRect(&pos, 29, 3, 249, 23);

	if(IsSelected())
		drawFont(GameDATA->m_hFONT[FONT_NORMAL], 1, &pos, COLOUR_YELLOW, FONT_POS_LEFT, mGame->mName);
	else
		drawFont(GameDATA->m_hFONT[FONT_NORMAL], 1, &pos, COLOUR_WHITE, FONT_POS_LEFT, mGame->mName);

	DrawImpl::Instance()->Draw2D(GetPosition().x + 3, GetPosition().y - 1, IMAGE_RES_STATE_ICON, mGame->mIcon, 0xFFFFFFFF);
}

void CTListItemPvPGame::Update(CObservable* observable, CTObject* object) {
}