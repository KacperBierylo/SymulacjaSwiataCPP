#pragma once
#include"Zwierze.h"
class Antylopa : public Zwierze {

public:
	void rysowanie() override;
	Antylopa(int a, int b);
	void akcja() override;
	void narodziny(int x, int y) override;
	int ucieczka() override;
};