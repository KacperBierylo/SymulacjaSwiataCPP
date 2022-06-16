#include<iostream>
#include<fstream>
#include"Swiat.h"
#include"Antylopa.h"
#include"BarszczSosnowskiego.h"
#include"Czlowiek.h"
#include"Guarana.h"
#include"Lis.h"
#include"Mlecz.h"
#include"Owca.h"
#include"Trawa.h"
#include"WilczeJagody.h"
#include"Wilk.h"
#include"Zolw.h"
Swiat::Swiat(int wysokosc, int szerokosc) {
	this->wysokosc = wysokosc;
	this->szerokosc = szerokosc;
	organizmy = new Organizm* [wysokosc * szerokosc];
	this->iloscOrganizmow = 0;
	czyZyje = 1;
	pozycjaStartowa = 0;
	pozycjaPrzedZapisem = 0;
}
int Swiat::GetSzerokosc() {
	return this->szerokosc;
}

int Swiat::GetWysokosc() {
	return this->wysokosc;
}

int Swiat::GetIloscOrganizmow() {
	return this->iloscOrganizmow;
}
void Swiat::SetIloscOrganizmow(int nowaIlosc) {
	this->iloscOrganizmow = nowaIlosc;
}
int Swiat::GetCzyZyje() {
	return czyZyje;
}
void Swiat::wykonajTure() {
	std::cout << "Nowa tura:\n";
	 czyZyje = 0;
	for (int i = pozycjaStartowa; i < this->GetIloscOrganizmow(); i++) {
		if (organizmy[i]->GetTyp() != 'C')organizmy[i]->akcja();
		if (organizmy[i]->GetTyp() == 'C') {
			pozycjaPrzedZapisem = i;
			rysujSwiat();
			organizmy[i]->akcja();
			system("cls");
			czyZyje = 1;
		}
	}
	if (pozycjaStartowa != 0) pozycjaStartowa = 0;
}

void Swiat::dodajOrganizm(Organizm& nowyOrganizm) {
	if (iloscOrganizmow == szerokosc * wysokosc) return;
	nowyOrganizm.SetSwiat(*this);
	int inicjatywa = nowyOrganizm.GetInicjatywa();
	int pozycja = iloscOrganizmow;
	for (int i = 0; i < this->iloscOrganizmow; i++) {		//organizmy sa sortowane wedlug inicjatywy przy wstawianiu do tablicy
		if (organizmy[i]->GetInicjatywa() < inicjatywa) {
			pozycja = i;
			break;
		}
	}
	for (int i = iloscOrganizmow; i > pozycja; i--) {
		organizmy[i] = organizmy[i-1];
	}
	this->organizmy[pozycja] = &nowyOrganizm;
	this->iloscOrganizmow++;
}

void Swiat::rysujSwiat() {
	for (int i = 0; i < this->GetSzerokosc()+2; i++) std::cout << "* ";
	std::cout << std::endl;
	for (int i = 0; i < this->GetWysokosc(); i++) {
		std::cout << "* ";
		for (int j = 0; j < this->GetSzerokosc(); j++) {
			bool czyWypisano = false;
			for (int k = 0; k < this->GetIloscOrganizmow(); k++) {
				if ((organizmy[k]->GetX() == j) && (organizmy[k]->GetY() == i)) {
					organizmy[k]->rysowanie();
					czyWypisano = true;
					break;
				}
			}
			if (czyWypisano == false)std::cout << ". ";
		}
		std::cout << "* ";
		std::cout << std::endl;
	}
	for (int i = 0; i < this->GetSzerokosc()+2; i++) std::cout << "* ";
	std::cout << std::endl;
}

int Swiat::szukajPoPozycji(int x, int y) {
	for (int i = 0; i < iloscOrganizmow; i++) {
		if ((organizmy[i]->GetX() == x) && (organizmy[i]->GetY() == y)) {
			return i;
		}
	}
	return -1;	//jesli nie znalazlo, zwraca -1
}

Organizm* Swiat::szukajPoIndeksie(int indeks) {
	return organizmy[indeks];
}
void Swiat::usunOrganizm(Organizm& martwyOrganizm) {
	int indeksMartwego = -1;
	for (int i = 0; i < iloscOrganizmow; i++) {
		if (organizmy[i] == &martwyOrganizm) {
			 indeksMartwego = i;
			break;
		}
	}

	for (int i = indeksMartwego; i < iloscOrganizmow-1; i++) {
		organizmy[i] = organizmy[i + 1];
	}
	delete &martwyOrganizm;
	iloscOrganizmow--;
}

