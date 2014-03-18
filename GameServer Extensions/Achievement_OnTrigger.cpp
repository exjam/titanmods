#include "main.h"
#include "Achievements.h"
#include "CustomAvatarData.h"

void __stdcall OnQuestTrigger(classUSER* user, unsigned int hash, int result){
	if(result != 5) return;
	AchievementOnTrigger(user, hash, result);
}

void __declspec(naked) ASMOnQuestTrigger(){
	static int retAddr = 0x1007C856;
	_asm {
		MOV EAX, DWORD PTR DS:[ESP+0x4]
		MOV EDX, DWORD PTR DS:[ESP+0xC]
		PUSH ECX
		PUSH EAX
		PUSH EDX
		PUSH ECX
		CALL OnQuestTrigger
		POP ECX

		PUSH EBP
		MOV EBP, ESP
		SUB ESP, 0x8
		JMP retAddr
	}
}

HookOnLoad(0x1007C850, ASMOnQuestTrigger, 1);