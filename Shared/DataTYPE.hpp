#ifndef DATATYPE_H
#define DATATYPE_H

struct tagPartITEM {
	unsigned int m_nItemNo : 10;
	unsigned int m_nGEM_OP : 9;
	unsigned int m_bHasSocket : 1;
	unsigned int m_cGrade : 4;
};

struct NewData {
	unsigned char mCtfFlag;
	unsigned char mGameTeam;
	unsigned char mPvPRank;
	float mScale;
	tagPartITEM mHelmet;
	tagPartITEM mArmor;
	tagPartITEM mGauntlet;
	tagPartITEM mBoots;
	tagPartITEM mBack;
	int mDuelEnemy;
	float mDuelCenterX;
	float mDuelCenterY;
};

struct DuelData {
public:
	void DuelData::Reset(){
		mRequestID = 0;
		mZulie = 0;
		mScore = 0;
		mMode = 0;
		mInDuel = false;
		mIsDead = false;
		mCenterX = 0.0f;
		mCenterY = 0.0f;
	}

	DuelData(){
		Reset();
	}

	int mRequestID;
	int mZulie;
	int mScore;
	int mMode;
	bool mInDuel;
	bool mIsDead;
	float mCenterX;
	float mCenterY;
};

struct CPartyData {
	short mPartyLevel;
	short mZoneNO;
	int mAverageLevel;
	int mMemberCount;
	char* mLeaderName;
};

enum GameType {
	DRAGON_HUNT,
	CONQUEST,
	CTF,
	KOTH,
};

#ifndef _LIB

struct AllVARS {
	AllVARS(unsigned int game, unsigned int instance, bool score, int npc);

	unsigned int mScore;
	unsigned int mGame;
	unsigned int mInstance;
	short mValues[10];
};

struct OneVAR {
	OneVAR(byte game, byte instance, bool score, short variable, short value){
		mGame = game;
		mInstance = instance;
		mSignupOrScore = score ? 1 : 0;
		mVariable = variable;
		mValue = value;
	}

	byte mSignupOrScore;
	byte mGame;
	byte mInstance;
	short mVariable;
	short mValue;
};

#endif
#endif