#ifndef ICONMANAGER_H
#define ICONMANAGER_H

class CIcon;
#include "tagHotICON.h"
#include <Shared/Templates.hpp>

class CHotIconSlot {
public:
	static CHotIconSlot* Instance(){
		return (CHotIconSlot*)((*((char**)0x6936A8)) + 0x1884);
	}

	CIcon* GetIcon( int Slot ) { 
		return CallMemberFunction<CHotIconSlot, CIcon*, int>(0x004CF7B0, this, Slot); 
	}//0x004CF7B0

	tagHotICON GetHotItem( tagHotICON* IconREF, int Slot ) { 
		return CallMemberFunction<CHotIconSlot, tagHotICON, tagHotICON*, int>(0x004CF9B0, this, IconREF, Slot); 
	}//0x004CF9B0
};

class CIconQuick {
public:
	int GetQuickBarSlotIndex() { 
		return CallMemberFunction<CIconQuick, int>(0x004D14F0, this); 
	}//004D14F0
};

#endif
