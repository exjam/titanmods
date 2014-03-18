#ifndef CSkill_H
#define CSkill_H
#include <Shared/Templates.hpp>

class CSkill
{
public:
	short GetSkillIndex() {
		return CallMemberFunction<CSkill, short>(0x004448E0, this);  
	}
};

#endif