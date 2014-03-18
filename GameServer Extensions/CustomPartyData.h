#ifndef CUSTOM_PARTY_DATA_H
#define CUSTOM_PARTY_DATA_H

#include <SHO_GS/CParty.h>

struct CustomPartyData {
	unsigned char mPrivate;

	void InitParty(){
		mPrivate = false;
	}

	void EndParty(){
		mPrivate = false;
	}
};

extern CustomPartyData gCustomPartyData[0x2000];

bool CanParty(int hi, int lo);
int IDXByParty(CParty* party);
void GetPartyList(classUSER* user);
int __stdcall Party_GetAvgLevel(CParty* party);

#endif
