////////////////////////////////////////////////////////////////////////
///////  GS_CThreadSQL  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef GS_CThreadSQL_H
#define GS_CThreadSQL_H
#include "SHO_GS.h"
#include "CSqlTHREAD.h"
#include "classDLLIST.h"
#include "CHotICONS.h"
#include "CCriticalSection.h"

class sql_ZONE_DATA;
class CInventory;

struct tagSqlUSER   { 
public: 
  unsigned char m_btLogOutMODE;
  classUSER* m_pUSER;
};

#pragma pack(push, 1)
struct tagBasicETC   { 
public: 
  CVec2 m_PosSTART;
  unsigned char m_btCharRACE;
  short m_nZoneNO;
  CVec2 m_PosREVIVE;
  short m_nReviveZoneNO;
  tagPartITEM m_PartITEM[0xA];
  tagPartITEM m_RideITEM[0x4];
  unsigned char m_btCharSlotNO;
  void Init();
  void SetPartITEM(short nPartIdx, tagITEM& sITEM);
};
struct tagGrowA_BUFF   { 
public: 
  union {
	tagGrowAbility m_sGA;
	unsigned char m_btBUFF[0x180];
};
  void Init();
};
#pragma pack(pop)

class TGAMESERVER_API GS_CThreadSQL  : public CSqlTHREAD   { 
public: 
  bool ConvertBasicETC();
  bool m_bWaiting;
  CCriticalSection m_csUserLIST;
  classDLLIST<tagSqlUSER> m_AddUserLIST;
  classDLLIST<tagSqlUSER> m_RunUserLIST;
  short m_nDefaultDataCNT;
  tagBasicETC* m_pDefaultBE;
  CInventory* m_pDefaultINV;
  tagBasicAbility* m_pDefaultBA;
  tagBasicETC m_sBE;
  tagBasicINFO m_sBI;
  tagGrowA_BUFF m_sGB;
  tagSkillAbility m_sSA;
  tagQuestData m_sQD;
  CHotICONS m_HotICON;
  tagBankData m_sEmptyBANK;
  short m_nTmpWEIGHT;
  CStrVAR m_TmpSTR;
  unsigned long m_dwCurTIME;
  virtual bool Run_SqlPACKET(tagQueryDATA* pSqlPACKET);
  bool Proc_LOAD_ZONE_DATA(int iZoneNO);
  bool Proc_SAVE_ZONE_DATA(int iZoneNO, sql_ZONE_DATA* pSqlZONE);
  bool Proc_LOAD_OBJVAR(tagQueryDATA* pSqlPACKET);
  bool Proc_SAVE_OBJVAR(tagQueryDATA* pSqlPACKET);
  bool Proc_SAVE_WORLDVAR(sql_ZONE_DATA* pSqlZONE);
  bool Proc_cli_MEMO(tagQueryDATA* pSqlPACKET);
  bool Proc_cli_CHAR_LIST(tagQueryDATA* pSqlPACKET);
  bool Proc_cli_SELECT_CHAR(tagQueryDATA* pSqlPACKET);
  bool Proc_cli_CREATE_CHAR(tagQueryDATA* pSqlPACKET);
  bool Proc_cli_DELETE_CHAR(tagQueryDATA* pSqlPACKET);
  bool Proc_cli_BANK_LIST_REQ(tagQueryDATA* pSqlPACKET);
  bool Proc_cli_MALL_ITEM_REQ(tagQueryDATA* pSqlPACKET);
  void Clear_LoginTABLE();
  void Add_LoginACCOUNT(char* szAccount);
  void Sub_LoginACCOUNT(char* szAccount);
  virtual void Execute();
  GS_CThreadSQL();
  virtual ~GS_CThreadSQL();
  void Set_EVENT();
  bool IO_ZoneDATA(CZoneTHREAD* pZONE, bool bSave);
  bool IO_NpcObjDATA(CObjNPC* pObjNPC, bool bSave);
  bool IO_EventObjDATA(CObjEVENT* pObjEVENT, bool bSave);
  bool Save_WorldVAR(unsigned char* pVarBUFF, short nBuffLEN);
  bool Load_WORLDVAR(unsigned char* pVarBUFF, short nBuffLEN);
  bool Add_SqlPacketWithACCOUNT(classUSER* pUSER, t_PACKET* pPacket);
  bool Add_SqlPacketWithAVATAR(classUSER* pUSER, t_PACKET* pPacket);
  bool Add_BackUpUSER(classUSER* pUSER, unsigned char btLogOutMODE);
  bool Sql_TEST();
  bool IsWaiting();
  int WaitUserCNT();
  bool UpdateUserRECORD(classUSER* pUSER);
};

#endif

