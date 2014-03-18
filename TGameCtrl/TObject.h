#ifndef TOBJECT_H
#define TOBJECT_H

#include "TGameCtrl.h"

//! Object Class
/*!
An object class allowing one to identify unknown classes based upon it by using "toString"
*/

class TGAMECTRL_API CTObject {
public:
	CTObject();
	virtual ~CTObject(void);
	virtual const char* toString() const;

public:
	std_string mStrString;
};

#endif
