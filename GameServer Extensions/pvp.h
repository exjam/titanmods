#ifndef PVP_H
#define PVP_H

#include "main.h"

enum {
	PVP_CANT = 0,
	PVP_PERMITION_ALL = 1,
	PVP_NON_PARTY_ALL = 2,
	PVP_AGIT = 11,
};

// Flag status for UI update
void _stdcall SendFlagData(CGameOBJ* pEVENT);
void SendFlagDataToPlayer(classUSER* pUSER, int ZoneNO);

// PvP Vars for PvP Window
void __stdcall Send_PvP_Vars_Login(classUSER* pUser);

// Custom player data
void _stdcall SendPlayerDATA(CGameOBJ* pObj1, CGameOBJ* pObj2);
void _stdcall SendPlayerToZone(classUSER* pPlayer);

// Duel
classUSER* GetDuelEnemy(classUSER* player);
bool AreDuelling(CGameOBJ* char1, CGameOBJ* char2);
void EndDuel(classUSER* winner, classUSER* loser, int method);
void LogDuel(int type, classUSER* winner, classUSER* loser, int bet);

struct NpcCmd {
	NpcCmd(unsigned int game, unsigned int instance, bool score, unsigned int npc, unsigned int zone = 0)
		: mGame(game), mInstance(instance), mScore(score), mNpc(npc), mZone(zone)
	{
	}

	unsigned int mGame;
	unsigned int mInstance;
	bool mScore;
	unsigned int mNpc;
	unsigned int mZone;
};

struct PvPPlayer {
	PvPPlayer() : mIP(0), mTeam(0), mID(0) {}
	~PvPPlayer(){
		if(mIP)
			delete [] mIP;
	}

	char* mIP;
	int mTeam;
	int mID;
};

class PvPQuest {
public:
	PvPQuest(int q1, int q2, int sw, char* pre, int inst, int npc)
		: mQuest1(q1), mQuest2(q2), mSwitch(sw), mNPC(npc)
	{
		mQuitRed = StrToHashKey(String("%1-%2-RedC").arg(pre).arg(inst));
		mQuitBlue = StrToHashKey(String("%1-%2-BlueC").arg(pre).arg(inst));
		mJoinRed = StrToHashKey(String("%1-%2-Red").arg(pre).arg(inst));
		mJoinBlue = StrToHashKey(String("%1-%2-Blue").arg(pre).arg(inst));
		mGiveUpRed = StrToHashKey(String("C%1-%2-RedC").arg(pre).arg(inst));
		mGiveUpBlue = StrToHashKey(String("C%1-%2-BlueC").arg(pre).arg(inst));
	}

public:
	int mNPC;
	int mQuest1;
	int mQuest2;
	int mSwitch;
	unsigned int mQuitRed;
	unsigned int mQuitBlue;
	unsigned long mJoinRed;
	unsigned long mJoinBlue;
	unsigned long mGiveUpRed;
	unsigned long mGiveUpBlue;
	Array<PvPPlayer*> mPlayers;
};

extern Array<NpcCmd*> gNpcVars;
extern Array<PvPQuest*> gPvPQuests;

struct MotionValue {
	union {
		WORD m_wValue;
		struct {
			WORD m_wETC : 15;
			WORD m_wIsSTOP :  1;
		};
	};
};

void ClearPvpIpList(int NpcID);

#endif