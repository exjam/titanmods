#include "main.h"
#include "SkillBar2.h"

#include <TRose/SaveConfigHook.h>

class SaveConfig {
public:
	SaveConfig(){
		SaveConfigHook::Apply(&Save);
	}

	static void __stdcall Save(){
		char temp[512] = { 0 };

		if(gOptions.mSkillBarX == 0 && gOptions.mSkillBarY == 0){
			if(gOptions.mSkillBarType == 0) {
				gOptions.mSkillBarX = 400;
				gOptions.mSkillBarY = getScreenHeight() - 128;
			}else{
				gOptions.mSkillBarX = 400;
				gOptions.mSkillBarY = getScreenHeight() - 464;
			}
		}

		_itoa_s(gOptions.mSkillBarEnable, temp, 10);
		WritePrivateProfileString("QUICKBAR2", "ENABLED", temp, gConfig);
		_itoa_s(gOptions.mSkillBarPage, temp, 10);
		WritePrivateProfileString("QUICKBAR2", "PAGE", temp, gConfig);
		_itoa_s(gOptions.mSkillBarType, temp, 10);
		WritePrivateProfileString("QUICKBAR2", "TYPE", temp, gConfig);
		_itoa_s(gOptions.mSkillBarX, temp, 10);
		WritePrivateProfileString("QUICKBAR2", "X", temp, gConfig);
		_itoa_s(gOptions.mSkillBarY, temp, 10);
		WritePrivateProfileString("QUICKBAR2", "Y", temp, gConfig);

		_itoa_s(gOptions.mFontSize, temp, 10 );
		WritePrivateProfileString("VIDEO", "FONT", temp, gConfig);
		_itoa_s(gOptions.mAntiAliasingEnable, temp, 10);
		WritePrivateProfileString("VIDEO", "ANTIALIASING", temp, gConfig);
		_itoa_s(gOptions.mQuestIconEnable, temp, 10);
		WritePrivateProfileString("VIDEO", "QUESTICONS", temp, gConfig);
		_itoa_s(gOptions.mFarZoom, temp, 10);
		WritePrivateProfileString("VIDEO", "FARZOOM", temp, gConfig);
		_itoa_s(gOptions.mAllowDuel, temp, 10);
		WritePrivateProfileString("VIDEO", "DUEL", temp, gConfig);

		int usernameID = 1;

		for(List<char*>::Iterator username = gOptions.mUsernames.begin(); username != gOptions.mUsernames.end(); ++username) {
			WritePrivateProfileString("USERNAMES", String("Username%1").arg(usernameID), *username, gConfig);
			usernameID++;
		}
	}
};

SaveConfig gSaveConfig;