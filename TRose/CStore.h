#ifndef CSTORE_H
#define CSTORE_H

#include "../Shared/Templates.hpp"

class CStore {
public:
	static CStore* Instance(){
		return CallStaticFunction<CStore*>(0x0045D780);
	}

	int CStore::GetUnionNo(){
		return CallMemberFunction<CStore, int>(0x0045D1F0, this);
	}
};

#endif