#include<iostream>
#include "Zolw.h"


Zolw::Zolw(int a, int b) {
	this->SetX(a);
	this->SetY(b);
	this->SetSila(2);
	this->SetInicjatywa(1);
	this->SetTyp('Z');
	this->SetNiesmiertelnosc(0);
	this->SetCzasOdnowieniaNiesmiertelnosci(0);
}

void Zolw::rysowanie() {
	std::cout << "Z ";
}

void Zolw::narodziny(int x, int y) {
	Zolw* dziecko = new Zolw(x, y);
	std::cout << "Dziecko ";
	dziecko->rysowanie();
	std::cout << "urodzilo sie na polu " << x << " " << y << "\n";
	this->GetSwiat()->dodajOrganizm(*dziecko);
}

void Zolw::akcja() {
	bool powodzenie = false;
	int x = this->GetX();
	int y = this->GetY();
	int szerokoscSwiata = this->GetSwiat()->GetSzerokosc();
	int wysokoscSwiata = this->GetSwiat()->GetWysokosc();

	while (powodzenie == false) {
		int ruch = rand() % 16;	//w 3 przypadkach na 4 nie poruszy sie
		if ((ruch == 0) && (x < szerokoscSwiata - 1)) {
			int czyKolizja = this->GetSwiat()->szukajPoPozycji(x + 1, y);
			this->rysowanie();
			std::cout << "probuje sie ruszyc z pola " << x << " " << y << " na pole " << x + 1 << " " << y << "\n";
			if (czyKolizja == -1) {
				this->SetX(x + 1);
				powodzenie = true;
			}
			else {
				kolizja(this->GetSwiat()->szukajPoIndeksie(czyKolizja), x + 1, y);
				powodzenie = true;
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
				kolizja(this->GetSwiat()->szukajPoIndeksie(czyKolizja), x - 1, y);
				powodzenie = true;
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
				kolizja(this->GetSwiat()->szukajPoIndeksie(czyKolizja), x, y - 1);
				powodzenie = true;
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
				kolizja(this->GetSwiat()->szukajPoIndeksie(czyKolizja), x, y + 1);
				powodzenie = true;
			}
		}
		else if ((ruch > 3) && (ruch < 16)) powodzenie = true;
	}
}

int Zolw::odbicie(Organizm* przeciwnik) {
	if (przeciwnik->GetSila() < 5) {
		this->rysowanie(); std::cout << "odbija atak "; przeciwnik->rysowanie(); std::cout << "\n";
		return 1;
	}
	else return 0;
}