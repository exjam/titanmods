////////////////////////////////////////////////////////////////////////
///////  CParty  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CParty_H
#define CParty_H
#include "SHO_GS.h"
#include "CCriticalSection.h"

class TGAMESERVER_API CParty  : public CCriticalSection   { 
public: 
  short m_nMemberCNT;
  int m_iPartyEXP;
  unsigned char m_btPartyLEV;
  void LevelUP();
  bool Send_PartyUserLIST(classUSER* pUSER, unsigned long dwUserTAG);
  bool Send_gsv_PARTY_ITEM(classUSER* pPicker, CObjITEM* pItemOBJ);
  unsigned short m_wPartyWSID;
  unsigned char m_btPartyRULE;
  unsigned long m_dwLastKillTIME;
  int m_iAverageLEV;
  int m_iTotalLEV;
  unsigned char m_btItemORDERs[0x5];
  tagPartyUSER* m_pPartyUSERs[0x7];
  CParty();
  void InitPARTY();
  classUSER* GetPartyOWNER();
  bool AddEXP(CObjMOB* pMobCHAR, int iTotalEXP, int iPartyExpA, int iPartyExpB);
  bool Change_PartyOWNER(classUSER* pNewOWNER, unsigned char btReply);
  bool Change_ObjectIDX(classUSER* pUSER);
  unsigned char Add_PartyUSER(classUSER* pUSER);
  bool Sub_PartyUSER(short nPartyPOS);
  bool Kick_MEMBER(unsigned long dwDBID);
  void Member_LevelUP(short nPartyPOS, short nLevelDIFF);
  bool Give_Item2ORDER(classUSER* pTryOBJ, CObjITEM* pItemOBJ);
  bool Is_ShareMODE();
  void Share_MONEY(int iMoney);
  int GetMemberCNT();
  unsigned char GetPartyLEV();
  int GetAverageLEV();
  int GetPartyEXP();
  bool SendWhisperToPartyMembers(char* szMessage);
  bool Send_gsv_PARTY_REPLY2Members(unsigned char btReply, unsigned long dwFromIDXorTAG);
  bool SendToPartyMembers(classPACKET* pCPacket);
  bool SendToPartyMembersExceptME(classUSER* pSender, classPACKET* pCPacket);
  bool SendPartyLEVnEXP(classUSER* pUSER, unsigned char bitLevelUP);
  bool Send_gsv_CHECK_NPC_EVENT(classUSER* pTryOBJ, short nNpcIDX);
  void Set_PartyRULE(unsigned char btRULE);
  void Warp_USERS(int iZoneNO, CVec2& PosGOTO);
  void OnConnect(classUSER* pUSER);
  void OnDisconnect(classUSER* pUSER);
  virtual ~CParty();
};

#include "CIndexARRAY.h"
class TGAMESERVER_API CPartyBUFF  : public CIndexARRAY<CParty *>   { 
public: 
  CCriticalSection m_csPartyBUFF;
  CParty* m_pPartyBUFF;
  CParty* Pool_Alloc();
  void Pool_Free(CParty* pCParty);
  CPartyBUFF();
  CPartyBUFF(unsigned short wMaxPartyCNT);
  virtual ~CPartyBUFF();
  bool CreatePARTY(classUSER* pOwner);
  void DeletePARTY(CParty* pCParty);
  void OnConnect(unsigned int uiPartyIDX, classUSER* pUSER);
};

#endif

