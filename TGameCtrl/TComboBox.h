#ifndef TCOMBOBOX_H
#define TCOMBOBOX_H

#include "TGameCtrl.h"
#include "WinCtrl.h"
#include "TButton.h"
#include "TListBox.h"
#include "TImage.h"
#include "ITFont.h"
#include "TListBox.h"

//! Combobox
/*!
A combobox control, this one supports text based items
*/

class TGAMECTRL_API CTComboBox : public CWinCtrl {
public:
	CTComboBox();
	virtual ~CTComboBox();

	virtual unsigned int Process(UINT uiMsg, WPARAM wParam, LPARAM lParam);
	virtual void Update(POINT ptMouse);
	virtual void Draw();

	virtual void Show();
	virtual void Hide();
	virtual void SetOffset(POINT offaet);
	virtual void MoveWindow(POINT pt);
	virtual void OwnerDraw();

	bool Create(int posX, int posY, int width, int height);
	
	void AddItem(char* item);
	void ClearItem();
	void DrawDropBoxImage();
	void DrawSelectedItem();
	CTListBox* GetListBox();
	char const* GetSelectedItem();
	short GetSelectedItemID();
	bool IsShowDropBox();
	void SetButton(CTButton* button);
	void SetImage(CTImage* top, CTImage* middle, CTImage* bottom);
	void SetListBox(CTListBox* listbox);
	void SetSelectedItem(short index);
	void ToggleShowDropBox();
	
protected:
	ITFont* mFontMgr;//0x70
	CTButton* mButton;//0x74
	CTImage* mTopImage;//0x78
	CTImage* mMiddleImage;//0x7C
	CTImage* mBottomImage;//0x80
	CTListBox* mListBox;//0x84
};
#endif