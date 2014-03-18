#ifndef WINCTRL_H
#define WINCTRL_H

#include "TGameCtrl.h"
#include "TObject.h"
#include "ITControl.h"
#include "ITDraw.h"
#include "ActionListenerList.h"

//! The base class for all window controls
/*!
This is the base class for all window controls, every control
must inherit from it, it has many helper functions which
are shared across all controls.
*/

class TGAMECTRL_API CWinCtrl : public CTObject, public ITControl {
public:
	//STATIC MEMBERS I THINK COS USING __cdecl NOT __thiscall!
	//class CWinCtrl * (ZCALL CWinCtrl::*PTG_CWinCtrl_GetMouseExclusiveCtrl();
	//class CWinCtrl * (ZCALL CWinCtrl::*PTG_CWinCtrl_GetProcessMouseOverCtrl();
	//bool (ZCALL CWinCtrl::*PTG_CWinCtrl_IsExclusive();
	//bool (ZCALL CWinCtrl::*PTG_CWinCtrl_IsProcessMouseOver();
	//void (ZCALL CWinCtrl::*PTG_CWinCtrl_SetMouseExclusiveCtrl(class CWinCtrl *);
	//void (ZCALL CWinCtrl::*PTG_CWinCtrl_SetProcessMouseOver(bool);
	//void (ZCALL CWinCtrl::*PTG_CWinCtrl_SetProcessMouseOverCtrl(class CWinCtrl *);
	CWinCtrl();
	virtual ~CWinCtrl();

	virtual unsigned int Process(UINT uiMsg,WPARAM wParam,LPARAM lParam);
	virtual	void Update(POINT ptMouse);
	virtual	void Draw();

	virtual void Draw(POINT draw);
	virtual bool IsInside(int x, int y);
	virtual void Init(DWORD type, int posX, int posY, int width, int height);
	virtual void OwnerDraw();
	virtual void SetSelected();
	virtual void SetDeselected();
	virtual void Show();
	virtual void Hide();
	virtual void SetFocus(bool focus);
	virtual bool IsVision();
	virtual void SetOffset(int x, int y);
	virtual void SetOffset(POINT offset);
	virtual void MoveWindow(POINT pos);

	void AddActionListener(IActionListener* actionListener);
	void RemoveActionListener(IActionListener* actionListener);

	bool IsActive();
	bool IsEnable();
	bool IsFocus();
	bool IsOwnerDraw();
	bool IsSelected();

	unsigned int GetControlID();
	int GetControlType();
	int GetHeight();
	POINT GetOffset();
	CWinCtrl * GetParent();
	POINT GetPosition();
	int GetWidth();

	void SetActive(bool active);
	void SetAlphaValue(unsigned char alpha);
	void SetControlID(unsigned int id);
	void SetControlType(unsigned long type);
	void SetCtrlStatus(unsigned long status);
	void SetDraw(ITDraw* draw);
	void SetEnable(bool enable);
	void SetHeight(int height);
	void SetOwnerDraw(bool ownerDraw);
	void SetParent(CWinCtrl* parent);
	int SetPosition(int posX, int posY);
	int SetPosition(POINT pos);
	void SetScaleHeight(float scaleHeight);
	void SetScaleWidth(float scaleWidth);
	void SetWidth(int width);

protected:
	//CTObject is at 0x00
	//ITControl is at 0x20

	CWinCtrl* mParent;//0x24
	DWORD mStatus;//0x28
	DWORD mControlType;//0x2C
	POINT mPosition;//0x30, 0x34
	POINT mOffset;//0x38, 0x3C
	DWORD mWidth;//0x40
	DWORD mHeight;//0x44
	DWORD mControlID;//0x48
	DWORD mParentID;//0x4c
	ITDraw* mDraw;//0x50
	bool mSelected;//0x54
	bool mOwnerDraw;//0x55
	float mScaleWidth;//0x58
	float mScaleHeight;//0x5C
	BYTE mAlphaValue;//0x60
	CActionListenerList mActionListenerList;//0x64
};

#endif
