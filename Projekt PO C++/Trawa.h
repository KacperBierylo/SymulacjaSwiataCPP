#pragma once
#include "Roslina.h"
class Trawa : public Roslina {

public:
	void rysowanie() override;
	Trawa(int a, int b);
	void rozsiew(int x, int y);
};
