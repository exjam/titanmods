////////////////////////////////////////////////////////////////////////
///////  CThreadGUILD  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CThreadGUILD_H
#define CThreadGUILD_H
#include "SHO_GS.h"
#include "CSqlTHREAD.h"
#include "CDataPOOL.h"
#include "classHASH.h"
#include "CDLList.h"

class TGAMESERVER_API CThreadGUILD  : public CSqlTHREAD   { 
public: 
  CDataPOOL<CClan> m_Pools;
  classHASH<CClan *>* m_pHashCLAN;
  CDLList<tagCLAN_CMD> m_ProcCMD;
  CDLList<tagCLAN_CMD> m_WaitCMD;
  virtual bool Run_SqlPACKET(tagQueryDATA* pSqlPACKET);
  void Test_add(char* pGuildName, char* pGuildDesc);
  void Test_del(char* pGuildName);
  virtual void Execute();
  bool Run_GuildPACKET(tagCLAN_CMD* pGuildCMD);
  CClan* Query_CreateCLAN(int iSocketIDX, t_PACKET* pPacket);
  bool Query_DeleteCLAN(char* szClanName);
  CThreadGUILD(unsigned int uiInitDataCNT, unsigned int uiIncDataCNT);
  virtual ~CThreadGUILD();
  void Set_EVENT();
  bool Add_ClanCMD(unsigned char btCMD, int iSocketIDX, t_PACKET* pPacket, char* szCharName);
  bool Query_LoginClanMember(char* szCharName, int iSenderSockIDX);
  bool Query_InsertClanMember(char* szCharName, unsigned long dwClanID, int iClanPos);
  bool Query_DeleteClanMember(char* szCharName);
  bool Query_AdjustClanMember(char* szCharName, int iAdjContr, int iAdjPos);
  bool Query_UpdateClanMOTD(unsigned long dwClanID, char* szMessage);
  bool Query_UpdateClanSLOGAN(unsigned long dwClanID, char* szMessage);
  bool Query_UpdateClanDATA(char* szField, t_PACKET* pPacket);
  bool Query_UpdateClanBINARY(unsigned long dwClanID, unsigned char* pDATA, unsigned int uiSize);
  unsigned short Query_UpdateClanMARK(CClan* pClan, unsigned short wMarkCRC, unsigned char* pDATA, unsigned int uiSize);
  void Login_GuildUSER(char* Var1, unsigned long Var2, int Var3);
  CClan* Find_CLAN(unsigned long dwClanID);
  CClan* Load_CLAN(unsigned long dwClanID);
  bool Create(classUSER* Var1, char* Var2);
  };

#endif

