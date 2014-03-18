////////////////////////////////////////////////////////////////////////
///////  CSLList<T>  class by MaTT (c) 2009-2010 ////////////
////////////////////////////////////////////////////////////////////////
#ifndef CSLList_H
#define CSLList_H
#include "SHO_GS.h"

template <typename T>
class TGAMESERVER_API CSLList   { 

struct tagNODE   { 
	public: tagNODE * m_pNEXT;
	public: tagAtkIP m_VALUE;
	public: tagNODE * tagNODE::GetNext();
};

	private: unsigned int m_iSIZE;

	private: tagNODE * m_pHEAD;
	private: tagNODE * m_pTAIL;
public : CSLList() { }
	public : void Init();
	public : bool IsEmpty();
	public : unsigned int GetNodeCount();
	public : tagNODE * AllocNAppend();
	public : tagNODE * AllocNAppend(T Var0 );
	public : bool DeleteHeadNFree();
	public : void AppendNode(tagNODE * Var0 );
	public : tagNODE * DeleteHead();
	public : tagNODE * GetHeadNode();
	public : tagNODE * GetTailNode();
	public : tagNODE * GetNextNode(tagNODE * Var0 );
	public : void AppendNodeList(CSLList<T> * Var0 );
	public : void ClearList();
	public : void ClearListNFree();

};

#endif