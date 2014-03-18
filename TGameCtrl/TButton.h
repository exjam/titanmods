#ifndef TBUTTON_H
#define TBUTTON_H

#include "TGameCtrl.h"
#include "SinglelineString.h"
#include "WinCtrl.h"

//! Button
/*!
A simple push button control
*/

class TGAMECTRL_API CTButton : public CWinCtrl {
public:
	CTButton();
	virtual ~CTButton();

	virtual unsigned int Process(UINT uiMsg, WPARAM wParam, LPARAM lParam);
	virtual	void Update(POINT ptMouse);
	virtual void Draw();

	bool Create(int posX, int posY, int width, int height, int normalGID, int overGID, int downGID , int moduleID);

	CSinglelineString& GetText();
	void SetText(char* text);
	void SetTextColor(unsigned long colour);

	void SetButtonState(int state);
	int GetButtonState();

	void SetSoundOverID(int id);
	void SetSoundClickID(int id);
	void SetDisableGrahicID(int id);//Lol rose did a typo fail

	void SetNoImage();
	void SetBlink(int blink, int blinkTime);

	void SetBlinkGid(int graphicID);

protected:
	CSinglelineString mText;//0x70
	int mButtonState;//0xC8
	int mModuleID;//0xCC
	int mNormalGraphicID;//0xD0
	int mOverGraphicID;//0xD4
	int mWTFUXWHERERU;//0xD8
	int mSourceNormalGraphicID;//0xDC
	int	mDownGraphicID;//0xE0
	int mDisableGraphicID;//0xE4
	int mOverSoundID;//0xE8
	int mClickSoundID;//0xEC
	int mBlink;//0xF0
	int mBlinkTime;//0xF4
	DWORD mPrevUpdateTime;//0xF8
	bool mNoImage;//0xFC
};

#endif
