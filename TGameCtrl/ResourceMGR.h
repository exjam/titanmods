#ifndef	_RESOURCEMGR_
#define _RESOURCEMGR_

#include "TGameCtrl.h"

class TGAMECTRL_API CResourceMgr
{
public:
	CResourceMgr(void);
	virtual ~CResourceMgr(void);
	static	CResourceMgr*	s_pInstance;
	static	CResourceMgr*	GetInstance();
	void	Destroy();
	int GetImageNID( int iModuleID, const char* szSID );
};
#endif