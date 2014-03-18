////////////////////////////////////////////////////////////////////////
///////  CDataPOOL  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CDataPOOL_H
#define CDataPOOL_H
#include "SHO_GS.h"
#include "CCriticalSection.h"
#include "classSLLIST.h"

template <typename T>
class TGAMESERVER_API CDataPOOL  : public CCriticalSection   { 

	struct CDataNODE  : public T   { 
	public: 
		bool m_POOL_bUsed;
		CDataNODE * m_POOL_pNextNODE;
		CDataNODE() { }
		~CDataNODE() { }
	};

	protected: unsigned int m_uiTotalDataCNT;
	protected: unsigned int m_uiIncDataCNT;
	protected: int m_iUsedCNT;
	protected: CStrVAR m_PoolName;
	protected: classSLLIST<CDataNODE *> m_BlockLIST;
	protected: CDataNODE * m_pHeadNODE;
	protected: CDataNODE * m_pTailNODE;
	protected : CDataNODE * Create(unsigned int Var0 );
	public : char * GetPoolNAME();
	public : int GetUsedCNT();
public : CDataPOOL( ) { }
	public : CDataPOOL(char * Var0 , unsigned int Var1 , unsigned int Var2 ) { }
public : virtual ~CDataPOOL() { }
	public : T * Pool_Alloc();
	public : void Pool_Free(T * Var0 );
};


#endif