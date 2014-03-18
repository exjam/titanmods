#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

struct AchievementData {
	bool HasAchievement(int id){
		int bitID = id % 8;
		int byteID = id / 8;
		return (mData[byteID] >> bitID) & 1;
	}
	
	void SetAchievement(int id, bool has){
		int bitID = id % 8;
		int byteID = id / 8;
		if(!has){
			mData[byteID] &= !(1 << bitID);
		}else{
			mData[byteID] |= 1 << bitID;
		}
	}

	unsigned char mData[32];
};

enum AchievePakFlags {
	ACHIEVEMENT_LOAD = 1,
	ACHIEVEMENT_UNLOCKED = 2,
	MAX_ACHIEVEMENT_FLAGS = 3,
};

#define PAK_ACHIEVEMENT 0x605

#endif