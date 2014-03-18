#ifndef TEDITBOX_H
#define TEDITBOX_H

#include "TGameCtrl.h"
#include "WinCtrl.h"
#include "ITFont.h"

//! Editbox
/*!
A basic text box edit control
*/

class TGAMECTRL_API CTEditBox : public CWinCtrl {
public:
	CTEditBox();
	virtual ~CTEditBox();

	virtual unsigned int Process(UINT uiMsg, WPARAM wParam, LPARAM lParam);
	virtual void Draw();
	virtual void SetFocus(bool focus);
	virtual void Hide();
	virtual void Show();

	bool Create(int posX, int posY, int width, int height, int charWidth);
	void AddType(unsigned long type);
	void AppendText(char const* text);
	unsigned long GetType();
	void Insert(char const* text);
	bool IsTypeHideCursor();
	bool IsTypeNumber();
	bool IsTypePassword();
	void MoveEnd();
	bool OnChar(WPARAM wParam, LPARAM lParam);
	bool OnKeyDown(WPARAM wParam, LPARAM lParam);
	void SetCharHeight(int height);
	void SetLimitText(int limit);
	void SetMultiline(bool multiline);
	void SetText(char const* text);
	void SetTextAlign(int align);
	void SetTextColor(int colour);
	void SetType(unsigned long type);
	bool chk_number(char const* text);
	void clear_text();
	void delete_one_char(int type);
	char* get_text();

public:
	enum Type {
		NONE = 0,
		NUMBER = 1,
		PASSWORD = 2,
		HIDECURSOR = 4,
	};

	enum Align {
		LEFT,
		CENTER,
		RIGHT,
	};

protected:
	int mMaxLength;//0x70
	int mCharWidth;//0x74
	int mCharHeight;//0x78
	bool mShowCursor;//0x7C
	bool mMultiline;//0x7D
	int mTextAlign;//0x80
	int mTextColour;//0x84
	unsigned long mType;//0x88
	ITFont* mFontManager;//0x8C
	int mCursorPos;//0x90
	int mScrollPos;//0x94
	char* mBuffer;//0x98
	int mUnknown9C;//0x9c wut wut wut
	int mFont;//0xA0
};

#endif