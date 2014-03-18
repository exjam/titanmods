#include "main.h"

void LoadAllOptions(){
	gOptions.mFontSize = GetPrivateProfileInt("VIDEO", "FONT", 1, gConfig);
	gOptions.mAntiAliasingEnable = GetPrivateProfileInt("VIDEO", "ANTIALIASING", 0, gConfig);
	gOptions.mQuestIconEnable = GetPrivateProfileInt("VIDEO", "QUESTICONS", 1, gConfig);
	gOptions.mFarZoom = GetPrivateProfileInt("VIDEO", "FARZOOM", 0, gConfig);
	gOptions.mAllowDuel = GetPrivateProfileInt("VIDEO", "DUEL", 1, gConfig);
	gOptions.mSkillBarEnable = GetPrivateProfileInt("QUICKBAR2", "ENABLED", 0, gConfig) ? 1 : 0;

	SetFont(9 + gOptions.mFontSize);

	if(gOptions.mAntiAliasingEnable){
		setFullSceneAntiAliasing(2);
		resetScreen();
	}

	if(gOptions.mFarZoom)
		ApplyZoom(true);

	char usernameKeys[1024];
	int readSize = 0;
	int totalSize = GetPrivateProfileString("USERNAMES", NULL, NULL, usernameKeys, sizeof(usernameKeys), gConfig);

	while(true){
		if(readSize >= totalSize)
			break;

		char* username = new char[35];
		GetPrivateProfileString("USERNAMES", &usernameKeys[readSize], "Username", username, 35, gConfig);
		gOptions.mUsernames.push_back(username);

		readSize += strlen(&usernameKeys[readSize]) + 1;
	}
}

static _declspec(naked) void ASMLoadOption(){
	static int ca1 = 0x0041CB90;
	static int jmpYay = 0x0041E908;
	_asm {
		CALL ca1
		CALL LoadAllOptions
		JMP jmpYay
	};
}

HookOnLoad(0x0041E903, ASMLoadOption, 0);