#ifndef TCHECKBOX_H
#define TCHECKBOX_H

#include "TGameCtrl.h"
#include "WinCtrl.h"

//! Checkbox
/*!
A checkbox control, you all know what they are.
*/

class TGAMECTRL_API CTCheckBox : public CWinCtrl {
public:
	CTCheckBox();
	virtual ~CTCheckBox();

	virtual unsigned Process(UINT uiMsg, WPARAM wParam, LPARAM lParam);
	virtual void Draw();

	bool Create(int posX, int posY, int width, int height, int moduleID, int checkImageID, int uncheckImageID);

	bool IsCheck();
	void SetCheck();
	void SetUncheck();

public:
	enum{
		UNCHECK,
		CHECK
	};

protected:
	int	mCheckState;
	int	mModuleID;
	int mCheckImageID;
	int mUncheckImageID;
};

#endif