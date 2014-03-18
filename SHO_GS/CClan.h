////////////////////////////////////////////////////////////////////////
///////  CClan  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CClan_H
#define CClan_H
#include "SHO_GS.h"
#include "CCriticalSection.h"
#include "CDLList.h"

struct wsv_CLANMARK_REG_TIME  : public t_PACKETHEADER   { 
public: 
  unsigned short m_wYear;
  unsigned char m_btMon;
  unsigned char m_btDay;
  unsigned char m_btHour;
  unsigned char m_btMin;
  unsigned char m_btSec;
};

class TGAMESERVER_API CClanUSER   { 
public: 
  CStrVAR m_Name;
  unsigned long m_HashName;
  int m_iContribute;
  int m_iPosition;
  int m_iConnSockIDX;
  unsigned char m_btChannelNo;
  short m_nLevel;
  short m_nJob;
  CClanUSER();
  ~CClanUSER();
};


class TGAMESERVER_API CClan  : public CCriticalSection   { 
public: 
  static const int s_iUserLimit[0x8];//static, [000BA310][0002:00008310];
  unsigned long m_dwClanID;
  short m_nClanLEVEL;
  int m_iClanSCORE;
  unsigned long m_dwClanMARK;
  unsigned short m_wClanMARK[0x2];
  unsigned long m_dwAlliedGroupID;
  int m_iClanRATE;
  __int64 m_biClanMONEY;
  CStrVAR m_Name;
  CStrVAR m_Desc;
  CStrVAR m_Motd;
  short m_nClanMarkLEN;
  unsigned char m_pClanMARK[0x400];
  wsv_CLANMARK_REG_TIME m_RegTIME;
  tagClanBIN m_ClanBIN;
  short m_nPosCNT[0x7];
  CDLList<CClanUSER> m_ListUSER;
  CClan();
  virtual ~CClan();
  void Init(char* szName, char* szDesc, unsigned long dwClanID, unsigned short wMark1, unsigned short wMark2, unsigned char* pClanBIN, unsigned short wMarkCRC, short nMarkDataLen, unsigned char* pClanMARK);
  void Free();
  int GetUserLimitCNT();
  int GetPositionLimitCNT(int iPos);
  void Disband();
  bool LogIn_ClanUSER(char* szCharName, int iSenderSockIDX, int iContribute);
  bool LogOut_ClanUSER(char* szCharName);
  bool Send_SetCLAN(unsigned char btCMD, classUSER* pMember);
  bool Send_MemberSTATUS(CClanUSER* pClanUser, unsigned char btResult);
  bool Insert_MEMBER(unsigned char btResult, classUSER* pMember, int iClanPos, char* szMaster);
  bool Delete_MEMBER(unsigned long HashCommander, char* szCharName, unsigned char btCMD, char* szKicker);
  bool Update_MEMBER();
  bool Adjust_MEMBER(unsigned long HashCommander, char* szCharName, int iAdjContr, int iAdjPos, char* szMaster, int iMaxPos, int iMinPos, bool bCheckPosLimit);
  unsigned long GetCurAbsSEC();
  unsigned char FindClanSKILL(short nSkillNo1, short nSkillNo2);
  bool AddClanSKILL(short nSkillNo);
  bool DelClanSKILL(short nSkillNo);
  bool SetClanMARK(unsigned char* pMarkData, short nDataLen, unsigned short wMarkCRC16, classUSER* pReqUSER);
  void SetJOBnLEV(unsigned long HashCHAR, char* szCharName, short nJob, short nLev);
  void SendRoster(int iSenderSockIDX);
  void Send_UpdateInfo();
  void SendPacketToMEMBER(classPACKET* pCPacket);
  bool Send_wsv_CLAN_COMMAND(unsigned char btCMD);
  bool Send_wsv_CLANMARK_REG_TIME(classUSER* pMember);
    };

#endif

