#pragma once
#include "Organizm.h"
class Organizm;

class Swiat {
private:
	int wysokosc;
	int szerokosc;
	int iloscOrganizmow;
	Organizm** organizmy;
	int czyZyje;
	int pozycjaPrzedZapisem;
	int pozycjaStartowa;
public:
	Swiat (int wysokosc, int szerokosc);
	void wykonajTure();
	void rysujSwiat();
	int GetWysokosc();
	int GetSzerokosc();
	void SetIloscOrganizmow(int nowaIlosc);
	int GetIloscOrganizmow();
	void dodajOrganizm(Organizm &nowyOrganizm);
	void usunOrganizm(Organizm& martwyOrganizm);
	int szukajPoPozycji(int x, int y);
	Organizm* szukajPoIndeksie(int indeks);
	int GetCzyZyje();
	void zapisSwiata();
	void wczytanieSwiata();
	void generujSwiat();
	~Swiat();
};