#pragma once
#include "Zwierze.h"
class Czlowiek : public Zwierze {

public:
	void rysowanie() override;
	Czlowiek(int a, int b);
	void akcja() override;
	void narodziny(int x, int y) override;
	int obrona(Organizm* atakujacy) override;
};