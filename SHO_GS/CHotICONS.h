////////////////////////////////////////////////////////////////////////
///////  CHotICONS  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CHotICONS_H
#define CHotICONS_H
#include "SHO_GS.h"

class TGAMESERVER_API CHotICONS   { 
	union {
		public: tagHotICON m_IconLIST[0x20];
		public: tagHotICON m_IconPAGE[0x8][0x4];
	};
	public : void Init();
	public : bool RegHotICON(unsigned char Var0 , tagHotICON Var1 );
	public : void DelHotICON(unsigned char Var0 );
};

#endif