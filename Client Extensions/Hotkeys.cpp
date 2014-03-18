#include "main.h"
#include "TRose\Game.h"
#include "Network.h"
#include "PvP.h"
#include "Controls.h"

bool __stdcall ProcessHotkey(int key){
	switch (key){
		case 0x55: // U
			CGameDATA::Instance()->m_bNoUI = !CGameDATA::Instance()->m_bNoUI;
			return true;
		case 0x4C: // L
			{
				if(CGame::Instance()->GetRight() >= 768){
					CreateConsole();
					gLogPackets = !gLogPackets;
				}
			}
			break;
		case 0x46: // F
			{
				if(CGameDATA::Instance()->m_iPvPState == PVP_CANT)
					EnableWallhack();
				else
					IT_MGR::Instance()->AppendChatMsg("You cannot use noclip in PvP zones.", CHAT_TYPE_SYSTEM);
			}
			break;
		case VK_SPACE:
			{
				CUserInputState* inputState = CUserInputState::Instance();
				CGameOBJ* self = CObjMGR::GetSelf();

				if(inputState && self)
					inputState->m_iCurrentTarget = self->m_nIndex;
			}
			break;
		case 0x57: // W
			IT_MGR::Instance()->OpenDialog(DLG_TYPE_ACHIEVEMENTS);
			break;
		case 0x50: // P
			IT_MGR::Instance()->OpenDialog(DLG_TYPE_PVP);
			break;
	}

	return false;
}

void __declspec(naked) ASMHotkeys(){
	static int retAddr = 0x0042116C;
	static int jmpOut = 0x00421428;
	_asm {
		PUSHAD
		PUSH EAX
		CALL ProcessHotkey
		CMP EAX, 1
		JE jOut
		POPAD
		ADD EAX,-0x31                                    
		CMP EAX, 0x26
		JMP retAddr
jOut:
		POPAD
		JMP jmpOut
	}
}

HookOnLoad(0x00421166, ASMHotkeys, 1);