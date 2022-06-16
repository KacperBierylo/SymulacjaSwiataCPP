#include"Roslina.h"
#include<iostream>

void Roslina::akcja() {
	bool powodzenie = false;
	int x = this->GetX();
	int y = this->GetY();
	int szerokoscSwiata = this->GetSwiat()->GetSzerokosc();
	int wysokoscSwiata = this->GetSwiat()->GetWysokosc();
	int a = 1, b = 1, c = 1, d = 1;
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

void Roslina::kolizja(Organizm* przeciwnik, int newX, int newY) {

}

char Roslina::getKrolestwo() {
	return 'r';
}