////////////////////////////////////////////////////////////////////////
///////  CAI_OBJ  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CAI_OBJ_H
#define CAI_OBJ_H
#include "SHO_GS.h"

class TGAMESERVER_API CAI_OBJ   { 
public: 
  unsigned long m_ulAICheckTIME[0x2];
  CAI_OBJ();
  unsigned long Get_AICheckTIME(int iIDX);
  void Set_AICheckTIME(int iIDX, unsigned long lCheckTIME);
  virtual float Get_CurXPOS();
  virtual float Get_CurYPOS();
  virtual float Get_BornXPOS();
  virtual float Get_BornYPOS();
  virtual int Get_TAG();
  virtual int Get_ObjTYPE();
  virtual int Get_PercentHP();
  virtual int Get_HP();
  virtual int Get_CharNO();
  virtual int Get_LEVEL();
  virtual int Get_ATK();
  virtual int Get_DEF();
  virtual int Get_RES();
  virtual int Get_HIT();
  virtual int Get_CHARM();
  virtual int Get_AVOID();
  virtual int Get_SENSE();
  virtual int Get_GiveEXP();
  virtual int Get_CRITICAL();
  virtual CAI_OBJ* Get_TARGET(bool Var1);
  virtual CAI_OBJ* Get_CALLER();
  virtual float Get_DISTANCE(CAI_OBJ* Var1);
  virtual float Get_MoveDISTANCE();
  virtual int Get_RANDOM(int Var1);
  virtual bool Change_CHAR(int Var0);
  virtual bool Create_PET(int Var0, float Var1, float Var2, int Var3, unsigned char Var4, bool Var5);
  virtual bool Is_ClanMASTER();
  virtual void Say_MESSAGE(char* Var0);
  virtual void Run_AWAY(int Var0);
  virtual void Drop_ITEM(short Var0, unsigned char Var1);
  virtual int Get_AiVAR(short Var0);
  virtual void Set_AiVAR(short Var0, int Var1);
  virtual void Recv_ITEM(short Var0, short Var1);
  virtual void Set_EMOTION(short Var0);
  virtual bool SetCMD_STOP();
  virtual bool SetCMD_MOVE2D(float Var1, float Var2, unsigned char Var3);
  virtual void SetCMD_RUNnATTACK(int Var1);
  virtual void Special_ATTACK();
  virtual CAI_OBJ* AI_FindFirstOBJ(int Var1);
  virtual CAI_OBJ* AI_FindNextOBJ();
  virtual int Get_EconomyVAR(short Var0);
  virtual int Get_WorldVAR(short Var0);
  virtual int Get_TeamNO();
  virtual bool Is_ALLIED(CAI_OBJ* pDestOBJ);
  bool Is_SameTEAM(CAI_OBJ* pDestOBJ);
  virtual unsigned char Is_DAY();
  virtual int Get_ZoneTIME();
  virtual int Get_WorldTIME();
  virtual void Set_TRIGGER(unsigned long Var0);
  virtual t_ObjTAG Get_CharObjTAG();
  virtual unsigned long Get_MagicSTATUS();
  virtual CAI_OBJ* Find_LocalNPC(int Var1);
  virtual void Set_EconomyVAR(short Var1, int Var2);
  virtual void Set_WorldVAR(short Var1, int Var2);
  virtual void Add_DAMAGE(unsigned short Var1);
  virtual bool Send_gsv_CHAT(char* Var1);
  virtual bool Send_gsv_SHOUT(char* Var1);
  virtual void Send_gsv_ANNOUNCE_CHAT(char* Var1);
  virtual bool SetCMD_Skill2SELF(short Var0, short Var1);
  virtual bool SetCMD_Skill2OBJ(int Var0, short Var1, short Var2);
};

#endif

