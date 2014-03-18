#ifndef JTABLE_H
#define JTABLE_H

#include "TGameCtrl.h"
#include "WinCtrl.h"
#include "IScrollModel.h"

class TGAMECTRL_API CJTable :	public CWinCtrl, public IScrollModel {
public:
	CJTable();
	virtual ~CJTable();

	virtual void Draw();
	virtual void Update(POINT ptMouse);
	virtual unsigned int Process(unsigned uiMsg, WPARAM wParam, LPARAM lParam);
	virtual void MoveWindow(POINT pos);

	virtual int GetValue();
	virtual int GetExtent();
	virtual int GetMaximum();
	virtual int GetMinimum();

	virtual void SetValue(int value);
	virtual void SetExtent(int extent);
	virtual void SetMaximum(int maximum);
	virtual void SetMinimum(int minimum);

	virtual RECT GetWindowRect();
	
	void Add(CWinCtrl* ctrl);

	CWinCtrl* GetItem(int index);

	int GetSelectedItemID();

	void SetColumnCount(int count);

	void SetCellHeight(int height);
	void SetCellWidth(int width);

	void SetColMargin(int margin);
	void SetRowMargin(int margin);

private:
	//data time!
	//0x70 = from IScrollModel
	int mValue;//74
	int mExtent;//78
	int mColumnCount;//7C
	int mCellWidth;//80
	int mCellHeight;//84
	int mRowMargin;//88
	int mColMargin;//8C
	int mSelectedItemID;//90
	char unk[0x20];//now 0x20 more bytes, probable some sort of container check Add(CWinCtrl* ctrl);!
};

#endif