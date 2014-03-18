////////////////////////////////////////////////////////////////////////
///////  CObjSUMMON  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CObjSUMMON_H
#define CObjSUMMON_H
#include "SHO_GS.h"
#include "CObjMOB.h"

class TGAMESERVER_API CObjSUMMON  : public CObjMOB   { 
public: 
  int m_iLevel;
  short m_nSummonedSkillIDX;
  int m_iOriATK;
  int m_iOriHIT;
  int m_iOriDEF;
  int m_iOriRES;
  int m_iOriAVOID;
  CObjSUMMON();
  virtual int Proc();
  unsigned char m_btSummonCMD;
  int m_iCallerUserObjIDX;
  unsigned long m_HashCALLER;
  void SetCallerOBJ(int iOwnerOBJ, unsigned long HashOwnerOBJ, int iOwnerLEVEL, short nSkillIDX, CObjCHAR* pOwnerAVT);
  virtual int GetCallerUsrIDX();
  virtual int GetCallerObjIDX();
  virtual unsigned long GetCallerHASH();
  virtual short GetSummonedSkillIDX();
  virtual int Get_LEVEL();
  virtual int GetOri_ATK();
  virtual int GetOri_HIT();
  virtual int GetOri_DEF();
  virtual int GetOri_RES();
  virtual int GetOri_AVOID();
  virtual ~CObjSUMMON();
};

#endif

