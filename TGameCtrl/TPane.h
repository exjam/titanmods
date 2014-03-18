#ifndef _CTPane_
#define _CTPane_
#include "winctrl.h"
#include "TContainer.h"

class TGAMECTRL_API CTPane : public CWinCtrl
{
public:
	CTPane(void);
	virtual ~CTPane(void);

	virtual void Update( POINT ptMouse );
	virtual void Draw();
	virtual unsigned Process( unsigned uiMsg, WPARAM wParam, LPARAM lParam );
	virtual void MoveWindow( POINT pt );
	virtual void Show();
	virtual void Hide();

	virtual void		AddChild( CWinCtrl* pCtrl );
	virtual void		DelChildAll();
	virtual void		DelChild( CWinCtrl* pCtrl );
	virtual CWinCtrl*	FindChild( unsigned iID );
	virtual CWinCtrl*	Find( const char * szName );
	virtual CWinCtrl*	Find( int iID );


public:
	CJContainer		m_Children;
};
#endif