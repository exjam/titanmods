#ifndef ZLISTBOX_H
#define ZLISTBOX_H

#include "TGameCtrl.h"
#include "WinCtrl.h"
#include "IScrollModel.h"
#include <deque>

//! A ListBox with CWinCtrl based items
/*!
This class implements a ListBox which uses CWinCtrl based items,
if you are looking for a ListBox with text based items check out
CTListBox.
*/

class TGAMECTRL_API CZListBox : public CWinCtrl, IScrollModel {
public:
	CZListBox();
	virtual ~CZListBox();

	virtual unsigned Process(unsigned uiMsg, WPARAM wParam, LPARAM lParam);
	virtual void Update(POINT ptMouse);
	virtual void Draw();

	virtual void Show();
	virtual void Hide();
	virtual void MoveWindow(POINT pos);

	//Thank you Mr CZListBox for providing me
	//with IScrollModel functions
	virtual int GetValue();
	virtual int GetExtent();
	virtual int GetMaximum();
	virtual int GetMinimum();

	virtual void SetValue(int value);
	virtual void SetExtent(int extent);
	virtual void SetMaximum(int max);
	virtual void SetMinimum(int min);

	virtual RECT GetWindowRect();
	//and it not implements IsLastItemDrawn

	void Add(CWinCtrl* ctrl);
	void Clear();
	void SetSelected(int index);
	void DeselectAll();
	int GetSelectedItemIndex();
	CWinCtrl* GetItem(int index);
	void InsertItem(int index, CWinCtrl* ctrl);
	bool DelItem(int iIndex);
	bool DelItemByControlID(int id);
	int GetSize();

protected:
	int mValue;
	int mExtent;
	int mMaxSize;
	std_deque<CWinCtrl*> mItems;
};

#endif