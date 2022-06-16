#include <iostream>
#include "BarszczSosnowskiego.h"
void BarszczSosnowskiego::rysowanie() {
	std::cout << "B ";
}

BarszczSosnowskiego::BarszczSosnowskiego(int a, int b) {
	this->SetX(a);
	this->SetY(b);
	this->SetSila(10);
	this->SetInicjatywa(0);
	this->SetTyp('B');
	this->SetNiesmiertelnosc(0);
	this->SetCzasOdnowieniaNiesmiertelnosci(0);
}

void BarszczSosnowskiego::rozsiew(int x, int y) {
	this->rysowanie();
	std::cout << "rozsiewa sie na pole " << x << " " << y << "\n";
	BarszczSosnowskiego* dziecko = new BarszczSosnowskiego(x, y);
	this->GetSwiat()->dodajOrganizm(*dziecko);
}

int BarszczSosnowskiego::obrona(Organizm* atakujacy) {
	atakujacy->rysowanie();
	std::cout << "Zostal zabiy przez B" << "\n";
	atakujacy->smierc(this->GetX(),this->GetY());
	return 1;
}
void BarszczSosnowskiego::akcja() {
	bool powodzenie = false;
	int x = this->GetX();
	int y = this->GetY();
	int szerokoscSwiata = this->GetSwiat()->GetSzerokosc();
	int wysokoscSwiata = this->GetSwiat()->GetWysokosc();
	int a = 1, b = 1, c = 1, d = 1;	//zmienne przechowujace informacje o stanie sasiednich pol
	int IndeksOrganizmuPoPrawej = this->GetSwiat()->szukajPoPozycji(x + 1, y);
	int IndeksOrganizmuPoLewej=this->GetSwiat()->szukajPoPozycji(x - 1, y);
	int IndeksOrganizmuPonizej=this->GetSwiat()->szukajPoPozycji(x, y + 1);
	int IndeksOrganizmuPowyzej=this->GetSwiat()->szukajPoPozycji(x, y - 1);
	//jezeli barszcz wykreje organizm z nim sasiadujacy, to go zabije
	if (IndeksOrganizmuPoPrawej != -1) {
		Organizm*ofiara=this->GetSwiat()->szukajPoIndeksie(IndeksOrganizmuPoPrawej);
		if (ofiara->getKrolestwo() == 'z') {
			ofiara->rysowanie();
			std::cout << " zostal zabiy przez B \n";
			ofiara->smierc(x + 1, y);
		}
	}
	if (IndeksOrganizmuPoLewej != -1) {
		Organizm* ofiara = this->GetSwiat()->szukajPoIndeksie(IndeksOrganizmuPoLewej);
		if (ofiara->getKrolestwo() == 'z') {
			ofiara->rysowanie();
			std::cout << " zostal zabiy przez B \n";
			ofiara->smierc(x - 1, y);
		}
	}
	if (IndeksOrganizmuPonizej != -1) {
		Organizm* ofiara = this->GetSwiat()->szukajPoIndeksie(IndeksOrganizmuPonizej);
		if (ofiara->getKrolestwo() == 'z') {
			ofiara->rysowanie();
			std::cout << " zostal zabiy przez B \n";
			ofiara->smierc(x, y + 1);
		}
	}
	if (IndeksOrganizmuPowyzej != -1) {
		Organizm* ofiara = this->GetSwiat()->szukajPoIndeksie(IndeksOrganizmuPowyzej);
		if (ofiara->getKrolestwo() == 'z') {
			ofiara->rysowanie();
			std::cout << " zostal zabiy przez B \n";
			ofiara->smierc(x, y - 1);
		}
	}
	while (powodzenie == false) {
		int pole = rand() % 32;
		if ((pole == 0) && (x < szerokoscSwiata - 1)) {
			a = 0;
			int czyKolizja = this->GetSwiat()->szukajPoPozycji(x + 1, y);
			if (czyKolizja == -1) {
				rozsiew(x + 1, y);
				powodzenie = true;
			}
			else a = 1;
		}
		else if ((pole == 1) && (x > 0)) {
			b = 0;
			int czyKolizja = this->GetSwiat()->szukajPoPozycji(x - 1, y);
			if (czyKolizja == -1) {
				rozsiew(x - 1, y);
				powodzenie = true;
			}
			else b = 1;
		}
		else if ((pole == 2) && (y > 0)) {
			c = 0;
			int czyKolizja = this->GetSwiat()->szukajPoPozycji(x, y - 1);
			if (czyKolizja == -1) {
				rozsiew(x, y - 1);
				powodzenie = true;
			}
			else c = 1;
		}
		else if ((pole == 3) && (y < wysokoscSwiata - 1)) {
			d = 0;
			int czyKolizja = this->GetSwiat()->szukajPoPozycji(x, y + 1);
			if (czyKolizja == -1) {
				rozsiew(x, y + 1);
				powodzenie = true;
			}
			else d = 1;
		}
		else if ((pole > 3) && (pole < 31)) powodzenie = true;
		if (a == 1 && b == 1 && c == 1 && d == 1) powodzenie = true;
	}
}