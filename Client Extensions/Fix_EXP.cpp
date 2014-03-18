#include "main.h"

int GetNewExp(int level){
	if(level > 210)
		level = 210;

	if(level <= 15)
		return (int)(((level + 3) * (level + 5) * (level + 10) * 0.7f));

	if(level <= 60)
		return (int)(((level - 5) * (level + 2) * (level + 2) * 2.2f));

	if(level <= 113)
		return (int)(((level - 11) * level * (level + 4) * 2.5f));

	if(level <= 150)
		return (int)(((level - 31) * (level - 20) * (level + 4) * 3.8f));
	
	if(level <= 178)
		return (int)(((level - 67) * (level - 20) * (level - 10) * 6.f));

	if(level <= 198)
		return (int)(((level - 67) * (level - 20) * (level - 10) * (level - 172)));

	return (int)((level - 67) * (level - 24) * (level - 22) * (level - 150) - 25440);
}


void __declspec(naked) ASMExpCalculator(){
	_asm {
		JMP GetNewExp
	};
}

HookOnLoad(0x004D8D20, ASMExpCalculator, 20);