#include <iostream>
#include "Trawa.h"
void Trawa::rysowanie() {
	std::cout << "T ";
}

Trawa::Trawa(int a, int b) {
	this->SetX(a);
	this->SetY(b);
	this->SetSila(0);
	this->SetInicjatywa(0);
	this->SetTyp('T');
	this->SetNiesmiertelnosc(0);
	this->SetCzasOdnowieniaNiesmiertelnosci(0);
}

void Trawa::rozsiew(int x, int y) {
	this->rysowanie();
	std::cout << "rozsiewa sie na pole " << x << " " << y << "\n";
	Trawa* dziecko = new Trawa(x, y);
	this->GetSwiat()->dodajOrganizm(*dziecko);
}