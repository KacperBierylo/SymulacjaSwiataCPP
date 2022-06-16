#include <iostream>
#include "Mlecz.h"
void Mlecz::rysowanie() {
	std::cout << "M ";
}

Mlecz::Mlecz(int a, int b) {
	this->SetX(a);
	this->SetY(b);
	this->SetSila(0);
	this->SetInicjatywa(0);
	this->SetTyp('M');
	this->SetNiesmiertelnosc(0);
	this->SetCzasOdnowieniaNiesmiertelnosci(0);
}

void Mlecz::rozsiew(int x, int y) {
	this->rysowanie();
	std::cout << "rozsiewa sie na pole " << x << " " << y << "\n";
	Mlecz* dziecko = new Mlecz(x, y);
	this->GetSwiat()->dodajOrganizm(*dziecko);
}

void Mlecz::akcja() {
	int proby = 0;	//podejmuje 3 proby rozsiania sie
	bool powodzenie = false;
	int x = this->GetX();
	int y = this->GetY();
	int szerokoscSwiata = this->GetSwiat()->GetSzerokosc();
	int wysokoscSwiata = this->GetSwiat()->GetWysokosc();
	int a = 0, b = 0, c = 0, d = 0;	//zmienne informujace czy rozsianie sie na dane pole jest mozliwe
	while (powodzenie == false) {
		int pole = rand() % 32;
		if ((pole == 0) && (x < szerokoscSwiata - 1)) {
			
			int czyKolizja = this->GetSwiat()->szukajPoPozycji(x + 1, y);
			if (czyKolizja == -1) {
				rozsiew(x + 1, y);
				powodzenie = true;
			}
			else a = 1;
		}
		else if ((pole == 1) && (x > 0)) {
			
			int czyKolizja = this->GetSwiat()->szukajPoPozycji(x - 1, y);
			if (czyKolizja == -1) {
				rozsiew(x - 1, y);
				powodzenie = true;
			}
			else b = 1;
		}
		else if ((pole == 2) && (y > 0)) {
			
			int czyKolizja = this->GetSwiat()->szukajPoPozycji(x, y - 1);
			if (czyKolizja == -1) {
				rozsiew(x, y - 1);
				powodzenie = true;
			}
			else c = 1;
		}
		else if ((pole == 3) && (y < wysokoscSwiata - 1)) {
			
			int czyKolizja = this->GetSwiat()->szukajPoPozycji(x, y + 1);
			if (czyKolizja == -1) {
				rozsiew(x, y + 1);
				powodzenie = true;
			}
			else d = 1;
		}
		else if ((pole > 3) && (pole <= 31)) {
			proby++; 
		}
		if (a == 1 && b == 1 && c == 1 && d == 1) powodzenie = true;
		if (proby >= 3) powodzenie = true;
	}
}