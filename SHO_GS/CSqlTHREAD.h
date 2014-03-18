////////////////////////////////////////////////////////////////////////
///////  CSqlTHREAD  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CSqlTHREAD_H
#define CSqlTHREAD_H
#include "SHO_GS.h"
#include "classTHREAD.h"
#include "CDLList.h"
#include "CCriticalSection.h"

class classSQL;
class classEVENT;

class TGAMESERVER_API CSqlTHREAD  : public classTHREAD   { 
public: 
  classSQL* m_pSQL;
  classEVENT* m_pEVENT;
  CCriticalSection m_CS;
  CDLList<tagQueryDATA> m_RunPACKET;
  CDLList<tagQueryDATA> m_AddPACKET;
  CDLList<char *> m_RunQUERY;
  CDLList<char *> m_AddQUERY;
  char* Del_SqlPACKET(char* pDelNODE);
  virtual bool Run_SqlPACKET(tagQueryDATA* Var1);
  virtual bool Proc_QuerySTRING();
  CSqlTHREAD();
  CSqlTHREAD(bool bCreateSuspended);
  virtual ~CSqlTHREAD();
  bool Connect(unsigned char btSqlTYPE, char* szServerIP, char* szUser, char* szPassword, char* szDBName, short nBindParamCNT, unsigned short wQueryBufferLEN);
  void Free();
  bool Add_SqlPACKET(int iTAG, char* szName, unsigned char* pDATA, int iDataSize);
  bool Add_QueryString(const char* szQuery);
};

#endif
