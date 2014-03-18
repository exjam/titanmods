////////////////////////////////////////////////////////////////////////
///////  classHASH<T>  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef classHASH_H
#define classHASH_H
#include "SHO_GS.h"

template <typename T>
struct tagHASH   { 
  public: T m_DATA;
  public: unsigned long m_ulKEY;
  public: tagHASH<T> * m_NEXT;
};

template <typename T>
class TGAMESERVER_API classHASH   { 
  private: int m_iRegCount;
  private: tagHASH<T> * * m_pTABLE;
  private: int m_iEntryCount;
  public : classHASH() { }
  public : classHASH(int Var0 ) { }
  public : ~classHASH() { }
  public : int GetTableCount();
  public : tagHASH<T> * GetEntryNode(int Var0 );
  public : int GetCount();
  public : int GetEntryCount(int Var0 );
  public : bool GetFirst(unsigned long * Var0 , T * Var1 );
  public : bool Insert(unsigned long Var0 , T Var1 );
  public : T Delete(unsigned long Var0 );
  public : bool Delete(unsigned long Var0 , T Var1 );
  public : tagHASH<T> * Search(unsigned long Var0 );
  public : tagHASH<T> * Search(unsigned long Var0 , T Var1 );
  public : tagHASH<T> * SearchContinue(tagHASH<T> * Var0 , unsigned long Var1 );
};

#endif