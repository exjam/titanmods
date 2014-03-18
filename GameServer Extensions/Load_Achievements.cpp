#include "main.h"
#include "..\Shared\RunOnLoad.hpp"
#include "CustomAvatarData.h"
#include <SHO_GS\classODBC.h>
#include <SHO_GS\classPACKET.h>
#include <SHO_GS\CPacket.h>
#include <SHO_GS\classUSER.h>
#include <SHO_GS\CObjNPC.h>
#include <SHO_GS\CZoneTHREAD.h>
#include <SHO_GS\CZoneLIST.h>

void __stdcall OnCharacterLoad(classODBC* odbc, classUSER* user){
	CustomAvatarData* data = CustomAvatarData::Get(user);
	unsigned char* achieveData = odbc->GetDataPTR(0x18);
	if(!achieveData)
		memset(data->mAchievements.mData, 0, 32);
	else
		memcpy_s(data->mAchievements.mData, 32, achieveData, 32);

	classPACKET* cpak = Packet_AllocNLock();
	if(!cpak) return;

	CPacket* pak = (CPacket*)cpak;
	pak->CreateNew(PAK_ACHIEVEMENT);
	pak->Add<char>(ACHIEVEMENT_LOAD);
	pak->Add<AchievementData>(data->mAchievements);
	user->SendPacket(cpak);
	Packet_ReleaseNUnlock(cpak);
}

void __declspec(naked) ASMLoadAvatarSQL(){
	static int retAddr = 0x10097F81;
	_asm {
		MOV EAX,DWORD PTR SS:[EBP-0x20]
		MOV ECX, DWORD PTR SS:[EBP-0x4]
		MOV ECX, DWORD PTR DS:[ECX+0x14]
		PUSH EAX
		PUSH ECX
		CALL OnCharacterLoad
		PUSH 0x14
		MOV EDX, DWORD PTR SS:[EBP-0x4]
		JMP retAddr
	};
}

HookOnLoad(0x10097F7C, ASMLoadAvatarSQL, 0);