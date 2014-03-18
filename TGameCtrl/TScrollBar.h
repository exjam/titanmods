#ifndef TSCROLLBAR_H
#define TSCROLLBAR_H

//Above includes so TScrollBox can has this

#include "TGameCtrl.h"
#include "WinCtrl.h"
#include "TButton.h"
#include "TScrollBarType.h"
#include "IScrollModel.h"
#include "TScrollBox.h"

class CTScrollBox;

//! Scrollbar
/*!
Its a scrollbar.
*/

class TGAMECTRL_API CTScrollBar : public CWinCtrl {
public:
	CTScrollBar();
	virtual ~CTScrollBar();

	virtual unsigned int Process(UINT uiMsg, WPARAM wParam, LPARAM lParam);
	virtual	void Update(POINT ptMouse);
	virtual void Draw();

	virtual void Show();
	virtual void Hide();

	virtual void SetOffset(POINT offset);
	virtual void MoveWindow(POINT pos);

	bool Create(int posX, int posY, int width, int height, int type = CTScrollBarType::VERTICAL);

	int GetExtent();
	int GetMaximum();
	RECT GetThumbMoveRange();

	void MoveEnd();
	void MoveHome();

	void SetModel(IScrollModel* model);
	void SetModelValue(int value);

	void SetNextButton(CTButton* button);
	void SetPrevButton(CTButton* button);

	void SetScrollBox(CTScrollBox* scrollbox);
	void SetValue(int value);

protected:
	CTButton* mPrevButton;
	CTButton* mNextButton;
	CTScrollBox* mScrollBox;
	IScrollModel* mScrollModel;
	CTScrollBarType* mScrollBarType;
};

#endif
