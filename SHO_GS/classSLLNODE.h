////////////////////////////////////////////////////////////////////////
///////  classSLLNODE<T>  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef classSLLNODE_H
#define classSLLNODE_H
#include "SHO_GS.h"

template <typename T>
class TGAMESERVER_API classSLLNODE   { 
	public: T DATA;
	public: classSLLNODE * m_pNEXT;
	public : classSLLNODE();
	public : classSLLNODE(T Var0 );
	public : classSLLNODE(int Var0 );
};

#endif