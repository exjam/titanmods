#ifndef CExternalUILobby_H
#define CExternalUILobby_H
#include "Shared/Templates.hpp"
#include "ExternalUIManager.h"

class CExternalUILobby {
public:
	CExternalUIManager* GetExternalUIManager() { 
		return CallMemberFunction<CExternalUILobby, CExternalUIManager*>(0x0049CE30, this); 
	}

	static CExternalUILobby* Instance(){
		return reinterpret_cast<CExternalUILobby*>(0x00697FE4);
	}
};

#endif