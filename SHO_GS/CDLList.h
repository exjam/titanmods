////////////////////////////////////////////////////////////////////////
///////  CDLList<T>    class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CDLList_H
#define CDLList_H
#include "SHO_GS.h"

template <typename T>
class TGAMESERVER_API CDLList  { 


struct tagNODE   { 
	public: tagNODE * m_pPREV;
	public: tagNODE * m_pNEXT;
	public: T m_VALUE;
	public : tagNODE * GetNext();
	public : tagNODE * GetPrev();
	public : tagNODE() { }
	public : virtual ~tagNODE() { }
};

	private: int m_iSIZE;
	private: tagNODE * m_pHEAD;
	private: tagNODE * m_pTAIL;
	public : CDLList() { }
	public : ~CDLList() { }
	public : void Init();
	public : bool IsEmpty();
	public : int GetNodeCount();
	public : void ResetNode();
	public : tagNODE * GetHeadNode();
	public : tagNODE * GetTailNode();
	public : tagNODE * GetNextNode(tagNODE * Var0 );
	public : tagNODE * GetPrevNode(tagNODE * Var0 );
	public : tagNODE * AllocNAppend();
	public : tagNODE * AllocNAppend(T Var0 );
	public : void DeleteNFree(tagNODE * Var0 );
	public : void AppendNode(tagNODE * Var0 );
	public : void DeleteNode(tagNODE * Var0 );
	public : void ReplaceNode(tagNODE * Var0 , tagNODE * Var1 );
	public : void InsertNodeToPrev(tagNODE * Var0 , tagNODE * Var1 );
	public : void InsertNodeToNext(tagNODE * Var0 , tagNODE * Var1 );
	public : void AppendNodeList(CDLList<T> * Var0 );
	public : void ClearList();
	public : void ClearListNFree();
};

#endif