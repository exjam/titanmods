/*#include "main.h"
#include "..\Shared\Code.hpp"
#include "..\Shared\RunOnLoad.hpp"

_declspec(naked) void ASMPointShop(){
	static int Jmp_Normal = 0x0045D2C8;
	static int Jmp_PointShop = 0x0045D2F6;
	_asm {		
		MOVSX EDX,BYTE PTR DS:[EDX+0x555]
		CMP ECX, 0x0A
		JE lblPointShop
		JMP Jmp_Normal
lblPointShop:		
		JMP Jmp_PointShop
	};
}

HookOnLoad(0x0045D2C1, ASMPointShop, 2);
*/
