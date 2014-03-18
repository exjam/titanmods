////////////////////////////////////////////////////////////////////////
///////  CObjMOB  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CObjMOB_H
#define CObjMOB_H
#include "SHO_GS.h"
#include "CObjCHAR.h"

class TGAMESERVER_API CObjMOB  : public CObjCHAR   { 
public: 
  char m_cSkillMotionIDX;
  virtual t_ObjTAG Get_TYPE();
  virtual char* Get_NAME();
  virtual bool Make_gsv_ADD_OBJECT(classPACKET* pCPacket);
  virtual CAI_OBJ* Get_CALLER();
  virtual bool SetCMD_Skill2SELF(short nSkillIDX, short nMotion);
  virtual bool SetCMD_Skill2OBJ(int iTargetObjIDX, short nSkillIDX, short nMotion);
  virtual void Run_AWAY(int iDistance);
  virtual void Drop_ITEM(short nDropITEM, unsigned char btToOwner);
  virtual bool Change_CHAR(int iCharIDX);
  virtual void Set_EMOTION(short nEmotionIDX);
  virtual int GetANI_Stop();
  virtual int GetANI_Move();
  virtual int GetANI_Attack();
  virtual int GetANI_Die();
  virtual int GetANI_Hit();
  virtual int GetANI_Skill();
  int GetANI_Etc();
  virtual int GetANI_Casting();
  virtual int Get_R_WEAPON();
  virtual int Def_AttackRange();
  int m_iCallerMobObjIDX;
  virtual int GetCallerObjIDX();
  virtual bool SendPacketToTARGET(CObjCHAR* pAtkCHAR, classPACKET* pCPacket);
  virtual int Get_AttackRange(short nSkillIDX);
  virtual bool IsFemale();
  virtual short IsMagicDAMAGE();
  virtual tagMOTION* Get_MOTION(short nActionIdx);
  virtual classUSER* Give_EXP();
  virtual int Save_Damage(int iAttackerIDX, int iDamage);
  virtual bool Dead(CObjCHAR* pKiller);
  virtual short Get_WEIGHT();
  virtual int Get_LEVEL();
  virtual int Get_GiveEXP();
  virtual int Get_AbilityValue(unsigned short wType);
  virtual int Get_INT();
  virtual int Get_CHARM();
  virtual int Get_SENSE();
  virtual unsigned char Get_MoveMODE();
  virtual unsigned char Get_RideMODE();
  virtual short GetOri_WalkSPEED();
  virtual short GetOri_RunSPEED();
  virtual short GetOri_ATKSPEED();
  virtual int GetOri_ATK();
  virtual int GetOri_DEF();
  virtual int GetOri_RES();
  virtual int GetOri_HIT();
  virtual int GetOri_AVOID();
  virtual int GetOri_CRITICAL();
  virtual int GetOri_MaxHP();
  virtual int GetOri_MaxMP();
  virtual bool Make_gsv_SUB_OBJECT(classPACKET* pCPacket);
  virtual void Add_ToTargetLIST(CObjAVT* pAVTChar);
  virtual void Sub_FromTargetLIST(CObjAVT* pAVTChar);
  virtual unsigned short Get_ATTRIBUTE();
  CCharDATA* m_pCharMODEL;
  unsigned long m_ulAICheckTIME[0x2];
  short m_nCritical;
  int m_iAiVAR[0x5];
  classDLLIST<CObjAVT *> m_TargetLIST;
  CObjMOB();
  virtual ~CObjMOB();
  short m_nQuestIDX;
  int m_iOriMaxHP;
  short m_nSavedDamageCNT;
  tagSavedDAMAGE* m_SavedDAMAGED;
  CRegenPOINT* m_pRegenPOINT;
  bool Init(CZoneTHREAD* pZONE, short nCharIdx, float fXPos, float fYPos, int iTeamNO, CRegenPOINT* pRegenPOINT, short nQuestIDX);
  virtual int Proc();
  virtual int Get_AiVAR(short nVarIdx);
  virtual void Set_AiVAR(short nVarIdx, int iValue);
  void LockTargetLIST();
  void UnlockTargetLIST();
  virtual void Do_CreatedAI();
  virtual void Do_StopAI();
  virtual void Do_AttackMoveAI(CObjCHAR* pTarget);
  virtual void Do_DamagedAI(CObjCHAR* pTarget, int iDamage);
  virtual void Do_KillAI(CObjCHAR* pTarget, int iDamage);
  virtual void Do_DeadAI(CObjCHAR* pTarget, int iDamage);
  virtual unsigned long Get_AICheckTIME(int iIDX);
  virtual void Set_AICheckTIME(int iIDX, unsigned long lCheckTIME);
};

#endif

