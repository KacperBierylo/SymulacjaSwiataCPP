#pragma once
#include "Zwierze.h"
class Wilk : public Zwierze {

public:
	void rysowanie() override;
	Wilk(int a, int b);
	void narodziny(int x, int y) override;
};