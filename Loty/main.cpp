#include <iostream>
#include <string>
#include "rezerwacja.h"
#include "funkcje.h"
//#include <vld.h>	//biblioteka  do wyciekow pamieci

int main(int argc, char * argv[])
{
	std::string przelacznik;
	std::string filename;

	if (argc >= 2)
	{
		przelacznik = argv[1];
		if (przelacznik == "-i")
			filename = argv[2];
		else
		{
			std::cout << "Podano zly przelacznik." << std::endl;
			return 0;
		}
	}
	else
	{
		std::cout << "Podano zbyt malo przelacznikow." << std::endl;
		return 0;
	}

	lot * p_head = nullptr;
	wczytaj(p_head, filename);
	
	sort_all(p_head);
	zapisz(p_head);

	usun_strukture(p_head);

	return 0;
}