////////////////////////////////////////////////////////////////////////
///////  GS_CThreadMALL  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef GS_CThreadMALL_H
#define GS_CThreadMALL_H
#include "SHO_GS.h"
#include "CSqlTHREAD.h"

class TGAMESERVER_API GS_CThreadMALL  : public CSqlTHREAD   { 
public: 
  bool m_bWaiting;
  CStrVAR m_QuerySTR;
  bool Send_gsv_MALL_ITEM_REPLAY(classUSER* pUSER, unsigned char btType, unsigned char btData);
  bool Give_MallITEM(tagQueryDATA* pSqlPACKET, unsigned char btMallInvIDX, short nDupCnt);
  bool Bring_MallITEM(tagQueryDATA* pSqlPACKET, unsigned char btMallInvIDX, short nDupCnt);
  bool List_MallITEM(int iScoketIDX, char* szAccount);
  virtual bool Run_SqlPACKET(tagQueryDATA* pSqlPACKET);
  virtual void Execute();
  GS_CThreadMALL();
  virtual ~GS_CThreadMALL();
  bool Add_SqlPacketWithACCOUNT(classUSER* pUSER, t_PACKET* pPacket);
  bool Add_SqlPacketWithAVATAR(classUSER* pUSER, t_PACKET* pPacket);
};

#endif

