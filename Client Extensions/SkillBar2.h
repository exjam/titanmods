#ifndef SKILLBAR2_H
#define SKILLBAR2_H

#include "Controls.h"
#include <TRose\Slot.h>

class SkillBar2 : public CTDialog, IObserver {
public:
	SkillBar2(int type);
	virtual ~SkillBar2();

	virtual unsigned int Process(UINT uiMsg, WPARAM wParam, LPARAM lParam);
	virtual void Update(CObservable* observable, CTObject* object);
	virtual void Update(POINT ptMouse);
	virtual void Draw();
	virtual void Show();
	virtual	void MoveWindow(POINT pt);
	virtual bool Create(const char* xmlFile);

	virtual bool IsVision();

	void ChangeType(int type);
	void SetPage(int page);
	unsigned char GetMouseClickSlot(POINT mousePos);
	void UpdateIcons();
	void UpdateSlotOffset();

	enum {
		IID_BG_VERTICAL = 5,
		IID_BG_HORIZONTAL = 6,
		IID_BTN_ROTATE = 10,
		IID_BTN_HORIZONTAL_PREV = 11,
		IID_BTN_HORIZONTAL_NEXT = 12,
		IID_BTN_VERTICAL_PREV = 13,
		IID_BTN_VERTICAL_NEXT = 14,
		IID_NUMBER = 20,
	};

	enum Type {
		HORIZONTAL,
		VERTICAL
	};

public:	
	int mHotKeyCount;
	bool mLoaded;

private:
	CSlot* mQuickSlots[8];
};

class CQuickBAR {
public:
	unsigned char GetMouseClickSlot(POINT& ptMouse){
		return CallMemberFunction<CQuickBAR, unsigned char, POINT&>(0x004C5650, this, ptMouse);
	}
};

#endif