////////////////////////////////////////////////////////////////////////
///////  CIndexARRAY<T>  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CIndexARRAY_H
#define CIndexARRAY_H
#include "SHO_GS.h"

template <typename T>
class TGAMESERVER_API CIndexARRAY  { 
  
	protected: T * m_pINDEX;
	protected: unsigned int m_uiBuffSize;
	protected: unsigned int m_uiLastSlot;
	public: int m_iUsedSlot;
	protected : virtual void Lock();
	protected : virtual void Unlock();
	protected : unsigned int GetEmptySlot();
	public : int GetEmptySlotCNT();
	public : int GetUsedSlotCNT();
	public : T GetData(unsigned int uiSlotNo );
};

#endif