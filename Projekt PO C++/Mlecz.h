#pragma once
#include "Roslina.h"
class Mlecz : public Roslina {

public:
	void rysowanie() override;
	Mlecz(int a, int b);
	void rozsiew(int x, int y);
	void akcja();
};

