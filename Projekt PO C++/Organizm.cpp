#include<Windows.h>
#include<iostream>
#include "Organizm.h"

void Organizm::SetX(int x){
	this->polozenie.x = x;
}

void Organizm::SetY(int y) {
	this->polozenie.y = y;
}

int Organizm::GetX() {
	return this->polozenie.x;
}

int Organizm::GetY() {
	return this->polozenie.y;
}
void Organizm::SetSwiat(Swiat& swiat) {
	this->swiat = &swiat;
}
Swiat* Organizm::GetSwiat() {
	return this->swiat;
}

int Organizm::GetSila() {
	return this->sila;
}
void Organizm::SetSila(int nowaSila) {
	this->sila = nowaSila;
}
int Organizm::GetInicjatywa() {
	return this->inicjatywa;
}
void Organizm::SetInicjatywa(int nowaInicjatywa) {
	this->inicjatywa = nowaInicjatywa;
}

char Organizm::GetTyp() {
	return this->typ;
}
void Organizm::SetTyp(char Ntyp) {
	this->typ = Ntyp;
}
void Organizm::smierc(int x, int y) {
	if (this->GetNiesmiertelnosc() > 0) {
		bool powodzenie = false;
		int d = 0, a = 0, s = 0, w = 0;
		if (x + 1 < this->GetSwiat()->GetSzerokosc()) {
			if (this->GetSwiat()->szukajPoPozycji(x + 1, y) == -1) d = 1;
		}
		if (x - 1 > 0) {
			if (this->GetSwiat()->szukajPoPozycji(x - 1, y) == -1) a = 1;
		}
		if (y + 1 < this->GetSwiat()->GetWysokosc()) {
			if (this->GetSwiat()->szukajPoPozycji(x, y + 1) == -1) s = 1;
		}
		if (y - 1 > 0) {
			if (this->GetSwiat()->szukajPoPozycji(x, y - 1) == -1) w = 1;
		}
	if ((d == 0) && (a == 0) && (s == 0) && (w == 0)) return;
	while (powodzenie == false) {
		int pole = rand() % 4;
		if ((pole == 0) && (d == 1)) {
			this->SetX(x + 1);
			this->SetY(y);
			powodzenie = true;
		}
		else if ((pole == 1) && (a == 1)) {
			this->SetX(x - 1);
			this->SetY(y);
			powodzenie = true;
		}
		else if ((pole == 2) && (s == 1)) {
			this->SetX(x);
			this->SetY(y + 1);
			powodzenie = true;
		}
		else if ((pole == 3) && (w == 1)) {
			this->SetX(x);
			this->SetY(y - 1);
			powodzenie = true;
		}
	}
	return;
	}

	this->GetSwiat()->usunOrganizm(*this);
}
void Organizm::smierc() {
	if (this->GetNiesmiertelnosc() > 0) {
		this->rysowanie(); std::cout << " uniknal smierci, bo byl w stanie niesmiertelnosci.\n";
		return;
	}
	this->GetSwiat()->usunOrganizm(*this);
}

int Organizm::odbicie(Organizm* przeciwnik) {
	return 0;
}

int Organizm::ucieczka() {
	return 0;
}

int Organizm::obrona(Organizm* atakujacy) {
	return 0;
}

void Organizm::SetNiesmiertelnosc(int n) {
	this->niesmiertelnosc = n;
}

int Organizm::GetNiesmiertelnosc() {
	return this->niesmiertelnosc;
}

void Organizm::SetCzasOdnowieniaNiesmiertelnosci(int n) {
	this->czasOdnowieniaNiesmiertelnosci = n;
}

int Organizm::GetCzasOdnowieniaNiesmiertelnosci() {
	return this->czasOdnowieniaNiesmiertelnosci;
}