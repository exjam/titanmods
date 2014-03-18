#include "main.h"
#include "Network.h"
#include "Controls.h"
#include "PvP.h"
#include <TRose\RecvPacketHook.h>
#include <TRose\SendPacketHook.h>

Packet* gRecvPacket;
Packet* gSendPacket;

bool gLogPackets = false;
bool gIsTrading;
unsigned short gClientID;
bool gInDuel = false;

bool __stdcall OnReceivePacket(Packet* pak)
{
	gRecvPacket = pak;

	switch(pak->Command()){
		case PAK_ACHIEVEMENT:
			Recv_srv_ACHIEVEMENT();
			break;
		case PAK_CONTRIBUTION:
			Recv_srv_CONTRIBUTION();
			break;
		case PAK_PARTYLIST:
			Recv_srv_PARTYLIST();
			break;
		case PAK_VENDMSG:
			Recv_srv_VENDMESSAGE();
			break;
		case PAK_DUEL:
			Recv_srv_DUEL();
			break;
		case PAK_MESSAGE:
			Recv_srv_MESSAGE();
			break;
		case PAK_ALLYCHAT:
			Recv_srv_ALLY();
			break;
		case PAK_FLAGSTATUS:
			Recv_srv_FLAG();
			break;
		case PAK_NPCVAR:
			Recv_srv_PVP(false);
			break;
		case PAK_NPCVARALL:
			Recv_srv_PVP(true);
			break;
		case PAK_PLAYERDATA:
			Recv_srv_PLAYERDATA();
			break;
		case CLI_SELECT_CHAR:
			{
				IT_MGR::Instance()->AppendChatMsg("Welcome to titanROSE! [www.titanROSE.com]", CHAT_TYPE_WHISPER);
				ResetGUI();
			}
			break;
		case CLI_JOIN_ZONE:
			gClientID = pak->Get<word>(0);
			break;
		case CLI_TOGGLE:
			Recv_srv_RIDE(false);
			break;
		case CLI_WHISPER:
			Recv_srv_WHISPER();
			break;
		case GSV_AVT_CHAR:
			Recv_srv_RIDE(true);
			break;
		case 0x7B5:
			Recv_srv_BUFF();
			break;
		case CLI_MEMO:
			{
				if(pak->Get<unsigned char>(0) == 0x02)
					IT_MGR::Instance()->AppendChatMsg("[MAIL] You've got a new offline message!", CHAT_TYPE_NOTICE);
			}
			break;
		case CLI_TRADE_P2P:
			{
				unsigned char result = pak->Get<unsigned char>(0);

				if((result == 3 || result == 2) && !gIsTrading)
					pak->Reset();

				gIsTrading = false;
			}
			break;
	}

	return false;
}

void _declspec(naked) ASMWorldPacket(){
	static int jRet = 0x004F0548;
	_asm {		
		MOV ECX, DWORD PTR DS:[ESI+4]
		PUSHAD
		PUSH ECX
		CALL OnReceivePacket
		POPAD
		MOVZX EAX, WORD PTR DS:[ECX+2]
		JMP jRet
	};
}

void _declspec(naked) ASMZonePacket(){
	static int jRet = 0x004EFD8A;
	_asm {		
		MOV EAX, DWORD PTR DS:[ESI+4]
		PUSHAD
		PUSH EAX
		CALL OnReceivePacket
		POPAD
		MOVZX ECX, WORD PTR DS:[EAX+2]
		JMP jRet
	};
}

HookOnLoad(0x004F0541, ASMWorldPacket, 2);
HookOnLoad(0x004EFD83, ASMZonePacket, 2);