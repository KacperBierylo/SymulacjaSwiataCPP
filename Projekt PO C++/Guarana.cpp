#include <iostream>
#include "Guarana.h"
void Guarana::rysowanie() {
	std::cout << "G ";
}

Guarana::Guarana(int a, int b) {
	this->SetX(a);
	this->SetY(b);
	this->SetSila(0);
	this->SetInicjatywa(0);
	this->SetTyp('G');
	this->SetNiesmiertelnosc(0);
	this->SetCzasOdnowieniaNiesmiertelnosci(0);
}

void Guarana::rozsiew(int x, int y) {
	this->rysowanie();
	std::cout << "rozsiewa sie na pole " << x << " " << y << "\n";
	Guarana* dziecko = new Guarana(x, y);
	this->GetSwiat()->dodajOrganizm(*dziecko);
}

int Guarana::obrona(Organizm* atakujacy) {
	int silaAtakujacego = atakujacy->GetSila();
	int nowaSila = silaAtakujacego + 3;
	atakujacy->SetSila(nowaSila);
	std::cout << "Sila ";
	atakujacy->rysowanie();
	std::cout << "zostala zwiekszona o 3\n";
	return 0;
}
