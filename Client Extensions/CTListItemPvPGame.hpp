#ifndef CTLISTGAME_H
#define CTLISTGAME_H

#include "PvP.h"
#include <TRose\RoseAPI.h>
#include <TRose\Game.h>
#include <TRose\IT_MGR.h>
#include <ExLIB\Array.hpp>
#include <ExLIB\List.hpp>
#include "..\Shared\Console.hpp"

PvPGame* InitDragonHunt(int instances);
PvPGame* InitCTF(int instances);
PvPGame* InitConquest(int instances);
PvPGame* InitKOTH(int instances);

class CTListItemPvPGame : public CWinCtrl {
public:
	CTListItemPvPGame(GameType gameType);
	virtual ~CTListItemPvPGame();
	virtual unsigned int Process(UINT uiMsg, WPARAM wParam, LPARAM lParam);
	virtual	void Draw();
	virtual void Update(CObservable* observable, CTObject* object);

public:	
	PvPGame* mGame;
};

#endif