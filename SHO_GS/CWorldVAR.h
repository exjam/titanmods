////////////////////////////////////////////////////////////////////////
///////  CWorldVAR  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CWorldVAR_H
#define CWorldVAR_H
#include "SHO_GS.h"

struct tagWorldVAR   { 
	union {
		struct {
			unsigned long m_dwAccTIME;
			short m_nWorldVAR[0x28];
		};
		unsigned char m_pVAR[0x1];
	};
};

class TGAMESERVER_API CWorldVAR : public tagWorldVAR  { 
public:
  CWorldVAR();
  void Inc_WorldTIME(bool bWorldServer);
  void Reset_WorldVAR(unsigned char* pVAR);
  int Get_WorldVAR(short nVarIDX);
  virtual void Set_WorldVAR(short nVarIDX, short nValue);
  virtual bool Save_WorldVAR();
};

#endif