#pragma once
#include "Roslina.h"
class BarszczSosnowskiego : public Roslina {

public:
	void rysowanie() override;
	BarszczSosnowskiego(int a, int b);
	void rozsiew(int x, int y);
	int obrona(Organizm* atakujacy) override;
	void akcja() override;
};


