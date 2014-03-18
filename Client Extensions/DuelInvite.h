#ifndef CTDUELINV_H
#define CTDUELINV_H

#include "Controls.h"
#include <TRose\RoseAPI.h>
#include <TRose\Game.h>
#include <TRose\IT_MGR.h>
#include <ExLIB\Array.hpp>
#include <ExLIB\List.hpp>
#include "..\Shared\Console.hpp"

class CTDuelInvite : public CTDialog, IObserver {
public:
	CTDuelInvite();
	virtual ~CTDuelInvite();
	virtual unsigned int Process(UINT uiMsg, WPARAM wParam, LPARAM lParam);
	virtual void Draw();
	virtual void Show();
	virtual void Update(POINT ptMouse);	
	virtual void Update(CObservable* observable, CTObject* object) { }
	virtual bool Create(const char* xmlFile);

	int GetNumber();

	enum {
		IID_BTN_EDITBOX = 11,
		IID_BTN_COMBOMODE = 14,
		IID_BTN_OK = 12,
		IID_BTN_CANCEL = 13,
	};
};

#endif