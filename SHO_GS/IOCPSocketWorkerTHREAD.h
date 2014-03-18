////////////////////////////////////
///////  IOCPSocketWorkerTHREAD   ////////////
////////////////////////////////////
#ifndef IOCPSocketWorkerTHREAD_H
#define IOCPSocketWorkerTHREAD_H
#include "SHO_GS.h"

class TGAMESERVER_API IOCPSocketWorkerTHREAD  : public CIocpTHREAD   { 
	private: IOCPSocketSERVER * m_pIOCPSocketSERVER;
	private : virtual void STATUS_ReturnTRUE(_OVERLAPPED * Var0 , unsigned long Var1 , unsigned long Var2 );
	private : virtual void STATUS_ReturnFALSE(_OVERLAPPED * Var0 , unsigned long Var1 );

	public : IOCPSocketWorkerTHREAD(IOCPSocketSERVER * Var0 );
	public : virtual ~IOCPSocketWorkerTHREAD();
	public : virtual void * __vecDelDtor(unsigned int Var0 );
};

#endif