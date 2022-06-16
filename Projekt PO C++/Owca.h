#pragma once
#include"Zwierze.h"
class Owca : public Zwierze {

public:
	void rysowanie() override;
	Owca(int a, int b);
	void narodziny(int x, int y) override;
};
