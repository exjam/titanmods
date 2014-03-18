#include "RoseAPI.h"
#include "CodeHook.h"
#include "GuiManager.h"
#include "SendPacket.h"
#include "StringManager.h"
#include "DrawImpl.h"
#include "Tooltip.h"
#include "BuffTooltipHook.h"
#include "Slot.h"
#include "DragItem.h"
#include "Game.h"
#include "IconManager.h"
#include "IconInSlot.h"
#include "EntityList.h"
#include "GetObjectIdxFromClientID.hpp"
#include "CallCharLuaFunc.hpp"

int BuffTimeHolder::mRemainTime = 0;

template<class T> void FixMemberFuncAddress(int troseAddr, T func){
	CodeHook::ApplyJmpHook((unsigned char*)(*((void**)&func)), (unsigned char*)troseAddr, 0);
}

void FixConstructorAddress(int addrROSE, unsigned char* createFunc){
	unsigned char* addr = createFunc;
	if(addr[2] == 0xE8){
		for(int i = 0; i < 0x20; ++i){
			if(addr[i] != 0xE9) continue;
			int relAddr = *(int*)(addr + i + 1);
			int cAddr = (int)(addr + i);
			int ctorAddr = cAddr + relAddr + 5;		
			unsigned char* codePtr = (unsigned char*)ctorAddr;
			DWORD oldProtect;
			VirtualProtect(codePtr, 5, PAGE_EXECUTE_READWRITE, &oldProtect);
			codePtr[0] = 0x8B;
			codePtr[1] = 0xC8;
			VirtualProtect(codePtr, 5, oldProtect, &oldProtect);
			CodeHook::ApplyJmpHook(codePtr + 2, (unsigned char*)addrROSE, 0);
			break;
		}
	}else{
		addr = addr + 0x30;
		for(int i = 0; i < 0x20; ++i){
			if(addr[i] != 0xE8) continue;
			int relAddr = *(int*)(addr + i + 1);
			int cAddr = (int)(addr + i);
			int ctorAddr = cAddr + relAddr + 5;		
			unsigned char* codePtr = (unsigned char*)ctorAddr;
			DWORD oldProtect;
			VirtualProtect(codePtr, 5, PAGE_EXECUTE_READWRITE, &oldProtect);
			codePtr[0] = 0x8B;
			codePtr[1] = 0xCE;
			VirtualProtect(codePtr, 5, oldProtect, &oldProtect);
			CodeHook::ApplyJmpHook(codePtr + 2, (unsigned char*)addrROSE, 1);
			break;
		}
	}
}

void GuiManager::AppendChatMsg(const char* text, int type, unsigned int colour){*(int*)0 = 1;}
void GuiManager::OpenMsgBox(char* text, int buttonType, int modal, int invokerDlg, CTCommand* commandOK, CTCommand* commandCancel, int msgType){*(int*)0 = 2;}
void GuiManager::AppendDlg(short type, CTDialog* dialog, int id){*(int*)0 = 3;}
CTDialog* GuiManager::FindDlg(DWORD dwDlgType){*(int*)0 = 4; return 0;}

void SendPacket::Send(class Packet* pSendPacket, bool sendToWorld){*(int*)0 = 4;}
void SendPacket::DoTrigger(unsigned char type, unsigned char questSlot, int questID, char* trigger){*(int*)0 = 5;}
void SendPacket::SendLocal(char* message){*(int*)0 = 6;}
void SendPacket::SendShout(char* message){*(int*)0 = 7;}
void SendPacket::SendSetHotIcon(unsigned char idx, tagHotICON HotICON){*(int*)0 = 8;}

const char* StringManager::GetString(int index){ *(int*)0 = 9; return 0; }
const char* StringManager::GetClanStr(int index){ *(int*)0 = 10; return 0; }
const char* StringManager::GetPlanetName(int index){ *(int*)0 = 11; return 0; }
const char* StringManager::GetClassName(int index){ *(int*)0 = 12; return 0; }
const char* StringManager::GetSkillType(int index){ *(int*)0 = 13; return 0; }
const char* StringManager::GetSkillTarget(int index){ *(int*)0 = 14; return 0; }
const char* StringManager::GetItemType(int index){ *(int*)0 = 15; return 0; }
const char* StringManager::GetAbilityName(int index){ *(int*)0 = 16; return 0; }
const char* StringManager::GetNPCName(int index){ *(int*)0 = 17; return 0; }
const char* StringManager::GetItemName(int type, int id){ *(int*)0 = 18; return 0; }

void DrawImpl::Draw2D(int x, int y, int moduleID, int graphicID, int colour){ *(int*)0 = 19; }
void DrawImpl::Draw3D(float x, float y, float z, int moduleID, int graphicID, int colour){ *(int*)0 = 20; }


void CInfoCreator(){
	Tooltip* tooltip = new Tooltip();
}
Tooltip::Tooltip(){ m_iWidth = 0;  }
Tooltip::~Tooltip(){ *(int*)0 = 25;  }
void Tooltip::AddString(const char* text, unsigned long color, HNODE hFont, UINT uFormat){ *(int*)0 = 51; }
void Tooltip::Clear(){ *(int*)0 = 1; }
void Tooltip::Draw(){ *(int*)0 = 2; }
void Tooltip::SetPosition(POINT pt){ *(int*)0 = 3; }


CSlot::CSlot(){ mIcon = 0; }
CSlot::~CSlot(){ *(int*)0 = 22; }
bool CSlot::AttachIcon(CIcon* pIcon){ *(int*)0 = 23; return false; }
void CSlot::DetachIcon(){ *(int*)0 = 24; }
CIcon* CSlot::GetIcon(){ *(int*)0 = 25; return 0; }

