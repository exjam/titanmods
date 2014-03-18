#ifndef TCAPTION_H
#define TCAPTION_H

#include "TGameCtrl.h"
#include "WinCtrl.h"
#include "TImage.h"
#include "TButton.h"

//! Caption for Dialogs
/*!
A caption control which allows dragging of dialogs and setting icons and buttons 
*/

class TGAMECTRL_API CTCaption : public CWinCtrl {
public:
	CTCaption();
	virtual ~CTCaption();

	virtual unsigned int Process(UINT uiMsg, WPARAM wParam, LPARAM lParam);
	virtual	void Update(POINT ptMouse);
	virtual void Draw();
	virtual void Hide();
	virtual void MoveWindow(POINT pos);

	bool Create(int posX, int posY, int width, int height);
	bool IsClicked();

	void SetString(const char* string);

	void SetIcon(CTImage* image);
	void SetImage(CTImage* image);
	void SetCloseButton(CTButton* button);
	void SetIconButton(CTButton* button);

public:
	bool mClicked;//0x70
	std_string	mTitle;//0x74
	CTImage* mIcon;//0x90
	CTImage* mImage;//0x94
	CTButton* mCloseButton;//0x98
	CTButton* mIconButton;//0x9C
};

#endif
