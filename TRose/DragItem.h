#ifndef DRAGITEM_H
#define DRAGITEM_H

#include <Shared/Templates.hpp>

class CTCommand;
class CIcon;

class CDragItem
{
public:
	CDragItem() { CallMemberFunction<CDragItem, void>(0x004802D0, this); }
	~CDragItem();

	void AddTarget(int iTargetType , CTCommand* pCmd){  
		return CallMemberFunction<CDragItem, void, int, CTCommand*>(0x00480170, this, iTargetType, pCmd); 
	}

private:
	char mUnkData[0x10];
};

#endif
	/*CDragItemCreator();
	FixConstructorAddress(0x004802D0, (unsigned char*)&CDragItemCreator);
	FixMemberFuncAddress(0x00480170, &CDragItem::AddTarget);*/