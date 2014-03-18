#ifndef TCONTAINER_H
#define TCONTAINER_H

#include "TGameCtrl.h"
#include "WinCtrl.h"

class TGAMECTRL_API CJContainer :	public CTObject
{
public:
	CJContainer();
	virtual ~CJContainer();

	void Draw();
	void Update( POINT ptMouse );
	unsigned Process( unsigned uiMsg, WPARAM wParam, LPARAM lParam );
	void MoveWindow( POINT pt );
	void Show();
	void Hide();

	CWinCtrl*	Find( unsigned index );
	CWinCtrl*	Find( const char * szName );

	void		Add( CWinCtrl* pCtrl );
	void		Remove( unsigned index );
	void		RemoveAll();
	void		SetChildEnable( unsigned iID, bool bEnable );

	std_list<CWinCtrl*> & GetChild();
	CWinCtrl * GetChild(int iIndex);

	void		MoveCtrl2ListEnd( int iID );

	std_list< CWinCtrl* >	m_Children;	

};

#endif