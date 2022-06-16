#pragma once
#include "Swiat.h"
struct Wspolrzedne {
	int x, y;
};
class Swiat;
class Organizm {
private:
	int sila;
	int inicjatywa;
	Swiat* swiat;
	Wspolrzedne polozenie;
	char typ;
	int niesmiertelnosc;
	int czasOdnowieniaNiesmiertelnosci;
public:

	virtual void akcja()=0;
	virtual void kolizja(Organizm* przeciwnik,int newX, int newY)=0;
	virtual void rysowanie()=0;
	void SetX(int x);
	void SetY(int y);
	int GetX();
	int GetY();
	Swiat*  GetSwiat();
	void SetSwiat(Swiat& swiat);
	int GetSila();
	void SetSila(int nowaSila);
	int GetInicjatywa();
	void SetInicjatywa(int nowaInicjatywa);
	char GetTyp();
	void SetTyp(char Ntyp);
	void smierc(int x, int y);
	void smierc();
	virtual int odbicie(Organizm* przeciwnik);
	virtual int ucieczka();
	virtual int obrona(Organizm* atakujacy);
	virtual char getKrolestwo() = 0;
	void SetNiesmiertelnosc(int n);
	int GetNiesmiertelnosc();
	void SetCzasOdnowieniaNiesmiertelnosci(int n);
	int GetCzasOdnowieniaNiesmiertelnosci();
};
