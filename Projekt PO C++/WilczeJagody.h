#pragma once
#include "Roslina.h"
class WilczeJagody : public Roslina {

public:
	void rysowanie() override;
	WilczeJagody(int a, int b);
	void rozsiew(int x, int y);
	int obrona(Organizm* atakujacy) override;
};


