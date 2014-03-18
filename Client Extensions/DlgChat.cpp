#include "main.h"
#include "Network.h"
#include "Controls.h"

char gLastWhisperer[32];

void _stdcall SendAllyChat(char* text){
	Packet* pak = new Packet(PAK_ALLYCHAT);
	pak->AddString(text);
	SendPacket::Instance()->Send(pak);
	delete pak;
}

static _declspec(naked) void ASMAllyChat(){
	static int retAddr = 0x004A92F7;
	_asm {	
		PUSHAD
		PUSH EAX
		CALL SendAllyChat
		POPAD
		JMP retAddr
	};
}

HookOnLoad(0x004A9045, ASMAllyChat, 4);

static _declspec(naked) void AppendFix2(){
	static int retAddr1 = 0x004A6A3D;
	static int retAddr2 = 0x004A6A45;
	_asm {		
		CMP DWORD PTR SS:[ESP+0x14], 0x34
		JNZ Shout
		MOV EDI, EDX
		PUSH 0x6368EC
		JMP retAddr1
Shout:
		CMP DWORD PTR SS:[ESP+0x14], 0x35
		JNZ Skip
		MOV EDI, EDX
		PUSH 0x6368F8
		JMP retAddr1
Skip:
		PUSH 0x0
		JMP retAddr1
	};
}

void __stdcall WhisperAppend(CTEditBox* editBox){
	if(editBox->get_text() == NULL || strlen(editBox->get_text()) < 1)
		editBox->AppendText("@");
}

void __stdcall ShoutAppend(CTEditBox* editBox){
	if(editBox->get_text() == NULL || strlen(editBox->get_text()) < 1)
		editBox->AppendText("!");
}

static _declspec(naked) void AppendFix(){
	static int retAddr = 0x004A9423;
	_asm {		
		CMP DWORD PTR DS:[EBX+0x5C], 2
		JNZ Shout
		PUSH ESI
		CALL WhisperAppend
Shout:
		CMP DWORD PTR DS:[EBX+0x5C], 3
		JNZ Skip
		PUSH ESI
		CALL ShoutAppend
Skip:
		MOV EAX,DWORD PTR DS:[EBX+0x5C]
		SUB EAX,4          
		JMP retAddr
	};
}

void _stdcall ChatFixes(){
	// Append and Whisper&Shout
	Code::JmpHook(0x004A685E, &AppendFix2, 0);
	Code::JmpHook(0x004A941D, &AppendFix, 1);

	// ! (Shout)
	Code::Write<unsigned char>(0x006368F8, 0x21);
	Code::Write<unsigned char>(0x004A99FF, 0x01);

	// Filter :: Allied
	Code::Write<unsigned char>(0x0048D9F4, 0x05);

	// Filter :: Whisper
	Code::Write<unsigned char>(0x0048D8DD, 0xB2);
	Code::Write<unsigned char>(0x0048D8DE, 0x02);

	// Filter :: Turn off System except @ All
	Code::Write<unsigned char>(0x004A979A, 0x00);
	Code::Write<unsigned char>(0x004A97BF, 0x00);
	Code::Write<unsigned char>(0x004A97E5, 0x00);
	Code::Write<unsigned char>(0x004A980B, 0x00);
	Code::Write<unsigned char>(0x004A9831, 0x00);
}

RunOnLoad(ChatFixes);