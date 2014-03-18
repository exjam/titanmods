#include "main.h"
#include "Controls.h"

void _stdcall OnKill(CGameOBJ* murderer, CGameOBJ* victim){
	if(!gIsActive) PwntHaxBbq();
	if(victim == CObjMGR::GetSelf()){
		if(!murderer) return;
		IT_MGR::Instance()->AppendChatMsg(String("You were killed by %1").arg(murderer->GetName()).Str(), CHAT_TYPE_NOTICE);
	}
}

static _declspec(naked) void ASMOnKillForward(){
	static const char* OnKillJNZ = reinterpret_cast<char*>(0x0046C502);
	static const char* OnKillJMP = reinterpret_cast<char*>(0x0046C4A2);
	_asm {
		PUSH ESI
		PUSH EDI
		CALL OnKill
		MOV EAX, DWORD PTR DS:[0x6936A8]
		MOV AX, WORD PTR DS:[EAX+0x18]
		CMP AX, WORD PTR DS:[EDI+0x18]
		JNZ gogoJNZ
		JMP OnKillJMP
gogoJNZ:
		JMP OnKillJNZ
	}
}

HookOnLoad(0x0046C498, ASMOnKillForward, 0);