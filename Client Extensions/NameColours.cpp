#include "main.h"
#include "PvP.h"
#include <TRose\NameColourHook.h>
#include <TRose\CGameOBJ.h>

class NameColours {
public:
	NameColours(){
		NameColourHook::Apply(&GetNameColour);
	}

	static int __stdcall GetNameColour(CGameOBJ* player, int curColour){
		if(!player) return curColour;

		if(!CanShowPVP()){
			int GameTeam = player->GetGameTeam();
			if(GameTeam == 1){
				return 0xFFFF0000;
			}else if(GameTeam == 2){
				return 0xFF0078FF;
			}else {
				return 0xFFFFFFFF;
			}
		}

		if(curColour == 0xFFFF0000)
			return curColour;//PvP red

		const char* name = player->GetName();
		if(!name) return curColour;

		if(strncmp(name, "[GM]", 4) == 0 || strncmp(name, "[DEV]", 5) == 0)
			return 0xFF0078FF;

		if(player->GetLevel() == 210)
			return 0xFFF28A36;

		return curColour;
	}
};

NameColours gNameColours;