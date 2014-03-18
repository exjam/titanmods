#ifndef ICONITEM_H
#define ICONITEM_H

#include "VirtualTable.h"

struct CIconItemVTABLE {
	char unk[0x30];
	VTABLEFUNC GetIndex;
};

class CIconItem {
public:
	CIconItemVTABLE* mVTable;
	short GetIndex(){
		return CallVTABLE<CIconItem, int>(mVTable->GetIndex, this);
	}
};

#endif
