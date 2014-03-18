#ifndef TLISTBOX_H
#define TLISTBOX_H

#include "TGameCtrl.h"
#include "WinCtrl.h"
#include "IScrollModel.h"
#include "ITFont.h"

//Shitty struct name from ROSE... xD
struct t_list_item {
	char mText[255];
	unsigned long mColour;
	bool mDrawn;
};

//! Listbox
/*!
A list box control using text for items
*/

class TGAMECTRL_API CTListBox : public CWinCtrl, public IScrollModel {
public:
	CTListBox();
	virtual ~CTListBox();

	virtual unsigned int Process(UINT uiMsg, WPARAM wParam, LPARAM lParam);
	virtual	void Update(POINT ptMouse);
	virtual void Draw();

	virtual int GetValue();
	virtual int GetExtent();
	virtual int GetMaximum();
	virtual int GetMinimum();

	virtual void SetValue(int value);
	virtual void SetExtent(int extent);
	virtual void SetMaximum(int max);
	virtual void SetMinimum(int min);

	virtual RECT GetWindowRect();
	virtual bool IsLastItemDrawn();

	bool Create(int posX, int posY, int width, int height, int maxline, int charWidth, int charHeight);
	
	void AppendText(char const* text, unsigned long colour, bool autoIncValue);
	void ClearText();
	void DeleteText(int index);
	short GetCharHeight();
	short GetCharWidthA();
	t_list_item GetItem(int index);
	short GetLineSpace();
	int GetMaxSize();
	char const* GetSelectedItem();
	short GetSelectedItemID();
	char const* GetText(int index);
	bool IsSelectable();
	bool ProcessSelectable(UINT uiMsg, WPARAM wParam, LPARAM lParam);
	void SetCharHeight(short height);
	void SetCharWidth(short width);
	void SetFont(int font);
	void SetLineSpace(short space);
	void SetMaxSize(int size);
	void SetSelectable(bool selectable);
	void SetSelectedItem(short index);
	void SetText(int index, char const* text, unsigned long colour);

protected:
	std_deque<t_list_item> mItems;//0x74
	short mValue;//0x88
	short mMaxLines;//0x8A
	short mMaxCharacters;//0x8C
	short mSelectedItem;//0x8E
	bool mSelectable;//0x90
	short mLineSpace;//0x92
	short mCharHeight;//0x94
	short mCharWidth;//0x96
	int mMaxSize;//0x98
	ITFont* mFontManager;//0x9C
	int mFont;//0xA0
};

#endif