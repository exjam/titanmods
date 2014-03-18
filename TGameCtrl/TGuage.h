#ifndef TGUAGE_H
#define TGUAGE_H

#include "TGameCtrl.h"
#include "WinCtrl.h"
#include "ITFont.h"
#include "ITDraw.h"

class TGAMECTRL_API CTGuage : public CWinCtrl {
public:
	CTGuage();
	virtual ~CTGuage();

	virtual void Draw();

	bool Create(int posX, int posY, int width, int height, int guageImgID, int backImgID, int moduleID);
	char const* GetText();
	int GetValue();
	void SetGuageImageID(int imageID);
	void SetText(char const* text);
	void SetValue(int value);

protected:
	int mBGImageID;//0x70
	int mGuageImageID;//0x74
	int mModuleID;//0x78
	std_string mText;//0x7C
	int mValue;//0x98
	ITFont* mFontImpl;//0x9C
	ITDraw* mDrawImpl;//0xA0
};

#endif