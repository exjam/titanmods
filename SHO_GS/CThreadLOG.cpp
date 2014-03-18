#include "CThreadLOG.h"

char* CThreadLOG::GetLocationSTR(short nZoneNO, CVec2& PosCUR) { return CallMemberFunction<CThreadLOG, char*, short, CVec2&>(0x10014770, this, nZoneNO, PosCUR); }
CThreadLOG::CThreadLOG() {};
CThreadLOG::~CThreadLOG() {};
void CThreadLOG::Set_EVENT() { return; }
bool CThreadLOG::Run_SqlPACKET(tagQueryDATA* pSqlPACKET) { return CallMemberFunction<CThreadLOG, bool, tagQueryDATA*>(0x10001CC0, this, pSqlPACKET); }
void CThreadLOG::Execute() { return CallMemberFunction<CThreadLOG, void>(0x100AF090, this); }
char* CThreadLOG::GetCurDateTimeSTR() { return CallMemberFunction<CThreadLOG, char*>(0x10006890, this); }
void CThreadLOG::Send_gsv_LOG_SQL() { return CallMemberFunction<CThreadLOG, void>(0x100AF190, this); }
bool CThreadLOG::When_ERROR(classUSER* pUSER, char* szFile, int iLine, char* szDesc) { return CallMemberFunction<CThreadLOG, bool, classUSER*, char*, int, char*>(0x100AF4D0, this, pUSER, szFile, iLine, szDesc); }
bool CThreadLOG::When_SysERR(char* szFile, int iLine, char* szDesc) { return CallMemberFunction<CThreadLOG, bool, char*, int, char*>(0x100AF3E0, this, szFile, iLine, szDesc); }
bool CThreadLOG::When_CharacterLOG(classUSER* pSourAVT, char* szCharNAME, unsigned char btDelOrNew) { return CallMemberFunction<CThreadLOG, bool, classUSER*, char*, unsigned char>(0x100AF460, this, pSourAVT, szCharNAME, btDelOrNew); }
bool CThreadLOG::When_ws_CLAN(char* szName, char* szIP, char* szLogType, CClan* pClan, unsigned char btSucType, int iSkillNo, int iNewPos) { return CallMemberFunction<CThreadLOG, bool, char*, char*, char*, CClan*, unsigned char, int, int>(0x100AF350, this, szName, szIP, szLogType, pClan, btSucType, iSkillNo, iNewPos); }



