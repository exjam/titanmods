////////////////////////////////////////////////////////////////////////
///////  classListBLOCK<T>  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef classListBLOCK_H
#define classListBLOCK_H
#include "SHO_GS.h"
#include "classHASH.h"

template <typename T>
class TGAMESERVER_API classListBLOCK   { 
  
	public : classHASH<T *> * m_pHashTable;

	public : classListBLOCK<T>(int Var0 );
	public : virtual ~classListBLOCK<T>();
	public : void ClearALL();
	public : virtual T * Insert(unsigned long Var0 , char * Var1 , unsigned short Var2 , unsigned long Var3 );
	public : virtual T * Search(unsigned long Var0 , char * Var1 , bool Var2 );
	public : virtual void Update(T * Var0 , unsigned short Var1 , unsigned long Var2 );
};

#endif