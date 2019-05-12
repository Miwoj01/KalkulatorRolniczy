#include "pch.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

void oblicz(std::vector<std::string>& gatunki, std::vector<std::string>& grupa, std::vector<std::string>& poczatek, std::vector<std::string>& koniec, float pole)
{
}

void wypisz_pole(float pole)
{
	std::cout << "Pole: " << pole << " ha\n";
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
}

void wczytaj_grupe(std::vector<std::string>& gatunki, std::vector<std::string>& grupa, std::vector<std::string>& tabela, bool& wyjscie)
{									//tabela = koniec lub poczatek, grupa = wszystkie uzyte grupy
	std::string linia;
	std::fstream plik;
	std::vector<std::string> grupka;  // na potrzebe tej funkcji
	int nrLinii = 0;
	int nrGrupy = 0;
	int wybor;
	std::string sztuk;

	std::cout << gatunki.size() + 1 << ". Cofnij";
	std::cout << "\n    Podaj numer operacji: ";
	std::cin >> wybor;
	if (wybor > gatunki.size()) { std::cout << "Nie ma takiej operacji!\n"; wyjscie = false; }
	else {
		system("cls");
		plik.open("djp/" + gatunki[wybor - 1] + ".txt", std::ios::in);
		if (plik.good() == false)
		{
			std::cout << "!!!Nie udalo sie otworzyc plikow z gatunkami!!!\n";
		}

		std::cout << "<GRUPA TECHNOLOGICZNA>\n";

		while (std::getline(plik, linia))
		{
			if (nrLinii % 2 == 0)
			{
				nrGrupy++;
				std::cout << nrGrupy << ". " << linia << "\n";
			}
			grupka.push_back(linia);
			grupa.push_back(linia);
			nrLinii++;
		}
		plik.close();
		std::cout << "\n    Podaj numer operacji: ";
		std::cin >> wybor;
		if (nrGrupy < wybor) { std::cout << "Nie ma takiej operacji!\n"; }
		else {
			std::cout << "    Sztuk: ";
			std::cin >> sztuk;

			tabela.push_back(grupka[2 * wybor - 2]);
			tabela.push_back(sztuk);
		}
	}
}

void wypisz_poczatek(std::vector<std::string> & poczatek)
{
	system("cls");
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "Stan poczatkowy:\n\n";
	for (int i = 0; i < poczatek.size(); i++)
	{
		if (i % 2 != 0)
		{
			std::cout << " sztuk: " << poczatek[i] << "\n\n";
		}
		else {
			std::cout << "<" << poczatek[i] << "\n";
		}
	}
}

void wypisz_koniec(std::vector<std::string> & koniec)
{
	std::cout << "Stan koncowy:\n\n";
	for (int i = 0; i < koniec.size(); i++)
	{
		if (i % 2 != 0)
		{
			std::cout << " sztuk: " << koniec[i] << "\n\n";
		}
		else {
			std::cout << "<" << koniec[i] << "\n";
		}
	}
}

void wczytaj_gatunki(std::vector<std::string> & gatunki)
{
	std::string linia;
	std::fstream plik;
	plik.open("djp/gatunki.txt", std::ios::in);

	if (plik.good() == false)
	{
		std::cout << "!!!Nie udalo sie otworzyc plikow z gatunkami!!!\n";
	}

	while (std::getline(plik, linia))
	{
		gatunki.push_back(linia);
	}
	plik.close();
}

void wypisz_gatunki(std::vector<std::string> & gatunki)
{
	for (int i = 0; i < gatunki.size(); i++)
	{
		std::cout << ++i << ". ";
		std::cout << gatunki[--i] << "\n";
	}
}

void stan_poczatek(std::vector<std::string> & gatunki, std::vector<std::string> & grupa, std::vector<std::string> & poczatek, std::vector<std::string> & koniec, float pole)
{
	bool wyjscie = true;

	system("cls");
	while (wyjscie)
	{
		wypisz_poczatek(poczatek);
		wypisz_koniec(koniec);
		wypisz_pole(pole);

		std::cout << "<STAN POCZATEK>\n";
		wypisz_gatunki(gatunki);
		wczytaj_grupe(gatunki, grupa, poczatek, wyjscie);
	}
}

void stan_koniec(std::vector<std::string> & gatunki, std::vector<std::string> & grupa, std::vector<std::string> & poczatek, std::vector<std::string> & koniec, float pole)
{
	bool wyjscie = true;

	system("cls");
	while (wyjscie)
	{
		wypisz_poczatek(poczatek);
		wypisz_koniec(koniec);
		wypisz_pole(pole);

		std::cout << "<STAN KONIEC>\n";
		wypisz_gatunki(gatunki);
		wczytaj_grupe(gatunki, grupa, koniec, wyjscie);
	}
}

void djp()
{
	bool wyjscie = true;
	std::vector <std::string> poczatek;
	std::vector <std::string> koniec;
	std::vector <std::string> gatunki;
	std::vector <std::string> grupa;
	float pole = 0;

	//
	wczytaj_gatunki(gatunki);

	while (wyjscie)
	{
		int wybor;

		wypisz_poczatek(poczatek);
		wypisz_koniec(koniec);
		wypisz_pole(pole);

		std::cout << "<DJP>\n";
		std::cout << "1. Dodaj stan na poczatku roku\n";
		std::cout << "2. Dodaj stan na koniec roku\n";
		std::cout << "3. Dodaj wielkosc pola\n";
		std::cout << "4. Oblicz DJP\n";
		std::cout << "5. Resetuj\n";
		std::cout << "6. Cofnij\n";
		std::cout << "\n   Podaj numer operacji: ";
		std::cin >> wybor;

		switch (wybor)
		{
		case 1: stan_poczatek(gatunki, grupa, poczatek, koniec, pole); break;
		case 2: stan_koniec(gatunki, grupa, poczatek, koniec, pole); break;
		case 3: {std::cout << "Pole: "; std::cin >> pole; }break;
		case 4: {oblicz(gatunki, grupa, poczatek, koniec, pole); } break;
		case 5: {poczatek.clear(); koniec.clear(); } break;
		case 6: wyjscie = false;
		default: std::cout << "Nie ma takiej operacji!\n"; break;
		}
	}
}

int main()
{
	bool wyjscie = true;

	while (wyjscie)
	{
		int wybor;

		std::cout << "Witaj w kalkulatorze!\n\n";
		std::cout << "1. DJP\n";
		std::cout << "2. \n";
		std::cout << "3. Wyjscie\n";
		std::cout << "\n   Podaj numer operacji: ";
		std::cin >> wybor;

		switch (wybor)
		{
		case 1: djp(); break;
			//case 2: break;
		case 3: wyjscie = false;
		default: std::cout << "Nie ma takiej operacji\n"; break;
		}
	}
	return 0;
}