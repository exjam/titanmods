#include "main.h"
#include <TRose\Camera.h>

void __stdcall Process(UINT uiMsg, WPARAM wParam, LPARAM lParam){
	switch(uiMsg){
		case WM_KEYDOWN:
			{
				switch(wParam){
				case VK_NEXT: // Page down
					CCamera::Instance()->Add_Distance(60.0f);
					break;
				case VK_PRIOR: // Page up
					CCamera::Instance()->Add_Distance(-60.0f);
					break;
				}
			}
			break;
	}
}

void __declspec(naked) ASMProcess(){
	static int jRet = 0x00420FF2;
	_asm {
		MOV EBP, DWORD PTR SS:[ESP+0x40]
		PUSHAD
		MOVZX ECX, BL
		PUSH ECX
	    PUSH EBP
		PUSH EAX
		CALL Process
		POPAD
		MOV EBP, EAX
		SUB EAX, 0x101
		JMP jRet
	}
}

HookOnLoad(0x00420FED, ASMProcess, 0);