void Swiat::zapisSwiata() {
	std::ofstream zapis("zapis.txt");
	zapis << wysokosc << " " << szerokosc << " " << iloscOrganizmow << " " <<pozycjaPrzedZapisem<< "\n";
	for (int i = 0; i < iloscOrganizmow; i++) {
		zapis << organizmy[i]->GetTyp() << " " << organizmy[i]->GetX() << " " << organizmy[i]->GetY() << " " << organizmy[i]->GetSila()
			<< " " << organizmy[i]->GetNiesmiertelnosc() << " " << organizmy[i]->GetCzasOdnowieniaNiesmiertelnosci() << "\n";
	}

	zapis.close();
}

void Swiat::wczytanieSwiata() {
	std::ifstream zapis("zapis.txt");
	int wysokosc,szerokosc,ilosc,niesmiertelnosc,czasOdnowieniaNiesmiertelnosci,pozycjaStart;
	zapis >> wysokosc >> szerokosc >> ilosc>>pozycjaStart;
	pozycjaStartowa = pozycjaStart;
	for (int i = 0; i < ilosc; i++) {
		char typ;
		int wspX, wspY, sila;
		zapis >> typ >> wspX >> wspY >> sila>>niesmiertelnosc>>czasOdnowieniaNiesmiertelnosci;
		if (typ == 'A') {
			Antylopa* nowyOrganizm = new Antylopa(wspX,wspY);
			nowyOrganizm->SetSila(sila);
			nowyOrganizm->SetNiesmiertelnosc(niesmiertelnosc);
			nowyOrganizm->SetCzasOdnowieniaNiesmiertelnosci(czasOdnowieniaNiesmiertelnosci);
			dodajOrganizm(*nowyOrganizm);
		}
		else if (typ == 'B') {
			BarszczSosnowskiego* nowyOrganizm = new BarszczSosnowskiego(wspX, wspY);
			nowyOrganizm->SetSila(sila);
			nowyOrganizm->SetNiesmiertelnosc(niesmiertelnosc);
			nowyOrganizm->SetCzasOdnowieniaNiesmiertelnosci(czasOdnowieniaNiesmiertelnosci);
			dodajOrganizm(*nowyOrganizm);
		}
		else if (typ == 'C') {
			Czlowiek* nowyOrganizm = new Czlowiek(wspX,wspY);
			nowyOrganizm->SetSila(sila);
			nowyOrganizm->SetNiesmiertelnosc(niesmiertelnosc+1);
			nowyOrganizm->SetCzasOdnowieniaNiesmiertelnosci(czasOdnowieniaNiesmiertelnosci+1);
			dodajOrganizm(*nowyOrganizm);
		}
		else if (typ == 'G') {
			Guarana* nowyOrganizm = new Guarana(wspX, wspY);
			nowyOrganizm->SetSila(sila);
			nowyOrganizm->SetNiesmiertelnosc(niesmiertelnosc);
			nowyOrganizm->SetCzasOdnowieniaNiesmiertelnosci(czasOdnowieniaNiesmiertelnosci);
			dodajOrganizm(*nowyOrganizm);
		}
		else if (typ == 'L') {
			Lis* nowyOrganizm = new Lis(wspX, wspY);
			nowyOrganizm->SetSila(sila);
			nowyOrganizm->SetNiesmiertelnosc(niesmiertelnosc);
			nowyOrganizm->SetCzasOdnowieniaNiesmiertelnosci(czasOdnowieniaNiesmiertelnosci);
			dodajOrganizm(*nowyOrganizm);
		}
		else if (typ == 'M') {
			Mlecz* nowyOrganizm = new Mlecz(wspX, wspY);
			nowyOrganizm->SetSila(sila);
			nowyOrganizm->SetNiesmiertelnosc(niesmiertelnosc);
			nowyOrganizm->SetCzasOdnowieniaNiesmiertelnosci(czasOdnowieniaNiesmiertelnosci);
			dodajOrganizm(*nowyOrganizm);
		}
		else if (typ == 'O') {
			Owca* nowyOrganizm = new Owca(wspX, wspY);
			nowyOrganizm->SetSila(sila);
			nowyOrganizm->SetNiesmiertelnosc(niesmiertelnosc);
			nowyOrganizm->SetCzasOdnowieniaNiesmiertelnosci(czasOdnowieniaNiesmiertelnosci);
			dodajOrganizm(*nowyOrganizm);
		}
		else if (typ == 'T') {
			Trawa* nowyOrganizm = new Trawa(wspX, wspY);
			nowyOrganizm->SetSila(sila);
			nowyOrganizm->SetNiesmiertelnosc(niesmiertelnosc);
			nowyOrganizm->SetCzasOdnowieniaNiesmiertelnosci(czasOdnowieniaNiesmiertelnosci);
			dodajOrganizm(*nowyOrganizm);
		}
		else if (typ == 'J') {
			WilczeJagody* nowyOrganizm = new WilczeJagody(wspX, wspY);
			nowyOrganizm->SetSila(sila);
			nowyOrganizm->SetNiesmiertelnosc(niesmiertelnosc);
			nowyOrganizm->SetCzasOdnowieniaNiesmiertelnosci(czasOdnowieniaNiesmiertelnosci);
			dodajOrganizm(*nowyOrganizm);
		}
		else if (typ == 'W') {
			Wilk* nowyOrganizm = new Wilk(wspX, wspY);
			nowyOrganizm->SetSila(sila);
			nowyOrganizm->SetNiesmiertelnosc(niesmiertelnosc);
			nowyOrganizm->SetCzasOdnowieniaNiesmiertelnosci(czasOdnowieniaNiesmiertelnosci);
			dodajOrganizm(*nowyOrganizm);
		}
		else if (typ == 'Z') {
			Zolw* nowyOrganizm = new Zolw(wspX, wspY);
			nowyOrganizm->SetSila(sila);
			nowyOrganizm->SetNiesmiertelnosc(niesmiertelnosc);
			nowyOrganizm->SetCzasOdnowieniaNiesmiertelnosci(czasOdnowieniaNiesmiertelnosci);
			dodajOrganizm(*nowyOrganizm);
		}
	}
	zapis.close();
}

