#ifndef DLGAPPEAR_H
#define DLGAPPEAR_H

#include "Controls.h"

class CTAppearance : public CTDialog, IObserver {
public:
	enum {
		CHANGE = 10,
		RETURN = 11,
		SEX_LEFT = 20,
		FACE_LEFT = 21,
		HAIR_LEFT = 22,
		SEX_RIGHT = 30,
		FACE_RIGHT = 31,
		HAIR_RIGHT = 32,
	};

public:
	CTAppearance();
	virtual ~CTAppearance();

	virtual unsigned int Process(UINT uiMsg, WPARAM wParam, LPARAM lParam);
	virtual void Draw();
	virtual void Show();

	virtual void Update(CObservable* observable, CTObject* object){}

private:
};

#endif