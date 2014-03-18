////////////////////////////////////
///////  IOCPSocketAcceptTHREAD   ////////////
////////////////////////////////////
#ifndef IOCPSocketAcceptTHREAD_H
#define IOCPSocketAcceptTHREAD_H
#include "SHO_GS.h"

class TGAMESERVER_API IOCPSocketAcceptTHREAD  : public CAcceptTHREAD   { 
	private: IOCPSocketSERVER * m_pIOCPSocketSERVER;
	private : virtual bool AcceptSOCKET(unsigned int Var0 , sockaddr_in & Var1 );

	public : IOCPSocketAcceptTHREAD(IOCPSocketSERVER * Var0 );
	public : virtual ~IOCPSocketAcceptTHREAD();
	public : virtual void * __vecDelDtor(unsigned int Var0 );
};

#endif