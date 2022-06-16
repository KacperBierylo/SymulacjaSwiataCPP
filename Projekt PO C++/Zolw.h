#pragma once
#include "Zwierze.h"
class Zolw : public Zwierze {

public:
	void rysowanie() override;
	Zolw(int a, int b);
	void narodziny(int x, int y) override;
	void akcja() override;
	int odbicie(Organizm* przeciwnik) override;
};

