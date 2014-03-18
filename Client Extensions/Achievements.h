#ifndef DLGAchievements_H
#define DLGAchievements_H

#include "Controls.h"
#include <ExLIB\Array.hpp>

class CZListBox;
class CTScrollBar;
class Achievement;

class CTAchievements : public CTDialog, IObserver {
public:
	CTAchievements();
	virtual ~CTAchievements();

	virtual unsigned int Process(UINT uiMsg, WPARAM wParam, LPARAM lParam);
	virtual void Draw();
	virtual void Show();

	virtual void Update(CObservable* observable, CTObject* object){}

private:
	void SetListBox(Array<Achievement*>& useList);
	int GetAchievementCnt();
	void ToggleSortMode();

public:
	int mWonCount;
	Array<Achievement*> mCurrList;
	bool mSortByID;

private:
	CZListBox* mListBox;
	CTScrollBar* mScrollBar;
};

#endif