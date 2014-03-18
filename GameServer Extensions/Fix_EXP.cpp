#include "main.h"
#include "..\Shared\Code.hpp"
#include "..\Shared\RunOnLoad.hpp"
/*
Level 1-15 ::(Level+10)*(level+5)*(Level+3)*0,7
Level 16-60 ::(Level-5)*(Level+2)*(level+2)*2,2
Level 61-113 ::(Level-11)*(Level+0)*(Level+4)*2,5
114-150 ::(Level-31)*(Level-20)*(Level+4)*3,8
151-178 ::(Level-67)*(Level-20)*(Level-10)*6
179-198 ::(Level-67)*(Level-20)*(Level-10)*(Level-172)
199-210 ::(Level-67)*(level-24)*(Level-22)*(Level-150)-25440
*/

int GetNewExp(int level){
	if(level > 210)
		level = 210;

	if(level <= 15)
		return (int)((level + 3) * (level + 5) * (level + 10) * 0.7f);
	
	if(level <= 60)
		return (int)((level - 5) * (level + 2) * (level + 2) * 2.2f);
	
	if(level <= 113)
		return (int)((level - 11) * (level) * (level + 4) * 2.5f);
	
	if(level <= 150)
		return (int)((level - 31) * (level - 20) * (level + 4) * 3.8f);
	
	if(level <= 178)
		return (level - 67) * (level - 20) * (level - 10) * 6;
	
	if(level <= 198)
		return (level - 67) *(level - 20) * (level - 10) * (level - 172);
	
	return (level - 67) * (level - 24) *(level - 22) * (level - 150) - 25440;
}

HookOnLoad(0x1005D0A0, GetNewExp, 20);
