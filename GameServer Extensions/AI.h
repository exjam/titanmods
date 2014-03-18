#ifndef CUSTOMAI_H
#define CUSTOMAI_H

#include "main.h"

#include <SHO_GS\classUSER.h>
#include <SHO_GS\classPACKET.h>
#include <SHO_GS\CPacket.h>
#include <SHO_GS\CObjNPC.h>
#include <SHO_GS\CObjEVENT.h>
#include <SHO_GS\CObjCHAR.h>
#include <SHO_GS\CZoneTHREAD.h>
#include <SHO_GS\CZoneLIST.h>
#include <SHO_GS\CLIB_GameSRV.h>

enum {
	GAME_STATUS_CLOSED,
	GAME_STATUS_SIGNUP,
	GAME_STATUS_FULL,
	GAME_STATUS_PROGRESS,
	GAME_STATUS_CANCEL,
};

enum {
	FLAG_HIDE,
	FLAG_SHOW,
};

enum {
	VAR_STATUS,
	VAR_SCORE_RED,
	VAR_SCORE_BLUE,
	VAR_3,
	VAR_4,
	VAR_PLAYERS_RED,
	VAR_PLAYERS_BLUE,
	VAR_WINNER,
};

enum {
	TEAM_NULL,
	TEAM_RED,
	TEAM_BLUE,
};

class CustomAI {
public:	
	CustomAI(short map){
		mDoShout = 0;
		mLastExec = 0;
		mMap = map;
	}

	~CustomAI(){}

	virtual void DoAI() { 
		Log(MSG_INFO, "DoAI - Not supposed to be called!");
	}

	virtual void Execute(short ZoneNO){ 
		if(mMap != ZoneNO) return;
		if((clock() - mLastExec) < 3000) return;

		DoAI();
		mLastExec = clock();
	}

public:
	int mDoShout;
	clock_t mLastExec;
	short mMap;
};

class CtfAI : public CustomAI {
public:
	CtfAI(int id, int zone, int npc, int qred, int qblue, int open, int cancel, int over, int cleanup)
		: CustomAI(zone), mID(id), mZone(zone), mNPC(npc), mQuestRed(qred), mQuestBlue(qblue),
		  mTimeOpen(open), mTimeOver(over), mTimeCancel(cancel), mTimeCleanup(cleanup)
	{
	}

	virtual void DoAI();

protected:
	int mID;
	int mNPC;
	int mZone;

	int mQuestRed;
	int mQuestBlue;

	int mTimeOpen;
	int mTimeOver;
	int mTimeCancel;
	int mTimeCleanup;
};

class KothAI : public CustomAI {
public:
	KothAI(int zone, int npc, int quest, int cleanup, int open, int cancel, int over)
		: CustomAI(zone), mNPC(npc), mQuest(quest), mZone(zone), mTimeCleanup(cleanup),
		  mTimeOpen(open), mTimeCancel(cancel), mTimeOver(over)
	{
	}

	virtual void DoAI();

protected:
	int mNPC;
	int mZone;
	int mQuest;
	int mTimeCleanup;
	int mTimeOpen;
	int mTimeCancel;
	int mTimeOver;
};

void RunAIP(short ZoneNO);
void InitVarList();
void CleanAllPvpNpcs();

#endif
