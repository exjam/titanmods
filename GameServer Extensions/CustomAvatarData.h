#ifndef CUSTOM_AVATAR_DATA_H
#define CUSTOM_AVATAR_DATA_H

#include <SHO_GS\classUSER.h>
#include <SHO_GS\CObjAvt.h>
#include <time.h>
#include "..\Shared\Console.hpp"
#include "..\Shared\AchievementData.hpp"

class CustomAvatarData {
public:
	CustomAvatarData() {
		mLastCheck = 0;
		mPartyListUpdate = 0;
		mLastDropTime = 0;
		mLastShout = 0;
		mShopOPEN = 0;
		cDeadTrigger = false;
		cKilledTrigger = false;
		mData.mCtfFlag = 0;
		mData.mGameTeam = 0;
		mData.mScale = 1.0f;
		mChkAchvIdx = 0;

		memset(mKilledClasses, 0, sizeof(byte)*8);
	}

	~CustomAvatarData(){}

	static CustomAvatarData* Get(CGameOBJ* pObj){
		classUSER* pUSER = static_cast<classUSER*>(pObj);

		int* val = (int*)(((char*)pUSER) + 0x2A40);
		CustomAvatarData* data = (CustomAvatarData*)*val;
		if(!data){
			data = new CustomAvatarData();
			*val = (int)data;		
		}

		return data;
	}

	bool cDeadTrigger;
	bool cKilledTrigger;
	clock_t mPartyListUpdate;
	clock_t mLastCheck;
	clock_t mLastDropTime;
	clock_t mLastShout;
	clock_t mShopOPEN;
	NewData mData;
	byte mKilledClasses[8];
	AchievementData mAchievements;
	unsigned long LotteryTickets;

	unsigned int mChkAchvIdx;
	DuelData pDuel;
};

#endif

/*
127b * 160 000 = 20 320 000b
 20,320,000 .......... bytes
     19,843.75 ....... kilobytes
         19.3786621093 megabytes
*/