void CSlot::Draw(){ *(int*)0 = 26; }
unsigned int CSlot::Process(UINT uiMsg, WPARAM wParam, LPARAM lParam){ *(int*)0 = 27; return 0; }
void CSlot::MoveWindow(POINT pt){ *(int*)0 = 28; }
void CSlot::Update(POINT mousePos){ *(int*)0 = 29; }

void CSlot::SetParent(int iID){ *(int*)0 = 30; }
void CSlot::SetDragAvailable(){ *(int*)0 = 31; }
void CSlot::SetDragItem(CDragItem* pDragItem){ *(int*)0 = 32; }

void CSlotCreator(){
	CSlot* slot = new CSlot();
}

GameEntity* EntityList::GetPlayerByID(int clientid, int unk1){ *(int*)0 = 33; return NULL; }

CDragItem::CDragItem(){ mUnkData[0] = 0; }
CDragItem::~CDragItem(){ mUnkData[1] = 1; }

void CDragItem::AddTarget(int iTargetType , CTCommand* pCmd){ *(int*)0 = 33; }

void CDragItemCreator(){
	CDragItem* item = new CDragItem();
}

CGame* CGame::Instance(){ *(int*)0 = 34; return 0; }
int CGame::GetRight(){ *(int*)0 = 34; return 0; }

CIcon* CIconManager::GetIcon(int slot){ *(int*)0 = 35; return 0; }
tagHotICON CIconManager::GetItem(int slot){ *(int*)0 = 36; return tagHotICON(); }

int CIconInSlot::GetIndex(){ *(int*)0 = 37; return 0; }

void RoseAPI::Init(){
	FixMemberFuncAddress(0x0048D890, &GuiManager::AppendChatMsg);
	FixMemberFuncAddress(0x0048F320, &GuiManager::OpenMsgBox);
	FixMemberFuncAddress(0x0048F9D0, &GuiManager::AppendDlg);
	FixMemberFuncAddress(0x0048D820, &GuiManager::FindDlg);

	FixMemberFuncAddress(0x004EFBB0, &SendPacket::Send);
	FixMemberFuncAddress(0x004FC1E0, &SendPacket::DoTrigger);
	FixMemberFuncAddress(0x004FB9B0, &SendPacket::SendLocal);
	FixMemberFuncAddress(0x004FBB10, &SendPacket::SendShout);
	FixMemberFuncAddress(0x004FBEA0, &SendPacket::SendSetHotIcon);

	FixMemberFuncAddress(0x0044B400, &StringManager::GetString);
	FixMemberFuncAddress(0x0044B4B0, &StringManager::GetClanStr);
	FixMemberFuncAddress(0x0044B560, &StringManager::GetPlanetName);
	FixMemberFuncAddress(0x0044B610, &StringManager::GetClassName);
	FixMemberFuncAddress(0x0044B6C0, &StringManager::GetSkillType);
	FixMemberFuncAddress(0x0044B770, &StringManager::GetSkillTarget);
	FixMemberFuncAddress(0x0044B820, &StringManager::GetItemType);
	FixMemberFuncAddress(0x0044B8D0, &StringManager::GetAbilityName);
	FixMemberFuncAddress(0x0044CB50, &StringManager::GetNPCName);
	FixMemberFuncAddress(0x0044CAA0, &StringManager::GetItemName);

	FixMemberFuncAddress(0x00488B40, &DrawImpl::Draw2D);
	FixMemberFuncAddress(0x00488CE0, &DrawImpl::Draw3D);

	CInfoCreator();
	FixConstructorAddress(0x00485800, (unsigned char*)&CInfoCreator);
	FixMemberFuncAddress(0x00485630, &Tooltip::Clear);
	FixMemberFuncAddress(0x00485190, &Tooltip::Draw);
	FixMemberFuncAddress(0x00485D00, &Tooltip::AddString);
	FixMemberFuncAddress(0x004850F0, &Tooltip::SetPosition);

	CSlotCreator();
	FixConstructorAddress(0x004CCFF0, (unsigned char*)&CSlotCreator);
	FixMemberFuncAddress(0x004CD0A0, &CSlot::SetParent);
	FixMemberFuncAddress(0x004CD0B0, &CSlot::SetDragAvailable);
	FixMemberFuncAddress(0x004CD0D0, &CSlot::SetDragItem);

	CDragItemCreator();
	FixConstructorAddress(0x004802D0, (unsigned char*)&CDragItemCreator);
	FixMemberFuncAddress(0x00480170, &CDragItem::AddTarget);

	FixMemberFuncAddress(0x0041D9A0, &CGame::Instance);
	FixMemberFuncAddress(0x0041C330, &CGame::GetRight);
	
	FixMemberFuncAddress(0x004CF7B0, &CIconManager::GetIcon);
	FixMemberFuncAddress(0x004CF9B0, &CIconManager::GetItem);

	FixMemberFuncAddress(0x004D14F0, &CIconInSlot::GetIndex);

	FixMemberFuncAddress(0x004778E0, &EntityList::GetPlayerByID);
}

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

unsigned short _declspec(naked) GetObjectIdxFromClientID(unsigned short clientid){
	_asm {
		MOVZX EDX, WORD PTR DS:[ESP+0x4]
		MOV ECX, DWORD PTR DS:[0x695B44]
		MOV AX, WORD PTR DS:[ECX+EDX*2+8]
		RETN
	}
}


unsigned short _declspec(naked) GetSelfObjectIDX(){
	_asm {
		MOV ECX, DWORD PTR DS:[0x6936A8]
		MOV AX, WORD PTR DS:[ECX+0x18]
		RETN
	}
}
