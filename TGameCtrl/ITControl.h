#ifndef ITCONTROL_H
#define ITCONTROL_H

#include "TGameCtrl.h"


//! Interface to Window Controls
/*!
This is a common interface which all controls must implement, it handles processing windows messages,
updating and drawing the control.
*/

class TGAMECTRL_API ITControl {
public:
	ITControl();
	virtual ~ITControl();

	virtual unsigned int Process(UINT uiMsg,WPARAM wParam,LPARAM lParam) = 0;
	virtual	void Update(POINT ptMouse) = 0;
	virtual void Draw() = 0;
};

#endif
