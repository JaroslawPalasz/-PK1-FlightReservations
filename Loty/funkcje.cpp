#include <iostream>
#include <fstream>
#include <string>

#include "funkcje.h"
#include "rezerwacja.h"

void wczytaj(lot *&p_head, std::string nazwa)
{
	std::ifstream plik(nazwa);

	if (!plik || !plik.is_open())
	{
		std::cout << "Podany plik nie istnieje lub nie udalo sie go otworzyc" 
			<< std::endl;
	}

	lot * nowy_lot = nullptr;
	pasazer * nowy_pasazer = nullptr;

	while (!plik.eof())
	{
		nowy_lot = new lot;
		nowy_pasazer = new pasazer;

		plik >> nowy_lot->symbol;
		plik >> nowy_lot->data;
		plik >> nowy_lot->miasto_start;
		plik >> nowy_lot->miasto_koniec;
		nowy_lot->p_pasazerowie = nullptr;
		nowy_lot->p_next = nullptr;

		plik >> nowy_pasazer->imie;
		plik >> nowy_pasazer->nazwisko;
		plik >> nowy_pasazer->miejsce;
		nowy_pasazer->p_next = nullptr;
		
		dodaj_do_struktury(p_head, nowy_lot, nowy_pasazer);
	}
	std::cout << "Utworzono strukture." << std::endl;
	plik.close();
}

void dodaj_do_struktury(lot *& p_head, lot * nowy_lot, pasazer * nowy_pasazer)
{

	lot *p_temp = p_head;
	//szukamy lotu
	while (p_temp && p_temp->symbol != nowy_lot->symbol)
	{
		p_temp = p_temp->p_next;
	}
	//dodajemy na poczatek listy nowy element
	//nie ma lotu
	if (!p_temp)
	{
		lot * LOT = new lot;
		LOT->symbol = nowy_lot->symbol;
		LOT->miasto_start = nowy_lot->miasto_start;
		LOT->miasto_koniec = nowy_lot->miasto_koniec;

		LOT->p_next = p_head;
		p_head = LOT;
		p_head->p_pasazerowie = nullptr;

		pasazer * PASAZER = new pasazer;
		PASAZER->imie = nowy_pasazer->imie;
		PASAZER->nazwisko = nowy_pasazer->nazwisko;
		PASAZER->miejsce = nowy_pasazer->miejsce;

		PASAZER->p_next = p_head->p_pasazerowie;
		p_head->p_pasazerowie = PASAZER;

	}
	else
	{
		pasazer * p_temp1 = p_temp->p_pasazerowie;

		pasazer * PASAZER = new pasazer;
		PASAZER->imie = nowy_pasazer->imie;
		PASAZER->nazwisko = nowy_pasazer->nazwisko;
		PASAZER->miejsce = nowy_pasazer->miejsce;

		PASAZER->p_next = p_temp->p_pasazerowie;
		p_temp->p_pasazerowie = PASAZER;

	}
	delete nowy_pasazer;
	delete nowy_lot;

}

int dlugosc(pasazer * p_head)
{
	if (!p_head) return 0;

	int dlugosc = 0;

	while (p_head)
	{
		dlugosc++;
		p_head = p_head->p_next;
	}
	return dlugosc;
}

void sort_all(lot * &p_head)
{
	if (!p_head)
	{
		std::cout << "Lista lotow nie istnieje." << std::endl;
		return;
	}

	lot * p_temp = p_head;
	while (p_temp)
	{
		sort_pasazer(p_temp->p_pasazerowie);
		p_temp = p_temp->p_next;
	}
}

void sort_pasazer(pasazer *&p_head) 
{ 

	if (!p_head) return;

	pasazer *current = nullptr;
	pasazer *previous_current = nullptr;
	pasazer *p_temp = nullptr;

	int l_pasazerow = dlugosc(p_head);

	for (int i = l_pasazerow - 1; i >= 0; i--) 
	{
		current = previous_current = p_head;
		for (int j = 0; j < l_pasazerow - 1; j++) 
		{
			if (current->miejsce > current->p_next->miejsce) 
			{
				//zamiana current z current->p_next
				p_temp = current->p_next; 
				current->p_next = current->p_next->p_next;
				p_temp->p_next = current;
				//zamiana pierwszego elementu listy
				if (current == p_head)
				{
					p_head = previous_current = p_temp;
				}
				else
				{
					previous_current->p_next = p_temp;
				}
				current = p_temp; //current musi byc p_temp
			}
			previous_current = current;
			current = current->p_next;
		}
	}
}

void zapisz(lot * p_head)
{
	if (!p_head) return;

	std::string symbol = "";

	while (p_head)
	{
		symbol = p_head->symbol;
		std::ofstream plik(symbol + ".txt");

		plik << "Lot " << p_head->symbol <<  " " << p_head->miasto_start << " - " << p_head->miasto_koniec << " " << p_head->data << std::endl;
		plik << "Pasazerowie:" << std::endl;
		
		pasazer * p_temp = p_head->p_pasazerowie;
		while (p_temp)
		{
			plik << p_temp->imie << " " << p_temp->nazwisko << " Miejsce : "
				<< p_temp->miejsce << std::endl;
			p_temp = p_temp->p_next;
		}
		p_head = p_head->p_next;
	}
}

void usun_strukture(lot * & p_head)
{
	while (p_head)
	{
		lot * p_next = p_head->p_next;
		while (p_head->p_pasazerowie)
		{
			pasazer * nast = p_head->p_pasazerowie->p_next;
			
			delete p_head->p_pasazerowie;
			p_head->p_pasazerowie = nast;
		}
		delete p_head;
		p_head = p_next;
	}
	std::cout << "Usunieto strukture." << std::endl;
}