////////////////////////////////////////////////////////////////////////
///////  CObjAVT  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CObjAVT_H
#define CObjAVT_H
#include "SHO_GS.h"
#include "CObjCHAR.h"
#include "CUserDATA.h"

#pragma pack(push, 2)
class TGAMESERVER_API CObjAVT  : public CObjCHAR  , public CUserDATA   { 
public: 
  int Padding;
  virtual t_ObjTAG Get_TYPE();
  virtual char* Get_NAME();
  virtual bool Make_gsv_ADD_OBJECT(classPACKET* pCPacket);
  virtual short GetCur_ATK_SPD();
  virtual float GetCur_MOVE_SPEED();
  virtual unsigned char GetCur_MOVE_MODE();
  unsigned char GetCur_RIDE_MODE();
  virtual short GetCur_PartITEM(short nPartIdx);
  virtual void SetCur_PartITEM(short nPartIdx, tagITEM& sITEM);
  virtual int GetCur_R_WEAPON();
  virtual int GetCur_L_WEAPON();
  virtual int GetCur_PET_BODY();
  virtual unsigned long GetCur_IngStatusFLAG();
  virtual int GetCur_AbilityValue(unsigned short nType);
  virtual int GetCur_MaxHP();
  virtual int GetCur_MaxMP();
  virtual int GetCur_ATK();
  virtual int GetCur_DEF();
  virtual int GetCur_RES();
  virtual int GetCur_HIT();
  virtual int GetCur_AVOID();
  virtual int GetCur_CRITICAL();
  virtual int GetCur_FUEL();
  virtual void SubCur_FUEL(short nValue);
  virtual short GetCur_RACE();
  virtual void SetCur_SEX(char cValue);
  virtual void SetCur_TeamNO(int iTeamNO);
  virtual void SetCur_UNION(char cValue);
  virtual void SetCur_JoHapPOINT(unsigned char btUnionIDX, short nValue);
  virtual void AddCur_EXP(int iExp);
  virtual void UpdateCur_Ability();
  virtual CAI_OBJ* Get_CALLER();
  virtual bool Is_ALLIED(CAI_OBJ* pDestOBJ);
  virtual bool SkillChk_ACTIVE(short nSkillIDX);
  virtual void SkillUse_ABILITY(short nSkillIDX);
  virtual void Recv_ITEM(short nItemNO, short iDupCnt);
  virtual int Get_CON();
  virtual int GetAdd_RecoverHP();
  virtual int GetAdd_RecoverMP();
  void Check_PerFRAME(unsigned long dwPassTIME);
  virtual short Get_WeightRATE();
  virtual int GetANI_Stop();
  virtual int GetANI_Move();
  virtual int GetANI_Attack();
  virtual int GetANI_Die();
  virtual int GetANI_Hit();
  virtual int GetANI_Casting();
  virtual int GetANI_Skill();
  virtual int GetANI_Sitting();
  virtual int GetANI_Standing();
  virtual int GetANI_Sit();
  virtual int Get_R_WEAPON();
  int Get_L_WEAPON();
  int Get_PET_BODY();
  virtual int Def_AttackRange();
  bool SetCMD_TOGGLE(unsigned char btTYPE, bool bForce);
  virtual short Get_nAttackSPEED();
  virtual float Get_MoveSPEED();
  virtual int Get_AttackRange(short nSkillIDX);
  virtual bool IsFemale();
  virtual short IsMagicDAMAGE();
  virtual tagMOTION* Get_MOTION(short nActionIdx);
  virtual short Get_WEIGHT();
  virtual int Get_LEVEL();
  virtual int Get_EXP();
  virtual int Get_JOB();
  virtual __int64 Get_MONEY();
  virtual int Get_INT();
  virtual int Get_CHARM();
  virtual int Get_SENSE();
  virtual unsigned char Get_MoveMODE();
  virtual unsigned char Get_RideMODE();
  virtual int Get_GiveEXP();
  virtual int Get_AbilityValue(unsigned short wType);
  virtual int Get_HP();
  virtual int Get_MP();
  virtual void Set_HP(int iHP);
  virtual void Set_MP(int iMP);
  virtual int Add_HP(int iValue);
  virtual int Add_MP(int iValue);
  virtual int Sub_HP(int iValue);
  virtual int Sub_MP(int iValue);
  virtual void Add_STAMINA(short nV);
  virtual void Add_MONEY(short nV);
  virtual void Clear_SummonCNT();
  virtual void Add_SummonCNT(short nV);
  virtual void Sub_SummonCNT(short nV);
  virtual short Get_SummonCNT();
  virtual short Max_SummonCNT();
  virtual int GetCur_SummonCNT();
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
  virtual int Save_Damage(int iAttackerIDX, int iDamage);
  virtual void Dec_WeaponLife();
  virtual void Dec_EngineLife();
  virtual void Stamp_AttackTIME();
  virtual short Get_PatHP_MODE();
  virtual void Set_PatHP_MODE(short nV);
  short m_nRunSPEED;
  short m_nAtkAniSPEED;
  unsigned long m_dwGoddnessTIME;
  unsigned long m_dwPatTIME;
  unsigned long m_dwAttackTIME;
  unsigned long m_dwRecoverTIME;
  unsigned char m_btWeightRate;
	public: enum { 
		RIDE_MODE_DRIVE = 0x2,
		RIDE_MODE_GUEST = 0x4,
	}; 
	short m_nSummonCNT;
	unsigned char m_btSummonCMD;
	short m_nPatAniROW;
	short m_nPatAniCOL;
	union {
		tagPartITEM m_PartITEM[0xA];
		struct {
			tagPartITEM m_sFaceIDX;
			tagPartITEM m_sHairIDX;
			tagPartITEM m_sHelmetIDX;
			tagPartITEM m_sArmorIDX;
			tagPartITEM m_sGauntletIDX;
			tagPartITEM m_sBootsIDX;
			tagPartITEM m_sGoggleIDX;
			tagPartITEM m_sKnapsackIDX;
			tagPartITEM m_sRWeaponIDX;
			tagPartITEM m_sLWeaponIDX;
		};
	};
	union {
		tagPartITEM m_RideITEM[0x4];
		struct {
			tagPartITEM m_sFrameIDX;
			tagPartITEM m_sEngineIDX;
			tagPartITEM m_sLegIDX;
			tagPartITEM m_sArmIDX;
		};
	};
  tag_MY_CLAN m_CLAN;
  CStrVAR m_ClanNAME;
  void ClanINIT(unsigned long dwClanID, int iClanPOS);
  char* GetClanNAME();
  void SetClanNAME(char* szName);
  unsigned long GetClanID();
  void SetClanID(unsigned long dwClanID);
  unsigned long GetClanMARK();
  void SetClanMARK(unsigned long dwMark);
  unsigned char GetClanPOS();
  void SetClanPOS(int iPos);
  unsigned char GetClanLEVEL();
  void SetClanLEVEL(short nLev);
  int GetClanSCORE();
  void SetClanSCORE(int iScore);
  int GetClanCONTRIBUTE();
  void SetClanCONTRIBUTE(int iCon);
  __int64 GetClanMONEY();
  void SetClanMONEY(__int64 biM);
  short GetClanUserCNT();
  void SetClanUserCNT(short nC);
  int GetClanRATE();
  void SetClanRATE(int iR);
  virtual bool Is_ClanMASTER();

