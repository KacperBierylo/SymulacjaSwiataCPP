#include <iostream>
#include<Windows.h>
#include<time.h>
#include<fstream>
#include "Swiat.h"
#include "Zwierze.h"
#include"Czlowiek.h"
#include "Wilk.h"
#include"Owca.h"
#include"Lis.h"
#include"Zolw.h"
#include"Antylopa.h"
#include "Roslina.h"
#include"Trawa.h"
#include"Mlecz.h"
#include"Guarana.h"
#include"WilczeJagody.h"
#include"BarszczSosnowskiego.h"

int main()
{  
    SetConsoleTitle(TEXT("Kacper Bieryło 180185"));
    srand(time(NULL));
    int wybor = 0, koniec = 0;
    int wysokosc, szerokosc;
    std::cout << "Sterowanie: poruszanie sie - strzalki, z - zapisuje stan gry, d - wlacza umiejetnosc specjalna czlowieka.\n";
   std::cout << "Aby stworzyc nowa gre wprowadz 1, aby wczytac zapisana gre wprowadz 2: ";
    while (koniec != 1) {
       std::cin >> wybor;
        if (wybor == 1) {
            std::cout << "Podaj wysokosc swiata: ";
            std::cin >> wysokosc;
            std::cout << "Podaj szerokosc swiata: ";
            std::cin >> szerokosc;
            Swiat world(wysokosc, szerokosc);
            world.generujSwiat();
            while (world.GetCzyZyje()) {
                world.wykonajTure();
            }
            world.rysujSwiat();
            koniec = 1;
            std::cout << "Koniec gry!";
        }
        else if (wybor == 2) {
            std::ifstream zapis("zapis.txt");
            if (zapis.fail()) {
                std::cout << "Nie masz zapisanego stanu gry!\n";
            }
            else {
                int wysokosc, szerokosc;
                zapis >> wysokosc >> szerokosc;
                Swiat world(wysokosc, szerokosc);
                zapis.close();
                world.wczytanieSwiata();
                while (world.GetCzyZyje()) {
                    world.wykonajTure();
                }
                world.rysujSwiat();
                koniec = 1;
                std::cout << "Koniec gry!";
            }
        }
        else {
            std::cout << "Nieznana opcja!\n";
            std::cin.clear();
            std::cin.ignore(256, '\n');
        }
        
    }
}

