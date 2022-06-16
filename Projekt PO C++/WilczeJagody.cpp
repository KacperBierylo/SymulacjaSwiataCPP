#include <iostream>
#include "WilczeJagody.h"
void WilczeJagody::rysowanie() {
	std::cout << "J ";
}

WilczeJagody::WilczeJagody(int a, int b) {
	this->SetX(a);
	this->SetY(b);
	this->SetSila(99);
	this->SetInicjatywa(0);
	this->SetTyp('J');
	this->SetNiesmiertelnosc(0);
	this->SetCzasOdnowieniaNiesmiertelnosci(0);
}

void WilczeJagody::rozsiew(int x, int y) {
	this->rysowanie();
	std::cout << "rozsiewa sie na pole " << x << " " << y << "\n";
	WilczeJagody* dziecko = new WilczeJagody(x, y);
	this->GetSwiat()->dodajOrganizm(*dziecko);
}

int WilczeJagody::obrona(Organizm* atakujacy) {
	atakujacy->rysowanie();
	std::cout << "Zostal zabiy przez J" << "\n";
	atakujacy->smierc(this->GetX(),this->GetY());
	return 1;
}
