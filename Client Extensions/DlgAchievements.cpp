#include "main.h"
#include "Achievements.h"
#include <TRose\RoseAPI.h>
#include <TRose\CObjMGR.h>
#include <TRose\CGameOBJ.h>
#include <TRose\D3DMatrix.h>
#include <ExLIB\Array.hpp>
#include <ExLIB\String.hpp>

CTAchievements* gAchieveDialog;

class CTListItemAchievement : public CWinCtrl {
public:
	CTListItemAchievement(){
		SetHeight(45);
		SetWidth(400);
		SetEnable(true);
		Show();
	}

	virtual ~CTListItemAchievement(){}

	virtual unsigned int Process(UINT uiMsg, WPARAM wParam, LPARAM lParam){
		if(!IsVision())	return 0;

		if(uiMsg == WM_LBUTTONUP){
			CMousePos pos;
			pos.mousePos = (long)lParam;

			if(IsInside(pos.x, pos.y)){
				((CZListBox*)GetParent())->DeselectAll();
				SetSelected();

				return 1;
			}
		}

		return 0;
	}

	virtual	void Draw(){
		if(!IsVision())	return;

		int drawIcon = mAchievement->mUnkIcon;
		unsigned long colour = COLOUR_WHITE;
		const char* nameText = mAchievement->mUnkName;
		const char* descText = mAchievement->mUnkDescription;
		bool achieved = gAchievementData.HasAchievement(mAchievement->mID);

		if(achieved){
			colour = COLOUR_YELLOW;
			drawIcon = mAchievement->mIcon;
		}

		if(achieved || !nameText)
			nameText = mAchievement->mName;

		if(achieved || !descText)
			descText = mAchievement->mDescription;

		DrawImpl::Instance()->Draw2D(GetPosition().x + 2, GetPosition().y + 3, IMAGE_RES_ITEM, drawIcon, 0xFFFFFFFF);

		tagRECT pos;
		SetRect(&pos, 43, 2, 357, 21);
		drawFont(GameDATA->m_hFONT[FONT_NORMAL_OUTLINE], 1, &pos, colour, FONT_POS_CENTER, nameText);
		SetRect(&pos, 43, 24, 357, 44);
		drawFont(GameDATA->m_hFONT[FONT_OUTLINE_14], 1, &pos, COLOUR_WHITE, FONT_POS_CENTER, descText);
	}

	Achievement* mAchievement;
};

CTAchievements::CTAchievements(){
	mWonCount = 0;
	mSortByID = true;
	SetDialogType(DLG_TYPE_ACHIEVEMENTS);
}

CTAchievements::~CTAchievements(){
	mListBox = (CZListBox*)Find(22);

	if(mListBox)
		mListBox->Clear();
}

void CTAchievements::Draw(){
	if(!IsVision())	return;

	CTDialog::Draw();

	POINT pt = this->GetPosition();
	ResetTransform((float)pt.x,(float)pt.y);

	tagRECT pos;
	SetRect(&pos, 352, 391, 352 + 75, 391 + 17);

	char buffer[32];
	sprintf_s(buffer, 32, "%u/%u", mWonCount, GetAchievementCnt());

	drawFont(GameDATA->m_hFONT[FONT_LARGE], 1, &pos, COLOUR_WHITE, FONT_POS_CENTER, buffer);
}

void CTAchievements::ToggleSortMode(){
	mSortByID = !mSortByID;
}

unsigned int CTAchievements::Process(UINT uiMsg, WPARAM wParam, LPARAM lParam){
	if(!IsVision())	return 0;

	unsigned int controlID = CTDialog::Process(uiMsg, wParam, lParam);

	if(uiMsg == WM_LBUTTONUP && controlID == 10)
		Hide();
	else if(uiMsg == WM_LBUTTONDOWN){
		switch(controlID){
			case 32:
				SetListBox(gAchievementList.mGeneral);
				mCurrList = gAchievementList.mGeneral;
				break;
			case 42:
				SetListBox(gAchievementList.mQuests);
				mCurrList = gAchievementList.mQuests;
				break;
			case 52:
				SetListBox(gAchievementList.mEvents);
				mCurrList = gAchievementList.mEvents;
				break;
			case 62:
				SetListBox(gAchievementList.mClan);
				mCurrList = gAchievementList.mClan;
				break;
			case 72:
				SetListBox(gAchievementList.mMonster);
				mCurrList = gAchievementList.mMonster;
				break;			
			case 82:
				SetListBox(gAchievementList.mPvp);
				mCurrList = gAchievementList.mPvp;
				break;
			case 80:
				ToggleSortMode();
				SetListBox(mCurrList);
				break;
		}
	}

	return controlID;
}

void CTAchievements::Show(){
	if(GetPosition().x == 0 && GetPosition().y == 0){
		POINT pt;
		pt.x = (getScreenWidth() / 2) - (this->GetWidth() / 2);
		pt.y = (getScreenHeight() / 2) - (this->GetHeight() / 2);
		MoveWindow(pt);
	}

	if(CTabbedPane* tabbedPane = (CTabbedPane*)Find(30))
		tabbedPane->SetSelectedIndex(0);

	if(CTButton* button = (CTButton*)Find(80))
		button->SetText("Sort");
	
	SetListBox(gAchievementList.mGeneral);
	mCurrList = gAchievementList.mGeneral;

	CTDialog::Show();
}

int CTAchievements::GetAchievementCnt(){
	int count = 0;

	for(unsigned int i = 0; i < gAchievementList.mAll.Size(); ++i){
		if(gAchievementList.mAll[i]->mHideIfUnachieved && !gAchievementData.HasAchievement(gAchievementList.mAll[i]->mID))
			continue;

		count++;
	}

	return count;
}

void CTAchievements::SetListBox(Array<Achievement*>& useList){
	mListBox = (CZListBox*)Find(22);
	mScrollBar = (CTScrollBar*)Find(23);

	if(!mListBox || !mScrollBar)
		return;

	mListBox->Clear();

	if(mSortByID){
		for(unsigned int i = 0; i < useList.Size(); ++i){
			Achievement* ach = useList[i];

			if(ach->mHideIfUnachieved && !gAchievementData.HasAchievement(ach->mID))
				continue;

			CTListItemAchievement* AchItem = new CTListItemAchievement();
			AchItem->mAchievement = ach;
			ach->mListItem = AchItem;

			mListBox->Add(AchItem);
		}
	}
	else{
		// Achieved
		for(unsigned int i = 0; i < useList.Size(); ++i){
			Achievement* ach = useList[i];

			if(!gAchievementData.HasAchievement(ach->mID))
				continue;

			CTListItemAchievement* AchItem = new CTListItemAchievement();
			AchItem->mAchievement = ach;
			ach->mListItem = AchItem;
			mListBox->Add(AchItem);
		}
		// Not achieved
		for(unsigned int i = 0; i < useList.Size(); ++i){
			Achievement* ach = useList[i];
			
			if(gAchievementData.HasAchievement(ach->mID) || ach->mHideIfUnachieved)
				continue;

			CTListItemAchievement* AchItem = new CTListItemAchievement();
			AchItem->mAchievement = ach;
			ach->mListItem = AchItem;
			mListBox->Add(AchItem);
		}
	}

	mScrollBar->MoveHome();
	mListBox->SetSelected(0);
}