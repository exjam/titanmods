#include "main.h"
#include <TRose\CObjMGR.h>
#include <TRose\CObjUSER.h>

bool __stdcall CanExecuteSkill(int skillSlot){
	CSkillSlot* pSkillSlot = ((CObjUSER*)CObjMGR::GetSelf())->GetSkillSlot();
	CSkill* pSkill = pSkillSlot->GetSkill(skillSlot);
	short skillID = pSkill->GetSkillIndex();

	return ((skillID >= 2404 && skillID <= 2425) || (skillID >= 2431 && skillID <= 2445) || (skillID >= 2451 && skillID <= 2465) ||
			(skillID >= 2471 && skillID <= 2485) || (skillID >= 2491 && skillID <= 2505) || (skillID >= 2511 && skillID <= 2525) ||
			(skillID >= 2531 && skillID <= 2540) || (skillID >= 2551 && skillID <= 2560) || (skillID >= 2571 && skillID <= 2580) ||
			(skillID >= 2591 && skillID <= 2617) || (skillID >= 2641 && skillID <= 2650) || skillID == 2621 || skillID == 2631);
}

void __declspec(naked) ASMCanExecuteSkill(){
	static int jRet = 0x0043F123;
	static int jPass = 0x0043F12A;
	_asm {
		PUSH ESI
		MOV ESI, ECX
		JNE SHORT jOut
		PUSHAD
		PUSH DWORD PTR DS:[ESI+0x4]
		CALL CanExecuteSkill
		CMP AL, 0x1
		JE jSuccess
		POPAD
		JMP jRet
jSuccess:
		POPAD
jOut:
		JMP jPass
	}
}

HookOnLoad(0x0043F11E, ASMCanExecuteSkill, 0);