#include "main.h"
#include "Controls.h"
#include <TRose\CodeHook.h>

#define MAX_PLAYER_COUNT 2500

void __stdcall AddChannel(CTListBox* listBox, char* channelName, short percent){
	DWORD colour = 0xFFFF0000;

	if(percent <= 60)
		colour = 0xFF00FF00;
	else if(percent <= 99)
		colour = 0xFFFFFF00;

	listBox->AppendText(String("%1 (%2/%3)").arg(channelName).arg((MAX_PLAYER_COUNT / 100) * percent).arg(MAX_PLAYER_COUNT), colour, true);
}

static _declspec(naked) void ASMAddChannel(){
	static int jRet = 0x0049C971;
	_asm {
		MOV EAX, DWORD PTR SS:[ESP+0x9C]
		ADD EDX, 4
		PUSHAD
		PUSH EAX
		PUSH EDX
		PUSH ESI
		CALL AddChannel
		POPAD
		JMP jRet
	};
}

HookOnLoad(0x0049C7E9, ASMAddChannel, 0);