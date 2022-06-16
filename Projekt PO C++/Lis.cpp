#include<iostream>
#include "Lis.h"


Lis::Lis(int a, int b) {
	this->SetX(a);
	this->SetY(b);
	this->SetSila(3);
	this->SetInicjatywa(7);
	this->SetTyp('L');
	this->SetNiesmiertelnosc(0);
	this->SetCzasOdnowieniaNiesmiertelnosci(0);
}

void Lis::rysowanie() {
	std::cout << "L ";
}

void Lis::narodziny(int x, int y) {
	Lis* dziecko = new Lis(x,y);
	std::cout << "Dziecko ";
	dziecko->rysowanie();
	std::cout << "urodzilo sie na polu " << x << " " << y << "\n";
	this->GetSwiat()->dodajOrganizm(*dziecko);
}
void Lis::akcja() {
	int a = 0, b = 0, c = 0, d = 0;	//zmienne przechowujace informacje, czy lis sprawdzil juz dane pole
	bool powodzenie = false;
	int x = this->GetX();
	int y = this->GetY();
	int szerokoscSwiata = this->GetSwiat()->GetSzerokosc();
	int wysokoscSwiata = this->GetSwiat()->GetWysokosc();
	if (x + 1 >= wysokoscSwiata)a = 1;
	if (x - 1 < 0) b = 1;
	if (y - 1 < 0) c = 1;
	if (y + 1 >= wysokoscSwiata) d = 1;
	while (powodzenie == false) {
		int ruch = rand() % 4;
		if ((ruch == 0) && (x < szerokoscSwiata - 1)) {
			int czyKolizja = this->GetSwiat()->szukajPoPozycji(x + 1, y);
			this->rysowanie();
			std::cout << "probuje sie ruszyc z pola " << x << " " << y << " na pole " << x + 1 << " " << y << "\n";
			if (czyKolizja == -1) {
				this->SetX(x + 1);
				powodzenie = true;
			}
			else {
				int sila = this->GetSila();
				int SilaPrzeciwnika = this->GetSwiat()->szukajPoIndeksie(czyKolizja)->GetSila();
				if (sila >= SilaPrzeciwnika) {
					kolizja(this->GetSwiat()->szukajPoIndeksie(czyKolizja), x + 1, y);
					powodzenie = true;
				}
				else {
					std::cout << "L zauwazyl silniejszego przeciwnika na polu docelowym.\n";
					a = 1;
				}
			}
		}
		else if ((ruch == 1) && (x > 0)) {
			int czyKolizja = this->GetSwiat()->szukajPoPozycji(x - 1, y);
			this->rysowanie();
			std::cout << "probuje sie ruszyc z pola " << x << " " << y << " na pole " << x - 1 << " " << y << "\n";
			if (czyKolizja == -1) {
				this->SetX(x - 1);
				powodzenie = true;
			}
			else {
				int sila = this->GetSila();
				int SilaPrzeciwnika = this->GetSwiat()->szukajPoIndeksie(czyKolizja)->GetSila();
				if (sila >= SilaPrzeciwnika) {
					kolizja(this->GetSwiat()->szukajPoIndeksie(czyKolizja), x - 1, y);
					powodzenie = true;
				}
				else {
					std::cout << "L zauwazyl silniejszego przeciwnika na polu docelowym.\n";
					b = 1;
				}
			}
		}
		else if ((ruch == 2) && (y > 0)) {
			int czyKolizja = this->GetSwiat()->szukajPoPozycji(x, y - 1);
			this->rysowanie();
			std::cout << "probuje sie ruszyc z pola " << x << " " << y << " na pole " << x << " " << y - 1 << "\n";
			if (czyKolizja == -1) {
				this->SetY(y - 1);
				powodzenie = true;
			}
			else {
				int sila = this->GetSila();
				int SilaPrzeciwnika = this->GetSwiat()->szukajPoIndeksie(czyKolizja)->GetSila();
				if (sila >= SilaPrzeciwnika) {
					kolizja(this->GetSwiat()->szukajPoIndeksie(czyKolizja), x, y-1);
					powodzenie = true;
				}
				else {
					std::cout << "L zauwazyl silniejszego przeciwnika na polu docelowym.\n";
					c = 1;
				}
			}
		}
		else if ((ruch == 3) && (y < wysokoscSwiata - 1)) {
			int czyKolizja = this->GetSwiat()->szukajPoPozycji(x, y + 1);
			this->rysowanie();
			std::cout << "probuje sie ruszyc z pola " << x << " " << y << " na pole " << x << " " << y + 1 << "\n";
			if (czyKolizja == -1) {
				this->SetY(y + 1);
				powodzenie = true;
			}
			else {
				int sila = this->GetSila();
				int SilaPrzeciwnika = this->GetSwiat()->szukajPoIndeksie(czyKolizja)->GetSila();
				if (sila >= SilaPrzeciwnika) {
					kolizja(this->GetSwiat()->szukajPoIndeksie(czyKolizja), x, y+1);
					powodzenie = true;
				}
				else {
					std::cout << "L zauwazyl silniejszego przeciwnika na polu docelowym.\n";
					d = 1;
				}
			}
		}
		if (a == 1 && b == 1 && c == 1 && d == 1)break;
	}

}