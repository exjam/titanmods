#ifndef TCOMMAND_H
#define TCOMMAND_H

#include "TGameCtrl.h"

class CTObject;

//! A virtual Command
/*!
This basically is used instead of function pointers... No better way to explain it :)...
*/

class TGAMECTRL_API CTCommand {
public:
	CTCommand();
	virtual ~CTCommand();

	virtual	bool Exec(CTObject*) = 0;
	bool IsWaitExecSucceed();

protected:
	bool mWaitExec;//0x04
};

#endif