void Swiat::generujSwiat() {
	Czlowiek* nowyOgranizm = new Czlowiek(0, 0);	//czlowiek startuje z pozycji (0, 0)
	dodajOrganizm(*nowyOgranizm);
	for (int i = 0; i < this->wysokosc; i++) {
		for (int j = 0; j < this->szerokosc; j++) {
			if ((i == 0) && (j == 0)) j = 1;	//pominiecie pola czlowieka
			int los = rand() % 100;		//dla kazdego pola 10% szans na pojawienie sie losowego organizmu
			if (los == 0) {
				Antylopa* nowyOrganizm = new Antylopa(j, i);
				dodajOrganizm(*nowyOrganizm);
			}
			else if (los == 1) {
				BarszczSosnowskiego* nowyOrganizm = new BarszczSosnowskiego(j, i);
				dodajOrganizm(*nowyOrganizm);
			}
			else if (los == 2) {
				Guarana* nowyOrganizm = new Guarana(j, i);
				dodajOrganizm(*nowyOrganizm);
			}
			else if (los == 3) {
				Lis* nowyOrganizm = new Lis(j, i);
				dodajOrganizm(*nowyOrganizm);
			}
			else if (los == 4) {
				Mlecz* nowyOrganizm = new Mlecz(j, i);
				dodajOrganizm(*nowyOrganizm);
			}
			else if (los == 5) {
				Owca* nowyOrganizm = new Owca(j, i);
				dodajOrganizm(*nowyOrganizm);
			}
			else if (los == 6) {
				Trawa* nowyOrganizm = new Trawa(j, i);
				dodajOrganizm(*nowyOrganizm);
			}
			else if (los == 7) {
				WilczeJagody* nowyOrganizm = new WilczeJagody(j, i);
				dodajOrganizm(*nowyOrganizm);
			}
			else if (los == 8) {
				Wilk* nowyOrganizm = new Wilk(j, i);
				dodajOrganizm(*nowyOrganizm);
			}
			else if (los == 9) {
				Zolw* nowyOrganizm = new Zolw(j, i);
				dodajOrganizm(*nowyOrganizm);
			}
		}
	}
}

Swiat::~Swiat() {
	for (int i = 0; i < iloscOrganizmow; i++) {
		delete organizmy[i];
	}
	delete[] organizmy;
}