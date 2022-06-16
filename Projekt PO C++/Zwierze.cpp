#include "Zwierze.h"
#include<iostream>
#include<Windows.h>

void Zwierze::rysowanie() {
	std::cout << "Z ";
}
void Zwierze::akcja() {
	bool powodzenie=false;
	int x = this->GetX();
	int y = this->GetY();
	int szerokoscSwiata = this->GetSwiat()->GetSzerokosc();
	int wysokoscSwiata = this->GetSwiat()->GetWysokosc();

		while (powodzenie == false) {
			int ruch = rand() % 4;
			if ((ruch == 0) && (x < szerokoscSwiata-1)) {
				int czyKolizja = this->GetSwiat()->szukajPoPozycji(x + 1, y);
				this->rysowanie();
				std::cout << "probuje sie ruszyc z pola " << x << " " << y << " na pole " << x + 1 << " " << y << "\n";
					if (czyKolizja == -1) {
						this->SetX(x + 1);
						powodzenie = true;
					}
					else {
						kolizja(this->GetSwiat()->szukajPoIndeksie(czyKolizja),x+1,y);
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
					kolizja(this->GetSwiat()->szukajPoIndeksie(czyKolizja),x-1,y);
					powodzenie = true;
				}
			}
			else if ((ruch == 2) && (y > 0)) {
				int czyKolizja = this->GetSwiat()->szukajPoPozycji(x, y-1);
				this->rysowanie();
				std::cout << "probuje sie ruszyc z pola " << x << " " << y << " na pole " << x << " " << y - 1 << "\n";
				if (czyKolizja == -1) {
					this->SetY(y - 1);
					powodzenie = true;
				}
				else {
					kolizja(this->GetSwiat()->szukajPoIndeksie(czyKolizja),x,y-1);
					powodzenie = true;
				}
			}
			else if ((ruch == 3) && (y < wysokoscSwiata-1)) {
				int czyKolizja = this->GetSwiat()->szukajPoPozycji(x, y + 1);
				this->rysowanie();
				std::cout << "probuje sie ruszyc z pola " << x << " " << y << " na pole " << x << " " << y + 1 << "\n";
				if (czyKolizja == -1) {
					this->SetY(y + 1);
					powodzenie = true;
				}
				else {
					kolizja(this->GetSwiat()->szukajPoIndeksie(czyKolizja),x,y+1);
					powodzenie = true;
				}
			}
		}
}

void Zwierze::kolizja(Organizm* przeciwnik, int newX, int newY) {
	//jesli funkcje obronne zwroca wartosc 1, to kolizja jest przerywana
	if(przeciwnik->obrona(this)==1) return;
	if (przeciwnik->odbicie(this) == 1) return;
	if (przeciwnik->ucieczka() == 1) {
		this->SetX(newX);
		this->SetY(newY);
		return;
	}
	if (this->GetTyp() != przeciwnik->GetTyp()) {
		int sila = this->GetSila();
		int silaPrzeciwnika = przeciwnik->GetSila();
		if (sila >= silaPrzeciwnika) {
			std::cout << "Wygral ";
			this->rysowanie();
			std::cout << "przegral ";
			przeciwnik->rysowanie();
			std::cout << "\n";
			przeciwnik->smierc();
			this->SetX(newX);
			this->SetY(newY);
		}
		else if (silaPrzeciwnika > sila) {
			std::cout << "Wygral ";
			przeciwnik->rysowanie();
			std::cout << "przegral ";
			this->rysowanie();
			std::cout << "\n";
			this->smierc(newX, newY);
		}
	}
	else {
		int w=0, s=0, a=0, d=0;	//sprawdzenie czy pola obok naleza do swiata
		if (newX <this->GetSwiat()->GetSzerokosc()-1) d = 1;
		if (newX > 0) a = 1;
		if (newY > 0) w = 1;
		if (newY < this->GetSwiat()->GetWysokosc() - 1) s = 1;

		if ((this->GetSwiat()->szukajPoPozycji(newX+1, newY) == -1)&&(d == 1)) {
			narodziny(newX + 1, newY);
		}

		else if ((this->GetSwiat()->szukajPoPozycji(newX-1, newY) == -1) && (a == 1)) {
			narodziny(newX - 1, newY);
		}

		else if ((this->GetSwiat()->szukajPoPozycji(newX, newY-1) == -1) && (w == 1)) {
			narodziny(newX, newY - 1);
		}

		else if ((this->GetSwiat()->szukajPoPozycji(newX, newY+1) == -1) && (s == 1)) {
			narodziny(newX, newY + 1);
		}
	}
}
char Zwierze::getKrolestwo() {
	return 'z';
}
