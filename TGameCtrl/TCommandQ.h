#ifndef TCOMMANDQ_H
#define TCOMMANDQ_H

#include "TGameCtrl.h"
#include "TCommand.h"

class TGAMECTRL_API CTCommandQ {
public:
	void* mVTable;//0x00
	std_list<CTCommand*>	mCommandList;//0x04
};

#endif
