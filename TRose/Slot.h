#ifndef CSLOT_H
#define CSLOT_H

#include <TGameCtrl\WinCtrl.h>
#include <TGameCtrl\TCommand.h>
#include <Shared/Templates.hpp>

class CIcon;
class CDragItem;

class CSlot : public CWinCtrl {
public:
	CSlot() { mIcon = 0; CallMemberFunction<CSlot, void>(0x004CCFF0, this); }//0x4CCFF0
	virtual ~CSlot();
	virtual bool AttachIcon(CIcon* pIcon);
	virtual void DetachIcon();
	virtual CIcon* GetIcon();

	virtual void Draw();
	virtual unsigned int Process(UINT uiMsg, WPARAM wParam, LPARAM lParam);
	virtual void MoveWindow(POINT pt);
	virtual void Update(POINT mousePos);

	void SetParent(int iID) { return CallMemberFunction<CSlot, void, int>(0x004CD0A0, this, iID); } //004CD0A0
	void SetDragAvailable() { return CallMemberFunction<CSlot, void>(0x004CD0B0, this); }//004CD0B0
	void SetDragItem(CDragItem* pDragItem) { return CallMemberFunction<CSlot, void, CDragItem*>(0x004CD0D0, this, pDragItem); }//004CD0D0

/*	FixConstructorAddress(0x004CCFF0, (unsigned char*)&CSlotCreator);
	FixMemberFuncAddress(0x004CD0A0, &CSlot::SetParent);
	FixMemberFuncAddress(0x004CD0B0, &CSlot::SetDragAvailable);
	FixMemberFuncAddress(0x004CD0D0, &CSlot::SetDragItem);*/

protected:
	CIcon* mIcon;
	int mParentID;
	bool mDragAvailable;
	CDragItem* mDragItem;
	CTCommand* mCommand;
	bool mClicked;
	POINT mClickedPos;
	DWORD mTooltipType;
};

#endif
