#include "RoseAPI.h"
#include "CodeHook.h"
#include "IT_MGR.h"
#include "SendPacket.h"
#include "StringManager.h"
#include "DrawImpl.h"
#include "Tooltip.h"
#include "BuffTooltipHook.h"
#include "Slot.h"
#include "DragItem.h"
#include "Game.h"
#include "IconManager.h"
#include "CObjMGR.h"
#include "ToolTipMgr.h"
#include "GetObjectIdxFromClientID.hpp"
#include "CallCharLuaFunc.hpp"
#include "STB.h"
#include <Shared/Templates.hpp>

int BuffTimeHolder::mRemainTime = 0;

CSlot::~CSlot(){ *(int*)0 = 51; }
bool CSlot::AttachIcon(CIcon* pIcon){ *(int*)0 = 52; return false; }
void CSlot::DetachIcon(){ *(int*)0 = 53; }
CIcon* CSlot::GetIcon(){ *(int*)0 = 54; return 0; }
void CSlot::Draw(){ *(int*)0 = 55; }
unsigned int CSlot::Process(UINT uiMsg, WPARAM wParam, LPARAM lParam){ *(int*)0 = 56; return 0; }
void CSlot::MoveWindow(POINT pt){ *(int*)0 = 57; }
void CSlot::Update(POINT mousePos){ *(int*)0 = 58; }


int __declspec(naked) Call_Char_Lua_Func(int iObject, const char* pFunc ){
	static int func = 0x004EC440;
	_asm {
		MOV EAX, DWORD PTR DS:[0x6998FC]
		MOV EAX, DWORD PTR DS:[EAX]
		CMP EAX, 0
		JE superFail
		MOV EAX, DWORD PTR DS:[EAX+0x8]
		PUSH 0x3E7
		PUSH DWORD PTR DS:[ESP+0x8]
		PUSH 1
		PUSH DWORD PTR DS:[ESP+0x14]
		PUSH EAX
		CALL func
		ADD ESP, 0x14
superFail:
		RETN
	}
}

/*
short	Get_ClientObjectIndex (WORD  wServerObjectIndex)	{	return m_nServer2ClientOBJ[ wServerObjectIndex ];	}
WORD	Get_ServerObjectIndex (short nClientObjectIndex)	{	return m_wClient2ServerOBJ[ nClientObjectIndex ];	}
*/
