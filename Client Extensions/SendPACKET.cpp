#include "main.h"
#include "Network.h"
#include "Controls.h"
#include "Appearance.h"

#include <TRose\CMAP.h>
#include <TRose\IT_MGR.h>
#include <TRose\CObjMgr.h>
#include <TRose\CTERRAIN.h>
#include <TRose\SendPacketHook.h>

extern bool gIsTrading;

bool __stdcall OnSendPacket(Packet* pak){
	//if(mLogPackets) pak->ToLog(true);

	if(pak->Command() == CLI_TRADE_P2P){
		unsigned char result = pak->Get<unsigned char>(0);

		if(result == 0 || result == 1)
			gIsTrading = true;
	}else if(pak->Command() == CLI_CHAT){
		if(pak->Get<char>(0) == '/'){
			char* command = pak->GetString(1);

			if(strcmp(command, "r") == 0) {
				if(strlen(gLastWhisperer) < 1)	return false;

				if(CTEditBox* editBox = (CTEditBox*)IT_MGR::Instance()->FindDlg(DLG_TYPE_CHAT)->Find(15)){
					editBox->clear_text();
					editBox->AppendText(String("@%1 ").arg(gLastWhisperer));
				}
			}else if(memcmp(command, "appear", 6) == 0){
				gAppearDialog->Show();
			}else if(memcmp(command, "camera", 6) == 0){
				StartAppearance();
			/*	char typebuf[16];
				int objid;
				if(sscanf(cmdstr, "spawn %s %d", typebuf, &objid) != 2 || (
					_strcmpi(typebuf, "cnst") != 0 && 
					_strcmpi(typebuf, "event") != 0 && 
					_strcmpi(typebuf, "deco") != 0)){

					IT_MGR::Instance()->AppendChatMsg("[Spawn] spawn <cnst/deco/event> <objid>", CHAT_TYPE_NOTICE);
					return false;
				}

				CGameOBJ* pAVATAR = CObjMGR::GetSelf();
				if(!pAVATAR){
					IT_MGR::Instance()->AppendChatMsg("[Spawn] !pAVATAR", CHAT_TYPE_NOTICE);
					return false;
				}

				float x = pAVATAR->m_PosCUR.x;
				float y = pAVATAR->m_PosCUR.y;
				CMAP* map = CTERRAIN::Instance()->GetMapPtrByWorldCoordinates(x, y);
				if(!map){
					IT_MGR::Instance()->AppendChatMsg("[Spawn] !map", CHAT_TYPE_NOTICE);
					return false;
				}

				D3DVECTOR pos;
				D3DXQUATERNION rotate;
				D3DVECTOR scale;

				pos.x = x;
				pos.y = y;
				pos.z = pAVATAR->m_PosCUR.z;

				scale.x = 1.0f;
				scale.y = 1.0f;
				scale.z = 1.0f;

				rotate.w = 1.0f;
				rotate.x = 0.0f;
				rotate.y = 0.0f;
				rotate.z = 0.0f;

				int iObjectIndex;
				if(_strcmpi(typebuf, "cnst") == 0)
					iObjectIndex = CObjMGR::Instance()->Add_GndCNST(objid, &pos, &rotate, &scale);
				else if(_strcmpi(typebuf, "deco") == 0)
					iObjectIndex = CObjMGR::Instance()->Add_GndTREE(objid, &pos, &rotate, &scale);
				else if(_strcmpi(typebuf, "event") == 0)
					iObjectIndex = CObjMGR::Instance()->Add_FixedEvent(123, objid, "EMPTY", "EMPTY", &pos, &rotate, &scale);

				if(!map->AddObject(iObjectIndex, &pos, &rotate, &scale)){
					IT_MGR::Instance()->AppendChatMsg("[Spawn] !map->AddObject", CHAT_TYPE_NOTICE);
					return false;
				}

				CGameOBJ *pObject = CObjMGR::Instance()->Get_OBJECT( iObjectIndex );
				if(!pObject){
					IT_MGR::Instance()->AppendChatMsg("[Spawn] !pObject", CHAT_TYPE_NOTICE);
					return false;
				}

				pObject->InsertToScene();*/
			}
		}
	}

	return false;
}

void __stdcall HookPacket(){
	SendPacketHook::Apply(OnSendPacket);
}

RunOnLoad(HookPacket);