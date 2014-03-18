#include "main.h"
#include "..\Shared\Code.hpp"
#include "..\Shared\RunOnLoad.hpp"
#include <SHO_GS\classPACKET.h>
#include <SHO_GS\classUSER.h>

Array<char*> gFilter;

void _stdcall AddFilters(){
	gFilter.PushBack("gameim");
}

RunOnLoad(AddFilters);


bool _stdcall CheckFilter(char* str){
	if(strlen(str) >= 255)
		return false;

	char buffer[255];
	const char* src = str;
	char* dst = buffer;
	while(*src){
		if(*src >= 'a' && *src <= 'z'){
			*dst = *src;
			++dst;
		}else if(*src >= 'A' && *src <= 'Z'){
			*dst = 0x20 + *src;
			++dst;
		}

		++src;
	}
	*dst = 0;

	for(unsigned int i = 0; i < gFilter.Size(); ++i){
		if(!strstr(buffer, gFilter[i])) continue;

		Log(MSG_DEBUG, "Filtered: %s", buffer);
		return true;
	}

	return false;
}


void _stdcall CheckStoreTitle(classUSER* user){
	if(!user) return;

	CustomAvatarData::Get(user)->mShopOPEN = clock();
	if(!CheckFilter(user->m_szUserTITLE)) return;

	memset(user->m_szUserTITLE, 0, 51);
	user->m_szUserTITLE[0] = 'F';
	user->m_szUserTITLE[1] = 'a';
	user->m_szUserTITLE[2] = 'g';
}

static _declspec(naked) void ASMStoreTitle(){
	static int jRETN = 0x10084A40;
	static int cOpen = 0x1007D860;

	_asm {
		MOV ECX,DWORD PTR SS:[EBP-4]
		PUSH ECX
		CALL CheckStoreTitle
		MOV ECX,DWORD PTR SS:[EBP-4]
		CALL cOpen
		JMP jRETN
	}
}

static _declspec(naked) void ASMFilterChat(){
	static int jRETN = 0x1006A17C;
	static int cPack = 0x10004100;
	static int jSkip = 0x1006A1E3;

	_asm {
		MOV ECX,DWORD PTR SS:[EBP+0x8]
		PUSH ECX
		CALL CheckFilter
		TEST AL, AL	// False(JE) = Good, (no HE) True = bad
		JE Good
		JMP jSkip
Good:
		CALL cPack
		JMP jRETN
	}
}

static _declspec(naked) void ASMFilterShout(){
	static int jRETN = 0x1006A0CD;
	static int cPack = 0x10004100;
	static int jSkip = 0x1006A145;

	_asm {
		MOV ECX,DWORD PTR SS:[EBP+0x8]
		PUSH ECX
		CALL CheckFilter
		TEST AL, AL	// False(JE:0) = Good, (JNZ:1)True = Skip
		JE Good
		JMP jSkip
Good:
		CALL cPack
		JMP jRETN
	}
}

HookOnLoad(0x10084A3B, ASMStoreTitle, 0);
HookOnLoad(0x1006A177, ASMFilterChat, 0);
HookOnLoad(0x1006A0C8, ASMFilterShout, 0);












/*
void _stdcall CheckBuyMoney(classUSER* pUSER) {
	if (pUSER->m_STORE.m_bActive) {
		__int64 TotalMoney = 0;
		bool Invalid = false;
		for (int i=0; i<pUSER->m_STORE.m_btWishCNT; i++) {
			if (pUSER->m_STORE.m_WishITEM[i].IsEmpty())
				continue;
			unsigned int Q = pUSER->m_STORE.m_WishITEM[i].GetQuantity();
			if (Q > 999 || Q < 1) { Invalid = true; break; }
			TotalMoney += (pUSER->m_STORE.m_dwWishPricePerEA[i] * Q);
		}
		if (Invalid || (TotalMoney > pUSER->m_Inventory.m_i64Money)) {
			t_PACKET* cpak = new t_PACKET();
			pUSER->Send_gsv_WHISPER("SERVER", "You do not have enough zulie.");
			pUSER->Recv_cli_P_STORE_CLOSE(cpak);
		}
	}
}

static _declspec(naked) void ASMCheckBuyMoney(){
	static int jRETN = 0x1007D942;
	_asm {
		ADD ESP, 0x4
		MOV EAX,DWORD PTR SS:[EBP-0x4]
		PUSH EAX
		CALL CheckBuyMoney
		MOV AL,1
		JMP jRETN
	}
}

HookOnLoad(0x1007D93D, ASMCheckBuyMoney, 0);

*/