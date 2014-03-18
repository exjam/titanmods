#ifndef DLGACCEPTGIVEUP_H
#define DLGACCEPTGIVEUP_H

#include "PvP.h"
#include <TRose\RoseAPI.h>
#include <TRose\IT_MGR.h>
#include <TRose\SendPacket.h>

class CTAcceptGiveUP : public CTCommand {
public:
	CTAcceptGiveUP(char* trigger){ 
		mTrigger = _strdup(trigger); 
	}

	virtual ~CTAcceptGiveUP(){ 
		free(mTrigger);
	}

	virtual bool Exec(CTObject* pObj){
		SendPacket::Instance()->DoTrigger(3, 0, 0, mTrigger);
		return true;
	}

public:	
	char* mTrigger;
};

#endif