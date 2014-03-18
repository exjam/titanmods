////////////////////////////////////////////////////////////////////////
///////  CThreadLOG  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CThreadLOG_H
#define CThreadLOG_H
#include "SHO_GS.h"
#include "CSqlTHREAD.h"

class TGAMESERVER_API CThreadLOG  : public CSqlTHREAD   { 
public: 
  CStrVAR m_PosSTR;
  char* GetLocationSTR(short nZoneNO, CVec2& PosCUR);
  CStrVAR m_QuerySTR;
  CStrVAR m_ItemSTR;
  CStrVAR m_DescSTR;
  CThreadLOG();
  virtual ~CThreadLOG();
  void Set_EVENT();
  virtual bool Run_SqlPACKET(tagQueryDATA* pSqlPACKET);
  virtual void Execute();
  bool m_bWaiting;
  CCriticalSection m_csSQL;
  _SYSTEMTIME m_locTime;
  char m_szDateTime[0x1E];
  char* GetCurDateTimeSTR();
  void Send_gsv_LOG_SQL();
  bool When_ERROR(classUSER* pUSER, char* szFile, int iLine, char* szDesc);
  bool When_SysERR(char* szFile, int iLine, char* szDesc);
  bool When_CharacterLOG(classUSER* pSourAVT, char* szCharNAME, unsigned char btDelOrNew);
  bool When_ws_CLAN(char* szName, char* szIP, char* szLogType, CClan* pClan, unsigned char btSucType, int iSkillNo, int iNewPos);
};

#endif

