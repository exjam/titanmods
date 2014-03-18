////////////////////////////////////
///////  CQuestDATA   ////////////
////////////////////////////////////
#ifndef CQuestDATA_H
#define CQuestDATA_H
#include "SHO_GS.h"
#include "classHASH.h"
#include "CStrVAR.h"
#include "STB.h"

enum eQST_RESULT {
	QST_RESULT_INVALID = 0,	// 서버에서 짤린다.
	QST_RESULT_SUCCESS,
	QST_RESULT_FAILED,		// 서버에서 실패 통보 된다.
	QST_RESULT_STOPPED,		// 서버 점검중이다.
};

class TGAMESERVER_API CQuestDATA   { 
public: 
  classHASH<CQuestTRIGGER *> m_HashQUEST;
  CStrVAR m_QuestListSTB;
  CStrVAR m_QuestFILE;
  CStrVAR m_BaseDIR;
  CStrVAR m_QuestLangSTB;
  int m_iLangCol;
  STBDATA* m_pSTB;
  bool m_bEnable;
  long m_lRefCnt;
  void LoadQuestTrigger(_iobuf* fpIN, unsigned int uiTriggerCNT, char* szFileName);
  bool LoadDATA(char* szFileName);
  STBDATA m_STB;
  bool LoadQuestTable(char* szQuestFile, char* szQuestListSTB, char* szBaseDIR, char* szQuestLangSTB, int iLangCol);
  bool LoadQuestTable();
  void Free();
  CQuestDATA(const CQuestDATA& Var1);
  CQuestDATA();
  ~CQuestDATA();
  eQST_RESULT CheckQUEST(CUserDATA* pUSER, unsigned long HashQuest, bool bDoReward, int iEventNpcIDX, CGameOBJ* pCallOBJ, short nSelectReward);
  CQuestTRIGGER* GetQuest(unsigned long HashQuest);
  void CheckAllQuest(CUserDATA* pUSER);
  bool IsEnable();
  void ToggleEnable();
  long GetRefCNT();
};

#endif

