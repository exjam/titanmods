#ifndef CTLISTGAME_H
#define CTLISTGAME_H

#include <TRose\RoseAPI.h>

class CTReplyDuel : public CTCommand {
public:
	CTReplyDuel(int playerID, byte denyOrAccept, int duelZulie){ 
		mRequestedDuelID = playerID;
		mAccept = denyOrAccept;
		mDuelZulie = duelZulie;
	}

	virtual ~CTReplyDuel(){ }

	virtual bool Exec(CTObject* object){
		if(mAccept == 1){
			CGameOBJ* self = CObjMGR::GetSelf();
			if(self->GetStat(40) < mDuelZulie){
				IT_MGR::Instance()->AppendChatMsg("You do not have enough zulie.", CHAT_TYPE_SYSTEM);
				mAccept = 0;
			}
		}

		Packet* pak = new Packet(PAK_DUEL);
		pak->Add<byte>(1); // Reply
		pak->Add<int>(mRequestedDuelID);
		pak->Add<byte>(mAccept); // Deny(0) or Accept(1) or Busy(2)
		SendPacket::Instance()->Send(pak);
		delete pak;

		return true;
	}

public:
	int mRequestedDuelID;
	int mDuelZulie;
	byte mAccept;
};

#endif