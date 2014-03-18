#include "main.h"

char* _stdcall FilterQuotes(char* pStr){
	if(!pStr) return NULL;

	char* src = pStr;
	while(*src){
		if(*src == '\'')
			*src = '`';

		++src;
	}

	return pStr;
}

void _declspec(naked) ASMQuotes(){ 
	static int jRetn = 0x10038863;
	_asm {
		POP EAX 

		PUSHAD
		PUSH EAX
		CALL FilterQuotes
		POPAD

		POP EDX
		POP EDI
		POP ESI
		POP EBX
		JMP jRetn
	}
}

HookOnLoad(0x1003885E, ASMQuotes, 0);
