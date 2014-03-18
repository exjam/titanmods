#ifndef DLGPvP_H
#define DLGPvP_H

#include <ExLIB\List.hpp>
#include <TRose\Packet.h>
#include "Controls.h"
#include <TRose\QuestFunctions.h>

struct PvPGame;
struct PvPInstance;
extern char* gGameRank[];
int GetRank();

class CTPvP : public CTDialog, IObserver {
public:
	CTPvP();
	virtual ~CTPvP();
	virtual unsigned int Process(UINT uiMsg, WPARAM wParam, LPARAM lParam);
	virtual void Draw();
	virtual void Show();
	virtual void Update(CObservable* observable, CTObject* object) { }

	void InitGameList();

	enum {
		IID_BTN_CLOSE = 10,
		IID_BTN_ICONIZE = 11,
		IID_BTN_MINIMIZE = 113,
		IID_BTN_MAXIMIZE = 114,
		IID_BTN_GIVEUP = 50,
		IID_PANEL_TOP = 100,
		IID_LIST_TOP = 20,
		IID_SCROLL_TOP = 21,
		IID_PANEL_BOTTOM = 200,
		IID_LIST_BOTTOM = 30,
		IID_SCROLL_BOTTOM = 31,
	};

public:	
	bool mMinimized;
};

class CTPvPInstance : public CTDialog, IObserver {
public:
	CTPvPInstance();
	virtual ~CTPvPInstance();
	virtual unsigned int Process(UINT uiMsg, WPARAM wParam, LPARAM lParam);
	virtual void Draw();
	virtual void Show();
	virtual void Update(POINT ptMouse);	
	virtual void Update(CObservable* observable, CTObject* object){}
	virtual bool Create(const char* xmlFile);

	void SetData(PvPInstance* instance){ 
		mInstance = instance;
	}

	void UpdateWindow();

	enum {
		IID_BTN_CLOSE = 10,
		IID_BTN_RED = 11,
		IID_BTN_BLUE = 12,
		IID_BTN_JOIN = 13,
	};

	enum {
		GAME_STATUS_CLOSED = 0,
		GAME_STATUS_SIGNUP = 1,
		GAME_STATUS_FULL = 2,
		GAME_STATUS_BUSY = 3,
		GAME_STATUS_CANCEL = 4,
		GAME_STATUS_MAX = 5,
	};

public:	
	PvPInstance* mInstance;
	int mPrevStatus;
	CWinCtrl* mJoin;
	CWinCtrl* mRed;
	CWinCtrl* mBlue;
};

struct PvPGame {
	char* mName;
	char* mJoinRed;
	char* mJoinBlue;
	char* mCheckRed;
	char* mCheckBlue;
	char* mGiveUp;
	char* mQuestFlag;
	char* mJoinBattle;
	int mMaxPlayers;
	int mIcon;
	int mMapID;
	int mBossIcon;
	GameType mType;
	List<PvPInstance*>* mInstanceList;
};

struct PvPInstance {
	int mID;
	int mStatus;
	int mPlayersBlue;
	int mPlayersRed;
	int mScoreBlue;
	int mScoreRed;
	int mData[4];
	PvPGame* mGame;
	char* mCheckRed;
	char* mCheckBlue;
	char* mQuestFlag;
	bool mIsNewb;

	PvPInstance::PvPInstance(int id, PvPGame* parent){
		mID = id;
		mGame = parent;
		mStatus = 0;
		mPlayersBlue = 0;
		mPlayersRed = 0;
		mScoreBlue = 0;
		mScoreRed = 0;
		mData[0] = 0;
		mData[1] = 0;
		mData[2] = 0;
		mData[3] = 0;
		mIsNewb = (id == 4);
	}

	bool IsRed(){
		return ::QF_checkQuestCondition(String(mGame->mCheckRed).arg(mID).Str()) ? true : false;
	}

	bool IsBlue(){
		return ::QF_checkQuestCondition(String(mGame->mCheckBlue).arg(mID).Str()) ? true : false;
	}

	bool HasFlag(){
		return ::QF_checkQuestCondition(String(mGame->mQuestFlag).arg(mID).Str()) ? true : false;
	}
};

enum {
	NPC_SIGNUPS = 0,
	NPC_GAME = 1,
	BOSS_RED = 4,
	BOSS_BLUE = 5,
};

extern char* gGameStatus[];
extern List<PvPGame*>* gGameList;
extern bool gAllowPartChange;
extern char* gDuelModes[];

PvPInstance* HasGameQuest();
bool CanShowPVP();

#define FLAG_ING_HIDDEN			0x06000000

extern int gDuelCountdown;
extern clock_t gDuelStart;

#endif