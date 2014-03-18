#include "ResourceMGR.h"

CResourceMgr::CResourceMgr(){}
CResourceMgr::~CResourceMgr(){}

CResourceMgr* CResourceMgr::GetInstance(){ return 0; }
void CResourceMgr::Destroy(){ return; }
int CResourceMgr::GetImageNID( int iModuleID, const char* szSID ){ return 0; }