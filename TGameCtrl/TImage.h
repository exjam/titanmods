#ifndef CTIMAGE_H
#define CTIMAGE_H

#include "TGameCtrl.h"
#include "WinCtrl.h"

//! An image class
/*!
This is used to draw any image from the TSI files, use moduleID to specify which TSI group,
and graphicID to specify what graphic from that TSI file.
*/

class TGAMECTRL_API CTImage : public CWinCtrl {
public:
	CTImage();
	virtual ~CTImage();

	virtual unsigned int Process(UINT uiMsg, WPARAM wParam, LPARAM lParam);
	virtual void Update(POINT ptMouse);
	virtual void Draw();
	virtual void Draw(POINT pos);

	bool Create(int posX, int posY, int width, int height, int graphicID ,int moduleID);

	void SetImage(int graphicID, int moduleID);
	void SetBlinkImage(int graphicID, int moduleID);

	void SetBlink();
	void SetUnblink();
	void SetBlinkSwapTime(DWORD swap_time);

protected:
	int mModuleID;//0x70
	int mGraphicID;//0x74
	int mBlinkGraphicID;//0x78
	int mBlinkModuleID;//0x7C
	bool mBlink;//0x80
	bool mBlinkEnable;//0x81
	DWORD mBlinkSwapTime;//0x84
	DWORD mBlinkPrevSwapTime;//0x88
	int mBlinkCurrentGID;//0x8C
	int mBlinkCurrentMID;//0x90
};

#endif
