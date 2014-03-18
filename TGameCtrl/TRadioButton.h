#ifndef TRADIOBOX_H
#define TRADIOBOX_H

#include "TGameCtrl.h"
#include "WinCtrl.h"
#include "SinglelineString.h"

class CTRadioBox;

//! RadioButton
/*!
I think you all know what radio buttons do.
*/

class TGAMECTRL_API CTRadioButton : public CWinCtrl {
public:
	CTRadioButton();
	virtual ~CTRadioButton();

	virtual unsigned int Process(UINT uiMsg, WPARAM wParam, LPARAM lParam);
	virtual	void Update(POINT ptMouse);
	virtual void Draw();

	bool Create(int posX, int posY, int width, int height, int normalGID, int overGID, int downGID, int moduleID);

	short GetButtonState();
	CSinglelineString& GetText();
	void SetButtonState(int state);
	void SetGhost();
	void SetRadioBox(CTRadioBox* box);
	void SetSoundDisableID(int id);
	void SetText(char* text);

public:
	enum {
		NORMAL,
		MOUSEOVER,
		CLICKED
	};

protected:
	CSinglelineString mString;//0x70
	short mState;//0xC8
	int mModuleID;//0xCC
	int mNormalGraphicID;//0xD0
	int mOverGraphicID;//0xD4
	int mDownGraphicID;//0xD8
	int mDisableSoundID;//0xDC
	CTRadioBox* mRadioBox;//0xE0
	bool mGhost;//0xE8
};

#endif
