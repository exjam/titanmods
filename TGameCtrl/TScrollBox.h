#ifndef TSCROLLBOX_H
#define TSCROLLBOX_H

#include "TGameCtrl.h"
#include "TScrollBar.h"
#include "TImage.h"

class CTScrollBoxType;
class CTScrollBar;

//! Scrollbox
/*!
The little box that moves in a scrollbar!
*/

class TGAMECTRL_API CTScrollBox : public CWinCtrl {
public:
	CTScrollBox();
	virtual ~CTScrollBox();

	virtual unsigned int Process(UINT uiMsg, WPARAM wParam, LPARAM lParam);
	virtual	void Update(POINT ptMouse);
	virtual void Draw();

	bool Create(int width, int height, int graphicID, int moduleID, int type = CTScrollBarType::VERTICAL);

	void SetTickMove(int i);
	void SetScrollBar(CTScrollBar* scrollbar);
	void MoveBoxPosition(int value, int max, int extent);
	void MoveBoxPositionByScreenPoint(POINT pt);
	void SetBlink();
	void SetUnblink();
	void SetBlinkImage(CTImage* image);

protected:
	bool mBlink;//70
	int mModuleID;//74
	int mGraphicID;//78
	CTScrollBar* mScrollBar;//7C
	bool mClicked;//80
	CTScrollBoxType* mScrollBoxType;//84
	CTImage* mBlinkImage;//88
};

#endif
