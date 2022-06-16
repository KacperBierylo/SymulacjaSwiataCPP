#pragma once
#include "Organizm.h"
class Roslina : public Organizm {
	public:
	void akcja() override;
	void kolizja(Organizm* przeciwnik, int newX, int newY) override;
	virtual void rozsiew(int x, int y)=0;
	virtual void rysowanie() override=0;
	char getKrolestwo() override;
};
