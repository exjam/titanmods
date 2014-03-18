#ifndef IOBSERVER_H
#define IOBSERVER_H

class CObservable;
class CTObject;

class IObserver {
public:
	virtual void Update(CObservable* pObservable, CTObject* pObj) = 0;	
};

#endif
