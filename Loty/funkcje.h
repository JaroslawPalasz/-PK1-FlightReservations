#pragma once

#include "rezerwacja.h"

/** funkcja wczytuje dane z pliku wejsciowego do dynamicznie alokowanych struktur nowy_lot i nowy_pasazer,
* jesli plik nie istnieje lub nie udalo sie go otworzyc lub udalo sie wczytac wszystkie dane,
* funkcja wypisuje na ekranie stosowny komunikat
* @param p_head wskaznik na glowe listy lotow
* @param nazwa nazwa pliku wejsciowego
* @return funkcja nie zwraca niczego
*/
void wczytaj(lot *&p_head, std::string nazwa);

/** funkcja dodaje do finalnej struktury lot i pasazera
* @param p_head wskaznik na glowe listy lotow
* @param nowy_lot wskaznik na lot, ktory dodajemy do listy
* @param nowy_pasazer wskaznik na pasazera, ktorego dodajemy do listy
* @return funkcja nie zwraca niczego
*/
void dodaj_do_struktury(lot *&p_head, lot *nowy_lot, pasazer *nowy_pasazer);

/** funkcja oblicza dlugosc listy pasazerow danego lotu
* @param p_head wskaznik na glowe listy pasazerow
* @return dlugosc listy pasazerow
*/
int dlugosc(pasazer *p_head);

/** funkcja wywoluje dla kazdego lotu funkcje sortujaca pasazerow, jesli lista nie istnieje 
* funkcja wypisuje stosowny komunikat
* @param p_head wskaznik na glowe listy lotow
* @return funkcja nie zwraca niczego
*/
void sort_all(lot * &p_head);

/** funkcja sortuje liste pasazerow korzystajac z prostej metody bubble sort, 
* zamieniajac odpowiednie wskazniki danych elementow listy
* @param p_head wskaznik na liste pasazerow
* @return funkcja nie zwraca niczego
*/
void sort_pasazer(pasazer *&p_head);

/** funkcja zapisuje cala strukture : liste lotow wraz z odpowiadajacymi im listami pasazerow 
* do plikow z nazwami lotow
* @param p_head wskaznik na glowe listy
* @return funkcja nie zwraca niczego
*/
void zapisz(lot * p_head);

/** funkcja usuwa wszystkie elementy z listy pasazerow i listy lotow
* @param p_head wskaznik na glowe listy lotow
* @return funkcja nie zwraca niczego
*/
void usun_strukture(lot * & p_head);