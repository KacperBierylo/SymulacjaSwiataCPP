#include<iostream>
#include "Owca.h"


Owca::Owca(int a, int b) {
	this->SetX(a);
	this->SetY(b);
	this->SetSila(4);
	this->SetInicjatywa(4);
	this->SetTyp('O');
	this->SetNiesmiertelnosc(0);
	this->SetCzasOdnowieniaNiesmiertelnosci(0);
}

void Owca::rysowanie() {
	std::cout << "O ";
}

void Owca::narodziny(int x, int y) {
	Owca* dziecko = new Owca(x, y);
	std::cout << "Dziecko ";
	dziecko->rysowanie();
	std::cout << "urodzilo sie na polu " << x << " " << y << "\n";
	this->GetSwiat()->dodajOrganizm(*dziecko);
}