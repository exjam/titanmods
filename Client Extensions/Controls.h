#ifndef CONTROLS_H
#define CONTROLS_H

#include <TRose\IT_MGR.h>

#include <TGameCtrl\WinCtrl.h>
#include <TGameCtrl\IObserver.h>
#include <TGameCtrl\TDialog.h>
#include <TGameCtrl\ZListBox.h>
#include <TGameCtrl\TComboBox.h>
#include <TGameCtrl\TCheckBox.h>
#include <TGameCtrl\TScrollBar.h>
#include <TGameCtrl\TPane.h>
#include <TGameCtrl\TCommand.h>
#include <TGameCtrl\TImage.h>
#include <TGameCtrl\TabbedPane.h>
#include <TGameCtrl\TContainer.h>
#include <TGameCtrl\TEditBox.h>
#include <TGameCtrl\TRadioBox.h>

extern int gQuesticonGUI;
extern int gUnlockedGUI;
extern int gBossGUI;
extern int gPageGID;
extern int gFlagRedGUI;

void PopupFatalError(char* errorMessage);
CWinCtrl* ControlInWindow(int window, int controlID);
CWinCtrl* ControlInPane(int window, int pane, int tab, int controlID);
#endif