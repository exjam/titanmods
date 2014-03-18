#ifndef CSkillSlot_H
#define CSkillSlot_H
#include "Skill.h"

class CSkillSlot
{
public:
	CSkill* GetSkill(short slotIndex) {
		return *(CSkill**)((unsigned char*)this + 4 * slotIndex);
	}
};

#endif