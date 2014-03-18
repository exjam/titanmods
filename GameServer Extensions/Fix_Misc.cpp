#include "main.h"
#include "..\Shared\Code.hpp"
#include "..\Shared\RunOnLoad.hpp"


// Fix Quest check "No Reward"

static _declspec(naked) void ASMQSTREWD(){
	static int jret = 0x10098A05;
	static int jNoREWARD = 0x10098AC3;
	_asm {  
		MOV EAX,DWORD PTR SS:[EBP+0x0C]
		CMP AL, 0
		JE jNoRewd

		MOV WORD PTR SS:[EBP-0xC],0x0FFFF
		JMP jret
jNoRewd:
		JMP jNoREWARD
	}
}
HookOnLoad(0x100989FF, ASMQSTREWD, 1);


// COND 21 FIX
static _declspec(naked) void ASMQSDZoneCheck(){
	static int jret = 0x10099174;
	_asm {  
		MOV EAX,DWORD PTR SS:[EBP-0x4]
		MOV EDX,DWORD PTR DS:[EAX]
		MOV EDI,ESP
		MOV ECX,DWORD PTR SS:[EBP-0x4]
		JMP jret
	}
}
HookOnLoad(0x10099162, ASMQSDZoneCheck, 12);


// TEST_SERVER
/*
static _declspec(naked) void ASMTS_HTTP(){
	static int jret = 0x100AA8FB;
	_asm {  
		JMP jret
	}
}
HookOnLoad(0x100AA673, ASMTS_HTTP, 1);
*/

static _declspec(naked) void ASMGMSpawn(){
	static int jret = 0x10053ABF;
	_asm {
		LEA EAX,DWORD PTR SS:[EBP-0x24]
		MOV DWORD PTR SS:[EAX+0x6],0x3B9AC9FF
		PUSH EAX      
		MOV ECX,DWORD PTR SS:[EBP-0x4]   
		JMP jret
	}
}
HookOnLoad(0x10053AB8, ASMGMSpawn, 2);


static _declspec(naked) void ASMFixOddError(){
	static int jbad = 0x1008FCAB;
	static int jret = 0x1008FA74;
	static int czone = 0x10004020;
	_asm {
		CALL czone
		TEST EAX, EAX
		JE bad
		JMP jret
bad: 
		JMP jbad
	}
}
HookOnLoad(0x1008FA6F, ASMFixOddError, 0);


static _declspec(naked) void ASMSPError(){
	static int jRet = 0x100A19F7;
	_asm {
		MOV ECX,DWORD PTR SS:[EBP+0x8]
		XOR AL, AL
		JMP jRet
	}
}
HookOnLoad(0x100A19D1, ASMSPError, 0);


