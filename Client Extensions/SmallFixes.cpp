#include "main.h"
#include "Controls.h"
#include "Network.h"

void FixAspectRatio(){
	unsigned int cameraNode = findNode("avatar_camera");

	if(cameraNode)
		setCameraAspectRatio(cameraNode, (float)getScreenWidth() / (float)getScreenHeight());
}

unsigned long __stdcall CustomItemColour(int type){
	if(type >= 1 && type <= 20)
		return 0xFF00FFFF; // Blueish

	if(type == 25)
		return 0xFFFF0000;	// Green!

	if(type == 40)
		return 0xFFFFAE00;	// PvP Orange

	return 0xFFFFFF00; // default = yellow
}

static _declspec(naked) void ASMForceLanguage(){
	static int retAddr = 0x0043FF3F;
	_asm {		
		MOV EAX,1
		RETN 4
	};
}

HookOnLoad(0x00446A00, ASMForceLanguage, 10);

static _declspec(naked) void ItemNames(){
	static int retAddr = 0x0043FF3F;
	_asm {		
		PUSH ECX
		CALL CustomItemColour
		JMP retAddr
	};
}

void __stdcall SmallFixes(){
	DWORD dwOldProtect;

	//Acquistion order patch
	VirtualProtect((LPVOID)0x0063B290, 10, PAGE_READWRITE, &dwOldProtect);
	sprintf_s((char*)0x0063B290, 10, "%s", "%s: %s");
	VirtualProtect((LPVOID)0x0063B290, 10, dwOldProtect, &dwOldProtect);

	// MAINTAIN_ABILITY stuffs (Shop, Warehouse)
	Code::NOP((unsigned char*)0x00630860,40);
	VirtualProtect((LPVOID)0x00630860, 40, PAGE_READWRITE, &dwOldProtect);
	sprintf_s((char*)0x00630860, 40, "%s", "%s :: Expires at %d/%d/%d");
	VirtualProtect((LPVOID)0x00630860, 40, dwOldProtect, &dwOldProtect);

	Code::Write<unsigned char>(0x0041E5C9, 0x51);
	Code::Write<unsigned char>(0x0041E5CB, 0x52);

	//Quest window string length
	Code::Write<unsigned char>(0x004CC377, 0xDC);
	Code::Write<unsigned char>(0x004BA875, 0xFF);

	//Grade display on masks
	Code::Write<unsigned char>(0x00441EED, 0xEB);
	Code::NOP((unsigned char*)0x00441EE5,4);

	// Allow refining
	Code::Write<unsigned char>(0x004DD4A6, 0x6F);
	Code::Write<unsigned char>(0x004DD4B5, 0x7C);
	Code::Write<unsigned char>(0x004DD4B6, 0x11);
	Code::Write<unsigned char>(0x004DD4BC, 0x7E);

	// Custom item colours
	Code::JmpHook(0x0043FF30, &ItemNames, 5);

	// Allow prefixes on all equipment types
	Code::Write<unsigned char>(0x0043FEF6, 0x01);
	Code::Write<unsigned char>(0x0043FEFB, 0x09);
	Code::Write<unsigned char>(0x0043FE01, 0xEB);
	Code::NOP((unsigned char*)0x0043FEFE,3);

	// Allow "prefix" colours on all equipment types
	Code::Write<unsigned char>(0x0043FEC6, 0x01);
	Code::Write<unsigned char>(0x0043FECB, 0x09);
	Code::Write<unsigned char>(0x0043FED1, 0xEB);
	Code::NOP((unsigned char*)0x0043FECE,3);

	// PAT Icon Positions
	unsigned char PAT[] = {	18,0,0,0, 77,0,0,0,
							18,0,0,0, 123,0,0,0, 
							18,0,0,0, 169,0,0,0, 
							118,0,0,0, 77,0,0,0 };
	Code::Write(0x006369E0, PAT, 32);

	// OnLine OffLine -> Online Offline
	Code::Write<unsigned char>(0x00637243, 0x6C);
	Code::Write<unsigned char>(0x0063723A, 0x6C);

	// Disable Alt+F4 Exit
	Code::NOP((unsigned char*)0x0041DC34, 9);

	//ClanPointCheckFix
	Code::Write<unsigned int>(0x004E8985, 0x90084E8B);
	Code::Write<unsigned char>(0x004E899A, 0x0C);
	Code::Write<unsigned short>(0x004E899E, 0xEFDE);

	// Friends list selected colour = blue
	Code::Write<unsigned char>(0x004C97A8, 0x60);

	// Remove volume change on map change
	Code::NOP((unsigned char*)0x00436881, 8);

	// Quest = 0x684
	Code::Write<unsigned short>(0x004FC1EA, 0x0684);

	// Remove Planet Change Scene
	Code::Write<unsigned char>(0x004F209A, 0xEB);

	// TitanROSE window name
	VirtualProtect((LPVOID)0x00632848, 10, PAGE_READWRITE, &dwOldProtect);
	sprintf_s((char*)0x00632848, 10, "%s", "TitanROSE");
	VirtualProtect((LPVOID)0x00632848, 10, dwOldProtect, &dwOldProtect);

	Code::Write<unsigned char>(0x0043907A, 0xEB); // Multi Client
	Code::NOP((unsigned char*)0x004F06C1, 10);	// Remove Change window name on login

	// NameBox Clan Z-order
	Code::Write<unsigned char>(0x00488234, 0x57);	// PUSH EDI( z ) instead of PUSH EBX( 0 )

	// Skill List always shows right-clicked tooltip
	Code::NOP((unsigned char*)0x004D314D, 13);

	// Appraisal Mode restart on packet recv
	Code::Write<unsigned char>(0x004F5EC9, 0xA3);


	//3rd item stat
	//004E4007  |. 8B44FE 4C      |MOV EAX,DWORD PTR DS:[ESI+EDI*8+4C]                      ;  MOV EAX,DWORD PTR DS:[ESI+EDI*8+44]
	//004E403C  |. 3B44FE 50      |CMP EAX,DWORD PTR DS:[ESI+EDI*8+50]                      ;  CMP EAX,DWORD PTR DS:[ESI+EDI*8+48]
	//004E4043  |. 66:83FB 02     |CMP BX,2                                                 ;  CMP BX,3
	Code::Write<unsigned char>(0x004E4007 + 3, 0x44);
	Code::Write<unsigned char>(0x004E403C + 3, 0x48);
	Code::Write<unsigned char>(0x004E4043 + 3, 0x3);

	//3rd item stat on toooool tip
	//00440308     8B7439 4C      MOV ESI,DWORD PTR DS:[ECX+EDI+4C]                         ;  MOV ESI,DWORD PTR DS:[ECX+EDI+44]
	//0044031C  |. 8B5407 50      |MOV EDX,DWORD PTR DS:[EDI+EAX+50]                        ;  MOV EDX,DWORD PTR DS:[EDI+EAX+48]
	//00440320  |. 8B4407 4C      |MOV EAX,DWORD PTR DS:[EDI+EAX+4C]                        ;  MOV EAX,DWORD PTR DS:[EDI+EAX+44]
	//0044037F  |. 66:8B4C38 4C   |MOV CX,WORD PTR DS:[EAX+EDI+4C]                          ;  MOV CX,WORD PTR DS:[EAX+EDI+44]
	//004403B2  |. 3B4417 50      |CMP EAX,DWORD PTR DS:[EDI+EDX+50]                        ;  CMP EAX,DWORD PTR DS:[EDI+EDX+48]
	//004403E0     83FF 10        CMP EDI,10                                                ;  CMP EDI,18
	Code::Write<unsigned char>(0x00440308 + 3, 0x44);
	Code::Write<unsigned char>(0x0044031C + 3, 0x48);
	Code::Write<unsigned char>(0x00440320 + 3, 0x44);
	Code::Write<unsigned char>(0x0044037F + 4, 0x44);
	Code::Write<unsigned char>(0x004403B2 + 3, 0x48);
	Code::Write<unsigned char>(0x004403E0 + 2, 0x18);


	//Remove union stat req from item tooltip (JobReq2 column)
	/*00441380     C2 0800        RETN 8
	00441383     90             NOP
	00441384     90             NOP
	00441385     90             NOP
	00441386     90             NOP*/
	Code::Write<unsigned char>(0x00441380, 0xc2);
	Code::Write<unsigned short>(0x00441381, 0x08);
	Code::Write<unsigned int>(0x00441383, 0x90909090);

	//Remove union stat req from equip cond check
	/*004E3FF0     90             NOP
	004E3FF1     90             NOP
	004E3FF2     EB 0E          JMP SHORT TRose.004E4002*/
	Code::Write<unsigned short>(0x004E3FF0, 0x9090);
	Code::Write<unsigned char>(0x004E3FF2, 0xEB);


	//10 jobs in list_class.stb
	//00440528  |. 83FA 08        |CMP EDX,8                               ;  CMP EDX, 0A
	//004E2577  |. 66:83FA 08     |CMP DX,8                                ;  CMP DX, 0A
	//004D1E4F  |. 83FA 08        |CMP EDX,8
	Code::Write<unsigned char>(0x00440528 + 2, 0x0A);
	Code::Write<unsigned char>(0x004E2577 + 3, 0x0A);
	Code::Write<unsigned char>(0x004D1E4F + 2, 0x0A);


	//Center align name in DlgInfo
	/*
	0049D5A1   68 96000000      PUSH 96   0x89
	0049D5A8   6A 0F            PUSH 0F   0x0C
	*/
	Code::Write<unsigned char>(0x0049D5A1 + 1, 0x89);
	Code::Write<unsigned char>(0x0049D5A8 + 1, 0x0C);
}

RunOnLoad(SmallFixes);