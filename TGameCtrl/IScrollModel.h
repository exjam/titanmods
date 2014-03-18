#ifndef ISCROLLMODEL_H
#define ISCROLLMODEL_H

#include "TGameCtrl.h"


//! Interface to Scrollable Items
/*!
This is a common interface used for all widgets which allow scrolling.
*/

class TGAMECTRL_API IScrollModel {
public:
	IScrollModel();

	virtual int GetValue() = 0;
	virtual int GetExtent() = 0;
	virtual int GetMaximum() = 0;
	virtual int GetMinimum() = 0;

	virtual void SetValue(int value) = 0;
	virtual void SetExtent(int extent) = 0;
	virtual void SetMaximum(int max) = 0;
	virtual void SetMinimum(int min) = 0;
	virtual RECT GetWindowRect() = 0;

	virtual bool IsLastItemDrawn();
};

#endif
