#ifndef TSTATUSBAR_H
#define TSTATUSBAR_H

#include "TGameCtrl.h"
#include "WinCtrl.h"
#include "TImage.h"

//! Status bar
/*!
A status bar control which allows only an image,
why this is used I do not know :D
*/

class TGAMECTRL_API CTStatusBar : public CWinCtrl {
public:
	CTStatusBar(void);
	virtual ~CTStatusBar(void);
	virtual void Draw();
	virtual void Update(POINT ptMouse);
	virtual void MoveWindow(POINT pt);

	void SetImage(CTImage* image);

protected:
	CTImage* mImage;//0x70
};

#endif
