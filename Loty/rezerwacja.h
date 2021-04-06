#pragma once

#include <string>

/** element listy jednokierunkowej opisujacy pasazera lotu
* @param p_next wskaznik na nastepny element listy
* @param imie imie pasazera
* @param nazwisko nazwisko pasazera
* @param miejsce numer miejsca
*/
struct pasazer {
	pasazer * p_next;

	std::string imie;
	std::string nazwisko;
	int miejsce;
};

/** element listy jednokierunkowej opisujacy lot
* @param p_next wskaznik na nastepny element listy
* @param p_pasazerowie wskaznik na liste pasazerow
* @param symbol symbol lotu
* @param data data wylotu
* @param miasto_start miejsce wylotu
* @param miasto_koniec docelowe miasto
*/
struct lot {
	lot *p_next;
	pasazer *p_pasazerowie;

	std::string symbol;
	std::string data;
	std::string miasto_start;
	std::string miasto_koniec;
};
