#ifndef PARTYLIST_H
#define PARTYLIST_H

#include "Controls.h"
#include <TRose\Tooltip.h>
#include <TRose\SendPacket.h>
#include <TRose\IT_MGR.h>
#include <TRose\StringManager.h>

#define PAK_PARTY_REFRESH 0x0
#define PAK_PARTY_ADD 0x0
#define PAK_PARTY_MODE 0x1
#define PAK_PARTY_CLEAR 0x2

#define PARTY_PRIVATE 1
#define PARTY_PUBLIC 0

extern unsigned char gPartyIsPrivate;
extern bool gDrawToolTip;

class CTListItemParty : public CWinCtrl {
public:
	CTListItemParty();
	virtual ~CTListItemParty();
	virtual unsigned int Process(UINT uiMsg, WPARAM wParam, LPARAM lParam);
	virtual void Update(POINT ptMouse);
	virtual	void Draw();

public:
	POINT mMouse;
	CPartyData mParty;
};

int MaxMembers(int partyLevel);

#endif