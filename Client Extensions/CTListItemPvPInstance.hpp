#ifndef CTLISTINST_H
#define CTLISTINST_H

#include "PvP.h"
#include <TRose\RoseAPI.h>
#include <TRose\Game.h>
#include <TRose\IT_MGR.h>
#include <ExLIB\Array.hpp>
#include <ExLIB\List.hpp>
#include "..\Shared\Console.hpp"

class CTListItemPvPInstance : public CWinCtrl {
public:
	CTListItemPvPInstance(PvPInstance* instance);
	virtual ~CTListItemPvPInstance();
	virtual unsigned int Process(UINT uiMsg, WPARAM wParam, LPARAM lParam);
	virtual	void Draw();
	virtual void Update(CObservable* observable, CTObject* object);

public:	
	PvPInstance* mInstance;
};

#endif