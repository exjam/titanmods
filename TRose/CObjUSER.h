#ifndef CObjUSER_H
#define CObjUSER_H
#include "CUserData.h"
#include "CObjCHAR.h"
#include "SkillSlot.h"

class CObjUSER : public CObjAVT, public CUserDATA
{
public:
	CSkillSlot* GetSkillSlot() {
		return (CSkillSlot*)((unsigned char*)this + 0x163C);
	}
};

#endif