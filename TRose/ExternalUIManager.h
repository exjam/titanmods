#ifndef CExternalUIManager_H
#define CExternalUIManager_H
#include "Shared/Templates.hpp"

class CTDialog;

class CExternalUIManager {
public:
	CTDialog* GetEUI(int type) { 
		return CallMemberFunction<CExternalUIManager, CTDialog*>(0x004993E0, this, type); 
	}
};

#endif