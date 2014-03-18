#include "main.h"
#include <TRose\BuffTooltipHook.h>

class BuffTimeRemaining {
public:
	BuffTimeRemaining(){
		BuffTooltipHook::Apply(&AlterBuffToolTip);
	}

	static void __stdcall AlterBuffToolTip(Tooltip* tooltip, int buffRemainTime){
		char text[32];

		buffRemainTime /= 1000;
		if(buffRemainTime < 0) 
			buffRemainTime = 0;

		if(buffRemainTime > 60){
			int mins = buffRemainTime / 60;
			sprintf_s(text, 32, "%im %is", mins, buffRemainTime - (mins*60));			
		}else
			sprintf_s(text, 32, "%is", buffRemainTime);

		tooltip->AddString(text);
	}

};

BuffTimeRemaining gBuffTimeRemaining;