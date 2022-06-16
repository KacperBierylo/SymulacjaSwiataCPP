#pragma once
#include "Zwierze.h"
class Lis : public Zwierze {

public:
	void rysowanie() override;
	Lis(int a, int b);
	void narodziny(int x, int y) override;
	void akcja() override;
};