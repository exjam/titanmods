#ifndef TRADIOBOX_H
#define TRADIOBOX_H

#include "TGameCtrl.h"
#include "WinCtrl.h"

class CTRadioButton;

//! A RadioButton Group
/*!
A group for radiobuttons allowing multiple sets to be on one dialog
*/

class TGAMECTRL_API CTRadioBox : public CWinCtrl {
public:
	CTRadioBox();
	virtual ~CTRadioBox();
	virtual void Show();

	void EventChangeSelect(unsigned int id);

	bool SetPressedButton(unsigned int id);
	unsigned int GetPressedButtonID();

	void RegisterCtrl(CTRadioButton* button);
	void UnregisterCtrl(CTRadioButton* button);

protected:
	unsigned char mUnk[0xC];//! ?A container for CTRadioButtons?
	int mSelected;//0x7C
};


#endif