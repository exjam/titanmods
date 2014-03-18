////////////////////////////////////////////////////////////////////////
///////  CObjAI  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CObjAI_H
#define CObjAI_H
#include "SHO_GS.h"
#include "CGameOBJ.h"
#include "CAI_OBJ.h"
#include "CObjTARGET.h"

class CZoneTHREAD;
class CObjCHAR;

class TGAMESERVER_API CObjAI  : public CGameOBJ  , public CAI_OBJ  , public CObjTARGET   { 
public: 
  unsigned short m_wState;
  unsigned short m_wCommand;
  unsigned short m_wBeforeCMD;
  virtual CZoneTHREAD* GetCur_ZONE();
  virtual bool IsInRANGE(CObjCHAR* Var1, int Var2);
  virtual void ActionEVENT(int Var1);
  virtual void Adjust_HEIGHT();
  virtual int GetCurrentFrame();
  virtual bool Set_MOTION(short Var1, float Var2, float Var3, bool Var4);
  virtual int GetANI_Stop();
  virtual int GetANI_Die();
  virtual int GetANI_Hit();
  virtual int GetANI_Move();
  virtual int GetANI_Attack();
  virtual int GetANI_Casting();
  virtual int GetANI_Skill();
  virtual int GetANI_Sitting();
  virtual int GetANI_Standing();
  virtual int GetANI_Sit();
  virtual int Def_AttackRange();
  virtual int Get_R_WEAPON();
  virtual bool Attack_START(CObjCHAR* Var1);
  virtual bool Skill_START(CObjCHAR* Var1);
  virtual bool Casting_START(CObjCHAR* Var1);
  virtual void Casting_END();
  virtual bool ToggleRunMODE();
  virtual bool ToggleSitMODE();
  virtual int Get_CON();
  virtual int GetAdd_RecoverHP();
  virtual int GetAdd_RecoverMP();
  virtual short GetPsv_ATKSPEED();
  virtual short Get_nAttackSPEED();
  virtual float Get_MoveSPEED();
  virtual int Get_AttackRange(short Var1);
  virtual float Get_SCALE();
  virtual int Get_HP();
  virtual int Get_MP();
  virtual int Get_MaxHP();
  virtual int Get_MaxMP();
  virtual short Get_WeightRATE();
  virtual unsigned long GetIngDurationStateFLAG();
  virtual short GetIngDurationStateSKILL(eING_TYPE Var1);
  virtual void Set_HP(int iHP);
  virtual void Set_MP(int iMP);
  virtual bool SetCMD_ATTACK(int iServerTarget);
  virtual bool SkillChk_ACTIVE(short Var0);
  virtual void SkillUse_ABILITY(short Var0);
  virtual bool SetCMD_SIT();
  virtual bool SetCMD_STAND();
  virtual bool SetCMD_MOVE(CVec2& PosFROM, CVec2& PosTO, int iServerTarget);
  virtual void SetCMD_DIE();
  virtual bool SetCMD_Skill2SELF(short nSkillIDX);
  virtual bool SetCMD_Skill2OBJ(int iServerTarget, short nSkillIDX);
  virtual bool SetCMD_Skill2POS(CVec2& PosGOTO, short nSkillIDX);
  virtual void Do_CreatedAI();
  virtual void Do_StopAI();
  virtual void Do_AttackMoveAI(CObjCHAR* pTarget);
  virtual void Do_DamagedAI(CObjCHAR* pTarget, int iDamage);
  virtual void Do_KillAI(CObjCHAR* pTarget, int iDamage);
  virtual void Do_DeadAI(CObjCHAR* pTarget, int iDamage);
  virtual void Do_DeadEvent(CObjCHAR* pTarget);
  virtual bool Is_SameTYPE(int iType);
  virtual bool Is_TauntSTATUS(int Var1);
  virtual bool SetCMD_STOP();
  virtual bool SetCMD_MOVE2D(float fPosX, float fPosY, unsigned char btRunMODE);
  virtual void SetCMD_RUNnATTACK(int iTargetObjTAG);
  virtual bool Send_gsv_SKILL_CANCEL(unsigned char Var1);
  virtual short Get_PatHP_MODE();
  virtual void Set_PatHP_MODE(short nV);
  tagMOTION* m_pCurMOTION;
  int m_iCurMotionFRAME;
  float m_fAccMotionFRAME;
  bool Set_CurMOTION(tagMOTION* pMotion);
  bool Chg_CurMOTION(tagMOTION* pMotion);
  void Start_MOVE(float fSpeed);
  void Restart_MOVE(CVec2& PosGOTO);
  void Start_ATTACK(CObjCHAR* pTarget);
  bool Is_Attack();
  bool Is_Stop();
  char Do_SKILL(int iServerTarget, CObjCHAR* pTarget);
  bool Goto_TARGET(CObjCHAR* pTarget, int iRange);
  bool Goto_POSITION(int iRange);
  int ProcCMD_SIT();
  int ProcCMD_STOP();
  int ProcCMD_MOVE();
  int ProcCMD_PICK_ITEM();
  int ProcCMD_ATTACK();
  int ProcCMD_Skill2SELF();
  int ProcCMD_Skill2POSITION();
  int ProcCMD_Skill2OBJECT();
  short Get_RecoverHP(short nRecoverMODE);
  short Get_RecoverMP(short nRecoverMODE);
  bool m_bAttackSTART;
  bool m_bCastingSTART;
  int m_iWaitLoopCnt;
  short m_nToDoSkillIDX;
  short m_nActiveSkillIDX;
  short Get_ActiveSKILL();
  void Del_ActiveSKILL();
  int m_iActiveObject;
  short m_nDoingSkillIDX;
  float m_fRunAniSPEED;
  float m_fCurMoveSpeed;
  int m_iMoveDistance;
  CVec2 m_PosBORN;
  CVec2 m_PosMoveSTART;
  CVec2 m_PosGOTO;
  CVec2 m_MoveVEC;
  unsigned char m_bRunMODE;
  CObjAI();
  virtual ~CObjAI();
  bool ProcMotionFrame();
  void Set_STATE(unsigned short wState);
  unsigned short Get_STATE();
  unsigned short Get_COMMAND();
  void Set_COMMAND(unsigned short wCommand);
  float Get_MoveAniSPEED();
  void Reset_MoveVEC();
  float Cal_AtkAniSPEED(short nRightWeaponItemNO);
  float Cal_RunAniSPEED(short nCmPerSec);
  virtual int Get_TAG();
  virtual int Get_ObjTYPE();
  bool Is_AVATAR();
  virtual int Get_PercentHP();
  virtual CAI_OBJ* Get_TARGET(bool bCheckHP);
  virtual void Set_TargetObjIDX(int iTargetOBJ);
};

#endif

