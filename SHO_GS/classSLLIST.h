////////////////////////////////////////////////////////////////////////
///////  classSLLIST  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef classSLLIST_H
#define classSLLIST_H
#include "SHO_GS.h"
#include "classSLLNODE.h"

template <typename T>
class TGAMESERVER_API classSLLIST   { 
	private: int iNodeCount;
	private: classSLLNODE<T> * m_pHEAD;
	private: classSLLNODE<T>  * m_pTAIL;
public : classSLLIST() { }
	public : void Init();
	public : bool IsEmpty();
	public : int GetNodeCount();
	public : classSLLNODE<T>  * AllocNAppend();
	public : classSLLNODE<T>  * AllocNAppend(T * Var0 );
	public : bool DeleteHeadNFree();
	public : void AppendNode(classSLLNODE<T>  * Var0 );
	public : classSLLNODE<T>  * DeleteHead();
	public : classSLLNODE<T>  * GetHeadNode();
	public : classSLLNODE<T>  * GetTailNode();
	public : classSLLNODE<T>  * GetNextNode(classSLLNODE<T> * Var0 );
	public : void AppendNodeList(classSLLIST * Var0 );
	public : void ClearList();
	public : void ClearListNFree();
};


#endif