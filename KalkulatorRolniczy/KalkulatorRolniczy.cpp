#include "pch.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

void wczytaj_liste()
{
}

void wczytaj_grupe(std::vector<std::string>& gatunki, std::vector<std::string>& grupa)
{
	std::string linia;
	std::fstream plik;
	int nrLinii = 0;
	int nrGrupy = 0;
	int wybor;

	std::cout << "\n    Podaj numer operacji: ";
	std::cin >> wybor;

	plik.open("djp/" + gatunki[wybor - 1] + ".txt", std::ios::in);

	if (plik.good() == false)
	{
		std::cout << "!!!Nie udalo sie otworzyc plikow z gatunkami!!!\n";
	}

	/*while (std::getline(plik, linia))
	{
		if (nrLinii % 2 == 0)
		{
			g[nrGrupy].nazwa = linia;
		}
		else {
			x = std::stof(linia);
			g[nrGrupy].a = std::stod(linia);
			nrGrupy++;
		}
		nrLinii++;
	}*/
	plik.close();
}

void wypisz_grupe(std::vector<std::string>& grupa)
{
	for (int i = 0; i < grupa.size(); i++)
	{
		std::cout << ++i << ". ";
		std::cout << grupa[--i] << std::endl;
	}
}

void wypisz_poczatek(std::vector<std::string>& poczatek)
{
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "Stan poczatkowy:\n";
	for (int i = 0; i < poczatek.size(); i++)
	{
		std::cout << poczatek[--i] << std::endl;
	}
}

void wypisz_koniec(std::vector<std::string>& koniec)
{
	std::cout << "Stan koncowy:\n";
	for (int i = 0; i < koniec.size(); i++)
	{
		std::cout << koniec[--i] << std::endl;
	}
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
}

void wczytaj_gatunki(std::vector<std::string>& gatunki)
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

void wypisz_gatunki(std::vector<std::string>& gatunki)
{
	for (int i = 0; i < gatunki.size(); i++)
	{
		std::cout << ++i << ". ";
		std::cout << gatunki[--i] << std::endl;
	}
}

void stan_poczatek(std::vector<std::string>& gatunki, std::vector<std::string>& listaGgrupa, std::vector<std::string>& poczatek, std::vector<std::string>& koniec)
{
	bool wyjscie = true;
	std::vector <std::string> grupa;
	system("cls");
	int wybor;
	while (wyjscie)
	{
		wypisz_poczatek(poczatek);
		wypisz_koniec(koniec);

		std::cout << "<STAN POCZATEK>\n";
		wypisz_gatunki(gatunki);
		wczytaj_grupe(gatunki, grupa);
	}
}

void stan_koniec(std::vector<std::string>& gatunki, std::vector<std::string>& listaGrupa, std::vector<std::string>& poczatek, std::vector<std::string>& koniec)
{
}

void djp()
{
	bool wyjscie = true;
	std::vector <std::string> poczatek;
	std::vector <std::string> koniec;
	std::vector <std::string> gatunki;
	std::vector <std::string> listaGrupa;

	system("cls");
	wczytaj_gatunki(gatunki);

	while (wyjscie)
	{
		int wybor;

		wypisz_poczatek(poczatek);
		wypisz_koniec(koniec);

		std::cout << "<DJP>\n";
		std::cout << "1. Dodaj stan na poczatku roku\n";
		std::cout << "2. Dodaj stan na koniec roku\n";
		std::cout << "3. Dodaj wielkosc pola\n";
		std::cout << "4. Cofnij\n";
		std::cout << "\n   Podaj numer operacji: ";
		std::cin >> wybor;

		switch (wybor)
		{
		case 1: stan_poczatek(gatunki, grupa, poczatek, koniec); break;
		case 2: stan_koniec(gatunki, grupa, poczatek, koniec); break;
			//case 3: break;
		case 4: wyjscie = false;
		default: std::cout << "Nie ma takiej operacji\n"; break;
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
		std::cout << "2. Resetuj\n";
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