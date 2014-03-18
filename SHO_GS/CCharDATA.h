////////////////////////////////////////////////////////////////////////
///////  CCharDATA  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CCharDATA_H
#define CCharDATA_H
#include "SHO_GS.h"

class TGAMESERVER_API CCharDATA   { 
	private: CStrVAR m_Name;
	private: short m_nAniCNT;
	private: tagMOTION * * m_ppAniFILE;
	public : CCharDATA();
	public : virtual ~CCharDATA();
	public : bool Load_MOBorNPC(_iobuf * Var0 , unsigned long * Var1 , short Var2 );
	public : bool IsValid();
	public : tagMOTION * GetMOTION(unsigned char Var0 );
  
};

#endif