#include "main.h"
#include "..\Shared\Code.hpp"
#include "..\Shared\RunOnLoad.hpp"

bool __stdcall CanDropItem(int slot, classUSER* user) {
	if(slot < 12 || slot >= 139) return false;

	CustomAvatarData* data = CustomAvatarData::Get(user);
	clock_t dt = clock() - data->mLastDropTime;
	if(dt < 500) return false;

	data->mLastDropTime = clock();
	return true;
}

static _declspec(naked) void ASMFixDrops(){
	static int jbad = 0x100859A7;
	static int jgood = 0x100856AA;

	_asm {
		PUSHAD
		MOV EAX,DWORD PTR SS:[EBP-0x10]		
		PUSH EAX	// User
		PUSH ECX	// Slot
		CALL CanDropItem
		TEST AL, AL
		JE bad
		POPAD
		JMP jgood
bad: 
		POPAD
		JMP jbad
	}
}

HookOnLoad(0x100855AA, ASMFixDrops, 0);
