#pragma once
#include "Roslina.h"
class Guarana : public Roslina {

public:
	void rysowanie() override;
	Guarana(int a, int b);
	void rozsiew(int x, int y);
	int obrona(Organizm* atakujacy) override;
};

