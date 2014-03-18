#ifndef TDIALOG_H
#define TDIALOG_H

#include "TGameCtrl.h"
#include "WinCtrl.h"
#include "TCaption.h"
#include "TStatusBar.h"
#include "TImage.h"
#include "TCommandQ.h"

//! The base dialog class
/*!
This is the base dialog class, all dialogs must inherit from it
but do not necessarily have to expand it, it handles all drawing
and processing for itself and its children.
*/

class TGAMECTRL_API CTDialog : public CWinCtrl {
public:
	//STATIC MEMBERS I THINK COS USING __cdecl NOT __thiscall!
	//ZCALL void SetProcessMouseOverDialog(CTDialog* dialog);
	//ZCALL CTDialog* GetProcessMouseOverDialog();
	CTDialog(void);
	virtual ~CTDialog(void);

	virtual unsigned int Process(UINT uiMsg, WPARAM wParam, LPARAM lParam);
	virtual	void Update(POINT ptMouse);
	virtual void Draw();

	virtual void Show();
	virtual void Hide();
	virtual void MoveWindow(POINT pos);
	virtual bool Create(const char* xml);
	virtual bool IsModal();
	virtual void PostMsg(unsigned msg, unsigned param1, unsigned param2);
	virtual int IsInValidShow();

	bool Create(int posX, int posY, int width, int height);

	void Add(CWinCtrl* control);
	bool Remove(int id);
	CWinCtrl* Find(int id);

	bool ShowChild(unsigned int id);
	bool HideChild(unsigned int id);

	void Push_Back_Cmd(CTCommand* command);
	void Push_Front_Cmd(CTCommand* command);
	void ClearCommandQ();

	void ChangeCaptionRect(RECT rect);

	CTCaption* GetCaption();
	long GetChildCount();
	int GetDefaultAdjustPosX();
	int GetDefaultAdjustPosY();
	int GetDefaultPosX();
	int GetDefaultPosY();
	DWORD GetDialogType();
	CTCommand* GetTCommand();

	void SetCaption(CTCaption* caption);
	void SetDefaultAdjustPosX(int posX);
	void SetDefaultAdjustPosY(int posY);
	void SetDefaultPosX(int posX);
	void SetDefaultPosY(int posY);
	void SetDefaultVisible(bool visible);
	void SetDialogType(DWORD type);
	bool SetEnableChild(unsigned int id, bool enable);
	void SetExtent(int i);
	void SetImage(CTImage* image);
	void SetModal();
	void SetModeless();
	void SetSoundShowID(int i);
	void SetSoundHideID(int i);
	void SetStatusBar(CTStatusBar* statusbar);

	bool IsDefaultVisible();

	void MoveCtrl2ListEnd(int id);
	void ProcessLButtonDown();

protected:
	std_list<CWinCtrl*> mListChildren;//0x70
	std_list<CWinCtrl*> mOwnerDrawChildren;//0x7C
	CTCaption* mCaption;//0x88
	CTStatusBar* mStatusBar;//0x8C
	CTImage* mImage;//0x90
	POINT mPointCaptionClicked;//0x94, 0x98
	DWORD mDialogType;//0x9C
	bool mModal;//0xA0
	int mSoundShowID;//0xA4
	int mSoundHideID;//0xA8
	CTCommandQ mCommandQueue;//0xAC
	int mDefaultPosX;//0xBC
	int mDefaultPosY;//0xC0
	int mDefaultAdjustPosX;//0xC4
	int mDefaultAdjustPosY;//0xC8
	bool mDefaultVisible;//0xCC
	int mExtent;//0xD0
};

#endif
