#include<iostream>
#include<fstream>
#include "Antylopa.h"

Antylopa::Antylopa(int a, int b) {
	this->SetX(a);
	this->SetY(b);
	this->SetSila(4);
	this->SetInicjatywa(4);
	this->SetTyp('A');
	this->SetNiesmiertelnosc(0);
	this->SetCzasOdnowieniaNiesmiertelnosci(0);
}

void Antylopa::rysowanie() {
	std::cout << "A ";
}

void Antylopa::narodziny(int x, int y) {
	Antylopa* dziecko = new Antylopa(x,y);
	std::cout << "Dziecko ";
	dziecko->rysowanie();
	std::cout << "urodzilo sie na polu " << x << " " << y << "\n";
	this->GetSwiat()->dodajOrganizm(*dziecko);
}

void Antylopa::akcja() {
	std::ofstream log("log.txt", std::ios_base::app);
	bool powodzenie = false;
	int x = this->GetX();
	int y = this->GetY();
	int szerokoscSwiata = this->GetSwiat()->GetSzerokosc();
	int wysokoscSwiata = this->GetSwiat()->GetWysokosc();

	while (powodzenie == false) {
		int ruch = rand() % 4;
		if ((ruch == 0) && (x < szerokoscSwiata - 2)) {
			int czyKolizja = this->GetSwiat()->szukajPoPozycji(x + 2, y);
			this->rysowanie();
			std::cout << "probuje ruszyc sie z pola " << x << " " << y << " na pole " << x + 2 << " " << y << "\n";
			if (czyKolizja == -1) {
				this->SetX(x + 2);
				powodzenie = true;
			}
			else {
				kolizja(this->GetSwiat()->szukajPoIndeksie(czyKolizja), x + 2, y);
				powodzenie = true;
			}
		}
		else if ((ruch == 1) && (x > 1)) {
			int czyKolizja = this->GetSwiat()->szukajPoPozycji(x - 2, y);
			this->rysowanie();
			std::cout<< "probuje ruszyc sie z pola " << x << " " << y << " na pole " << x - 2 << " " << y << "\n";
			if (czyKolizja == -1) {
				this->SetX(x - 2);
				powodzenie = true;
			}
			else {
				kolizja(this->GetSwiat()->szukajPoIndeksie(czyKolizja), x - 2, y);
				powodzenie = true;
			}
		}
		else if ((ruch == 2) && (y > 1)) {
			int czyKolizja = this->GetSwiat()->szukajPoPozycji(x, y - 2);
			this->rysowanie();
			std::cout<<  "probuje ruszyc sie z pola " << x << " " << y << " na pole " << x << " " << y - 2 << "\n";
			if (czyKolizja == -1) {
				this->SetY(y - 2);
				powodzenie = true;
			}
			else {
				kolizja(this->GetSwiat()->szukajPoIndeksie(czyKolizja), x, y - 2);
				powodzenie = true;
			}
		}
		else if ((ruch == 3) && (y < wysokoscSwiata - 2)) {
			int czyKolizja = this->GetSwiat()->szukajPoPozycji(x, y + 2);
			this->rysowanie();
			std::cout<< "probuje ruszyc sie z pola " << x << " " << y << " na pole " << x << " " << y + 2 << "\n";
			if (czyKolizja == -1) {
				this->SetY(y + 2);
				powodzenie = true;
			}
			else {
				kolizja(this->GetSwiat()->szukajPoIndeksie(czyKolizja), x, y + 2);
				powodzenie = true;
			}
		}
	}
}

int Antylopa::ucieczka() {
	int szerokoscSwiata = this->GetSwiat()->GetSzerokosc();
	int wysokoscSwiata = this->GetSwiat()->GetWysokosc();
int rezultat = rand() % 2;
if (rezultat == 0) return 0;
else {
	int x = this->GetX();
	int y = this->GetY();
	if ((this->GetSwiat()->szukajPoPozycji(x + 1, y) == -1)&&(x + 1 < szerokoscSwiata)) {
		this->SetX(x + 1);
		this->rysowanie(); std::cout << "ucieka z pola " << x << " " << y << " na pole " << x + 1 << " " << y << "\n";
	}
	else if ((this->GetSwiat()->szukajPoPozycji(x - 1, y) == -1) && (x - 1 >= 0)){
		this->SetX(x - 1);
		this->rysowanie(); std::cout << "ucieka z pola " << x << " " << y << " na pole " << x - 1 << " " << y << "\n";
	}
	else if ((this->GetSwiat()->szukajPoPozycji(x, y + 1) == -1) && (y + 1 < wysokoscSwiata)){
		this->SetY(y + 1);
		this->rysowanie(); std::cout << "ucieka z pola " << x << " " << y << " na pole " << x << " " << y + 1 << "\n";
	}
	else if ((this->GetSwiat()->szukajPoPozycji(x, y - 1) == -1) && (x + 1 < szerokoscSwiata)&&(y-1 >= 0)){
		this->SetY(y - 1);
		this->rysowanie(); std::cout << "ucieka z pola " << x << " " << y << " na pole " << x << " " << y - 1 << "\n";
	}
	else {
		return 0;
	}
	return 1;
}
}