#include "TabbedPane.h"

CTabbedPane::CTabbedPane(){}
CTabbedPane::~CTabbedPane(){}

unsigned int CTabbedPane::Process(UINT uiMsg, WPARAM wParam, LPARAM lParam){ return 0; }
void CTabbedPane::Update(POINT ptMouse){}
void CTabbedPane::Draw(){}
void CTabbedPane::Show(){}
void CTabbedPane::Hide(){}
void CTabbedPane::MoveWindow(POINT pos){}
bool CTabbedPane::IsInside(int x, int y){ return false; }

unsigned int CTabbedPane::AddTab(CTRadioButton* button, CJContainer* tab){ return 0; }
int CTabbedPane::GetSelectedIndex(){ return 0; }
CJContainer* CTabbedPane::GetTabContainer(int id){ return 0; }
bool CTabbedPane::IsMinimize(){ return false; }
void CTabbedPane::RemoveAll(){}
void CTabbedPane::SetMinimize(bool minimise){}
void CTabbedPane::SetMinimizeButton(CTButton* button){}
void CTabbedPane::SetMinimizeRect(const RECT& rect){}
bool CTabbedPane::SetSelectedIndex(unsigned int index){ return false; }