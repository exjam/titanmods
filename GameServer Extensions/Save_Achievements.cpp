#include "main.h"
#include "..\Shared\RunOnLoad.hpp"
#include "CustomAvatarData.h"
#include <SHO_GS\classODBC.h>

unsigned char increasedArgLength[] = { 0x18, 0x01 };

void __stdcall SaveAvatarSQL(classODBC* odbc, classUSER* user){
	CustomAvatarData* data = CustomAvatarData::Get(user);
	odbc->BindPARAM(0x0A, data->mAchievements.mData, 32);
}

void __declspec(naked) ASMSaveAvatarSQL(){
	static int retAddr = 0x100945F1;
	static const char* achieveStr = ",binAchievement=";
	_asm {
		MOV ECX,DWORD PTR SS:[EBP-0x4]
		MOV ECX,DWORD PTR DS:[ECX+0x14]
		MOV EAX,DWORD PTR SS:[EBP+0x8]
		//ADD EAX, 0xA0
		PUSH EAX
		PUSH ECX
		CALL SaveAvatarSQL
		/*Custom Parameters Start*/
			PUSH 6
			PUSH 0x0A
			PUSH 5
			PUSH achieveStr
		/*Custom Parameters End*/
		PUSH 6
		PUSH 9
		PUSH 5
		JMP retAddr
	}
}

HookOnLoad(0x100945EB, ASMSaveAvatarSQL, 1);
WriteOnLoad(0x10094662, increasedArgLength, 2);