  int m_iAppliedPenaltyEXP;
  unsigned char m_btRideMODE;
  short Padding2;
  int m_iLinkedCartObjIDX;
  int m_iLinkedCartUsrIDX;
  unsigned char m_btRideATTR;
  short Padding3;
  CStrVAR m_Name;

  CObjAVT();
  virtual ~CObjAVT();
  void Set_NAME(char* szName);
  void Set_LEVEL(int iValue);
  tagITEM Get_EquipITEM(short Var1);
  short GetPartITEM(short nPartIdx);
  void SetPartITEM(short nEquipInvIDX);
  void SetPartITEM(short nPartIdx, tagITEM& sITEM);
  void SetRideITEM(short nRideInvIDX);
  virtual short GetPsv_ATKSPEED();
  void UpdateAbility();
  void Update_SPEED();
  void Resurrection(short nSkillIDX);
  classDLLNODE<CObjAVT *>* m_pTargetNODE;
  virtual char* Get_StoreTITLE();
  virtual bool Send_gsv_HP_REPLY(int Var1, int Var2);
  virtual bool Send_gsv_SET_ITEM_LIFE(short Var1, short Var2);
  virtual bool Send_gsv_SPEED_CHANGED(bool Var1);
  virtual bool Send_gsv_SETEXP(unsigned short Var1);
  virtual void Set_TargetIDX(int iTargetIndex, bool bCheckHP);
  void Set_PenalEXP(unsigned char btAddPercent);
  void Cancel_PenalEXP(unsigned char btPercent);
  bool Send_gsv_GODDNESS_MODE(unsigned char btOnOff);
  bool Add_Goddess();
  bool Del_Goddess();
  void Cal_AruaAtkSPD();
  virtual void Cal_AruaRunSPD();
  virtual void Cal_AruaMaxHP();
  virtual void Cal_AruaMaxMP();
  virtual void Cal_AruaATTACK();
  virtual void Cal_AruaHIT();
  virtual void Cal_AruaAVOID();
  virtual void Cal_AruaCRITICAL();
  void Cal_AruaRES();
  bool Is_CartDriver();
  bool Is_CartGuest();
  virtual void UpdateCartGuest();
};
#pragma pack(pop)
#endif

