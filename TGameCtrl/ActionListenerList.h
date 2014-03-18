#ifndef ACTIONLISTENERLIST_H
#define ACTIONLISTENERLIST_H

#include "TGameCtrl.h"
#include "IActionListener.h"

class TGAMECTRL_API CActionListenerList {
public:
	std_list<IActionListener*> mList;
};

#endif
