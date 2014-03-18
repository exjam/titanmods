#ifndef CSINGLELINESTR_H
#define CSINGLELINESTR_H

#include "TGameCtrl.h"

//! Singleline Text
/*!
This is a single line text control, it gets given a RECT which it must fit in, and will automatically cut the string
and prefix it with ... when you start going past the end of the RECT, making it kinda scrollable :).
*/

class TGAMECTRL_API CSinglelineString {
public:
	std_string mMessage;//0x00
	std_string mEllipsisMsg;//0x1C
	DWORD mFormat;//0x38
	RECT mRect;//0x3C
	bool mIsEllipsis;//0x4C
	int mFont;//0x50
	DWORD mColour;//0x54
};

#endif
