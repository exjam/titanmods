#include "main.h"

bool __stdcall ValidIP(char* ipAddress){
#ifdef TEST_SERVER
	return true;
#else
if(!strcmp(ipAddress, "127.0.0.1"))
	return true;
#endif
	return false;
}

void __declspec(naked) ASMCheckConnectIP(){
	static int jmpRet = 0x00499D50;
	static int callConnect = 0x004EFCC0;

	_asm {
		PUSHAD

		MOV EAX,DWORD PTR DS:[0x693504]
		MOV ECX,DWORD PTR DS:[EAX+0xDC]
		PUSH ECX
		CALL ValidIP
		TEST AL, AL
		JE Bad

		POPAD

		PUSH 1
		PUSH EDX
		PUSH ECX
		MOV ECX,DWORD PTR DS:[0x699920]
		CALL callConnect
		JMP jmpRet
Bad:
		POPAD

		MOV AL, 0
		JMP jmpRet
	}
}

#ifndef DEBUG_MODE
HookOnLoad(0x00499D41, ASMCheckConnectIP, 10);
#endif