void __stdcall Fixes(){
	//All items get a serial
	Code::Write<unsigned short>(0x1000AD69, 0x9090);

	//Party default mode -> set item order
	Code::Write<unsigned char>(0x1000FA84, 0x80);

	//All items log
	Code::Write<unsigned char>(0x10065C96, 0xEB);
	Code::Write<unsigned char>(0x10066006, 0xEB);
	Code::Write<unsigned char>(0x100662D7, 0xEB);

	Code::Write<unsigned char>(0x10065C97, 0x15);
	Code::Write<unsigned char>(0x10066007, 0x15);
	Code::Write<unsigned char>(0x100662D8, 0x63);

	// Remove HandlePacket -> IsHacking
	Code::NOP((unsigned char*)0x1008D3C1, 23);

	// Remove Except OBJ Messages (kill_all)
	Code::Write<unsigned char>(0x10061A01, 0x3B);

	// Skill Lock
	Code::Write<unsigned char>(0x10011D2F, 0x77);
	Code::Write<unsigned char>(0x10011D31, 0x72);

	// Remove quest packet handler
	Code::Write<unsigned int>(0x1008F5BD, 0x1008F53F);
	
	// Money / Zulie / Exp hax patch
	Code::Write<unsigned char>(0x1008EDF6, 0x8B);
	Code::Write<unsigned char>(0x1008EDF7, 0x4D);
	Code::Write<unsigned char>(0x1008EDF8, 0xFC);
	Code::Write<unsigned char>(0x1008EDF9, 0xE8);
	Code::Write<unsigned char>(0x1008EDFA, 0xA2);
	Code::Write<unsigned char>(0x1008EDFB, 0x1C);
	Code::Write<unsigned char>(0x1008EDFC, 0xFF);
	Code::Write<unsigned char>(0x1008EDFD, 0xFF);
	Code::Write<unsigned char>(0x1008EDFE, 0x0F);
	Code::Write<unsigned char>(0x1008EDFF, 0xB6);
	Code::Write<unsigned char>(0x1008EE00, 0xC0);

	// Motion spam
	Code::Write<unsigned char>(0x1007EE1D, 0xEB);
	Code::Write<unsigned char>(0x1007EE1E, 0x1F);
	Code::Write<unsigned char>(0x1007EE1F, 0x90);

	//User Counter
	DWORD dwOldProtect;
	VirtualProtect((LPVOID)0x100B9048, 100, PAGE_READWRITE, &dwOldProtect);
	sprintf_s((char*)0x100B9048, 100, "%s", "http://not_real_website.com/not_real_script.php?cnt=%d");
	VirtualProtect((LPVOID)0x100B9048, 100, dwOldProtect, &dwOldProtect);

	// Invincible Team stuff OnJoin
	Code::NOP((unsigned char*)0x100897A0, 4);

	// Slot 3 Storage
	Code::Write<unsigned char>(0x1007DE8F, 0x78);

	// Remove old sell whisper
	Code::Write<unsigned char>(0x10084377, 0x83);
	Code::Write<unsigned char>(0x10084378, 0xC4);
	Code::Write<unsigned char>(0x10084379, 0x04);
	Code::Write<unsigned char>(0x1008437A, 0xEB);
	Code::Write<unsigned char>(0x1008437B, 0x14);

	// Money trade log req
	Code::Write<unsigned char>(0x10066574, 0x83);
	Code::Write<unsigned char>(0x10066577, 0x01);
	Code::NOP((unsigned char*)0x10066578, 3);


	// Remove update clan data
	Code::Write<unsigned short>(0x100A21BA, 0);
	// Remove update clan user
	Code::Write<unsigned short>(0x100A198C, 0);
	// Remove clan delete success
	Code::Write<unsigned short>(0x100A25CB, 0);

	// Glov PK
	Code::Write<unsigned char>(0x100D4EF9, 0xEB);

	// Event Obj Zone update
	Code::Write<unsigned char>(0x100576B0, 0x90);

	Code::Write<unsigned char>(0x100576BF, 0x0D);
	Code::Write<unsigned char>(0x100576C0, 0x96);

	// Zone list limit removed
	Code::Write<unsigned char>(0x10092EA3, 0xEB);

	//Add 3rd stat column
	//10072802     83F9 02        CMP ECX,2                                                ;  CMP ECX, 3
	//1007283D     837C90 4C 00   CMP DWORD PTR DS:[EAX+EDX*4+4C],0                        ;  CMP DWORD PTR DS:[EAX+EDX*4+44],0
	//1007287B     66:8B448A 4C   MOV AX,WORD PTR DS:[EDX+ECX*4+4C]                        ;  MOV AX,WORD PTR DS:[EDX+ECX*4+44]
	//100728CB     3B5481 50      CMP EDX,DWORD PTR DS:[ECX+EAX*4+50]                      ;  CMP EDX,DWORD PTR DS:[ECX+EAX*4+48]
	Code::Write<unsigned char>(0x10072804, 0x03);
	Code::Write<unsigned char>(0x10072840, 0x44);
	Code::Write<unsigned char>(0x1007287F, 0x44);
	Code::Write<unsigned char>(0x100728CE, 0x48);

	//Disable check for unionionion
	//1007278B     EB 43          JMP SHORT SHO_GS_1.100727D0
	Code::Write<unsigned char>(0x1007278B, 0xEB);

	//Add up to 10 jobs for list_class.stb
	//100714CD  |. 83F8 08        |CMP EAX,8
	Code::Write<unsigned char>(0x100714CD + 2, 0x0A);
}

RunOnLoad(Fixes);
