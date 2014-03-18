////////////////////////////////////////////////////////////////////////
///////  classDLLIST  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef classDLLIST_H
#define classDLLIST_H
#include "SHO_GS.h"

template <typename T>
class classDLLNODE   { 
	public: T DATA;
	public: classDLLNODE * m_pNEXT;
	public: classDLLNODE * m_pPREV;
public : classDLLNODE(T Var0 ) { }
public : classDLLNODE() { }
};

template <typename T>
class classDLLIST   { 
	private: int iNodeCount;
	public: classDLLNODE<T> * m_pHEAD;
	private: classDLLNODE<T> * m_pTAIL;
public : classDLLIST() { }
	public : void Init();
	public : bool IsEmpty();
	public : int GetNodeCount();
	public : void ResetNode();
	public : classDLLNODE<T> * GetHeadNode();
	public : classDLLNODE<T> * GetTailNode();
	public : classDLLNODE<T> * GetNextNode(classDLLNODE<T> * Var0 );
	public : classDLLNODE<T> * GetPrevNode(classDLLNODE<T> * Var0 );
	public : classDLLNODE<T> * AllocNAppend();
	public : classDLLNODE<T> * AllocNAppend(T Var0 );
	public : void DeleteNFree(classDLLNODE<T> * Var0 );
	public : void AppendNode(classDLLNODE<T> * Var0 );
	public : void DeleteNode(classDLLNODE<T> * Var0 );
	public : void ReplaceNode(classDLLNODE<T> * Var0 , classDLLNODE<T> * Var1 );
	public : void InsertNodeToPrev(classDLLNODE<T> * Var0 , classDLLNODE<T> * Var1 );
	public : void InsertNodeToNext(classDLLNODE<T> * Var0 , classDLLNODE<T> * Var1 );
	public : void AppendNodeList(classDLLIST<T> * Var0 );
	public : void ClearList();
	public : void ClearListNFree();
};

#endif