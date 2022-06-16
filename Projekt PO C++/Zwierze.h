#pragma once
#include "Organizm.h"

class Zwierze :public Organizm {

public:
	void rysowanie() override;
	void akcja() override;
	void kolizja(Organizm* przeciwnik, int newX, int newY) override;
	virtual void narodziny(int x, int y)=0; 
	char getKrolestwo() override;
};