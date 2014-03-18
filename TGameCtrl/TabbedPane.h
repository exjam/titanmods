#ifndef TABBEDPANE_H
#define TABBEDPANE_H

#include "TGameCtrl.h"
#include "WinCtrl.h"

class CTRadioButton;
class CTButton;
class CJContainer;

//! Tabbed Pane
/*!
Bog standard tabbed pane control
*/

class TGAMECTRL_API CTabbedPane : public CWinCtrl {
public:
	CTabbedPane();
	virtual ~CTabbedPane();

	virtual unsigned int Process(UINT uiMsg, WPARAM wParam, LPARAM lParam);
	virtual	void Update(POINT ptMouse);
	virtual	void Draw();
	virtual void Show();
	virtual void Hide();
	virtual void MoveWindow(POINT pos);
	virtual bool IsInside(int x, int y);

	unsigned int AddTab(CTRadioButton* button, CJContainer* tab);
	int GetSelectedIndex();
	CJContainer* GetTabContainer(int id);
	bool IsMinimize();
	void RemoveAll();
	void SetMinimize(bool minimise);
	void SetMinimizeButton(CTButton* button);
	void SetMinimizeRect(const RECT& rect);
	bool SetSelectedIndex(unsigned int index);

protected:
	unsigned char unk[0x14];//0x14 is sizeof vector btw
	bool mMinimise;//0x84
	RECT mMinimiseRect;//0x88
};

#endif