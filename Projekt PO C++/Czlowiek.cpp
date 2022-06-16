#include "Czlowiek.h"
#include<conio.h>
#include<iostream>
Czlowiek::Czlowiek(int a, int b) {
	this->SetX(a);
	this->SetY(b);
	this->SetSila(5);
	this->SetInicjatywa(4);
	this->SetTyp('C');
	this->SetNiesmiertelnosc(0);
	this->SetCzasOdnowieniaNiesmiertelnosci(0);
}

void Czlowiek::rysowanie() {
	if(this->GetNiesmiertelnosc()>1)std::cout << "C|";
	else std::cout << "C ";
}
void Czlowiek::akcja() {
	int ns = this->GetNiesmiertelnosc();
	if (ns > 0) this->SetNiesmiertelnosc(ns-1);
	if (this->GetCzasOdnowieniaNiesmiertelnosci() > 0) this->SetCzasOdnowieniaNiesmiertelnosci(this->GetCzasOdnowieniaNiesmiertelnosci() - 1);
	std::cout << "Pozostalo tur niesmiertelnosci: " << this->GetNiesmiertelnosc() << "	" << "czas odnowienia: " << this->GetCzasOdnowieniaNiesmiertelnosci() << std::endl;
	bool powodzenie = false;
	int x = this->GetX();
	int y = this->GetY();
	int szerokoscSwiata = this->GetSwiat()->GetSzerokosc();
	int wysokoscSwiata = this->GetSwiat()->GetWysokosc();

	while (powodzenie == false) {
		int akcja = _getch();
		if (akcja == 224) {
			int ruch = _getch();	//sterowanie
			if ((ruch == 77) && (x < szerokoscSwiata - 1)) {
				int czyKolizja = this->GetSwiat()->szukajPoPozycji(x + 1, y);	//w prawo
				if (czyKolizja == -1) {
					this->SetX(x + 1);
					powodzenie = true;
				}
				else {
					kolizja(this->GetSwiat()->szukajPoIndeksie(czyKolizja), x + 1, y);
					powodzenie = true;
				}
			}
			else if ((ruch == 75) && (x > 0)) {
				int czyKolizja = this->GetSwiat()->szukajPoPozycji(x - 1, y);	//w lewo
				if (czyKolizja == -1) {
					this->SetX(x - 1);
					powodzenie = true;
				}
				else {
					kolizja(this->GetSwiat()->szukajPoIndeksie(czyKolizja), x - 1, y);
					powodzenie = true;
				}
			}
			else if ((ruch == 72) && (y > 0)) {
				int czyKolizja = this->GetSwiat()->szukajPoPozycji(x, y - 1);	//w gore
				if (czyKolizja == -1) {
					this->SetY(y - 1);
					powodzenie = true;
				}
				else {
					kolizja(this->GetSwiat()->szukajPoIndeksie(czyKolizja), x, y - 1);
					powodzenie = true;
				}
			}
			else if ((ruch == 80) && (y < wysokoscSwiata - 1)) {
				int czyKolizja = this->GetSwiat()->szukajPoPozycji(x, y + 1);	//w dol
				if (czyKolizja == -1) {
					this->SetY(y + 1);
					powodzenie = true;
				}
				else {
					kolizja(this->GetSwiat()->szukajPoIndeksie(czyKolizja), x, y + 1);
					powodzenie = true;
				}
			}
		}
		else if (akcja == 'd') {
			if (this->GetCzasOdnowieniaNiesmiertelnosci() < 1) {
				this->SetNiesmiertelnosc(5);
				this->SetCzasOdnowieniaNiesmiertelnosci(10);
				std::cout << "Aktywowano niesmiertelnosc!\n";
			}
			else std::cout << "Umiejetnosc musi sie odnowic!\n";
			
		}
		else if (akcja == 'z') {
			this->GetSwiat()->zapisSwiata();
			std::cout << "Zapisano gre!\n";
		}
	}
}
void Czlowiek::narodziny(int x, int y) {

}

int Czlowiek::obrona(Organizm* atakujacy) {
	int silaCzlowieka = this->GetSila();
	int silaPrzeciwnika = atakujacy->GetSila();
	if (this->GetNiesmiertelnosc() > 0) {
		if (silaPrzeciwnika >= silaCzlowieka)
			this->smierc(this->GetX(),this->GetY());
			return 1;
	}
	else return 0;
}