#include<iostream>
#include "Wilk.h"

Wilk::Wilk(int a, int b) {
	this->SetX(a);
	this->SetY(b);
	this->SetSila(9);
	this->SetInicjatywa(5);
	this->SetTyp('W');
	this->SetNiesmiertelnosc(0);
	this->SetCzasOdnowieniaNiesmiertelnosci(0);
}

void Wilk::rysowanie() {
	std::cout << "W ";
}

void Wilk::narodziny(int x, int y) {
	Wilk* dziecko = new Wilk(x, y);
	std::cout << "Dziecko ";
	dziecko->rysowanie();
	std::cout << "urodzilo sie na polu " << x << " " << y << "\n";
	this->GetSwiat()->dodajOrganizm(*dziecko);
}