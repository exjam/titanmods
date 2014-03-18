#ifndef ITDRAW_H
#define ITDRAW_H

#include "TGameCtrl.h"

//! Interface for Drawing
/*!
This is actually implemented by TRose.exe and passed to TGameCtrl, it allows TGameCtrl to actually draw,
due to TRose.exe not having dll exports I could not figure out how this one works!
*/
class TGAMECTRL_API ITDraw {
public:
	void* mVTable;
};

#endif
