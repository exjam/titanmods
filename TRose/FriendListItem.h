#ifndef FriendListItem_H
#define FriendListItem_H

#include "Shared/Templates.hpp"
#include <TGameCtrl\WinCtrl.h>

class CFriendListItem : public CWinCtrl {
public:
	const char* GetName(){
		return CallMemberFunction<CFriendListItem, const char*>(0x004C9AB0, this);
	}
	
	const unsigned char GetStatus(){
		return CallMemberFunction<CFriendListItem, unsigned char>(0x004C96E0, this);
	}
};

#endif