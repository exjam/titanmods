#include "TContainer.h"

CJContainer::CJContainer(){}
CJContainer::~CJContainer(){}

void CJContainer::Draw(){}
void CJContainer::Update( POINT ptMouse ){}
unsigned CJContainer::Process( unsigned uiMsg, WPARAM wParam, LPARAM lParam ){return 0;}
void CJContainer::MoveWindow( POINT pt ){}
void CJContainer::Show(){}
void CJContainer::Hide(){}
CWinCtrl*	CJContainer::Find( unsigned index ){return 0;}
CWinCtrl*	CJContainer::Find( const char * szName ){return 0;}
void		CJContainer::Add( CWinCtrl* pCtrl ){}
void		CJContainer::Remove( unsigned index ){}
void		CJContainer::RemoveAll(){}
void		CJContainer::SetChildEnable( unsigned iID, bool bEnable ){}
std_list<CWinCtrl*> & CJContainer::GetChild(){return std_list<CWinCtrl*>();}
CWinCtrl * CJContainer::GetChild(int iIndex){return 0;}
void		CJContainer::MoveCtrl2ListEnd( int iID ){}