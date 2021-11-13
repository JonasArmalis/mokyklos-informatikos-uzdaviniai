#include "Funkcijos.h"

int main()
{
	int Pazymiai[maxKiekis][maxKiekis];
	int rows;
	double Vidurkiai[maxKiekis];

	std::ifstream fd("duomenys.txt");
	std::ofstream rezultatai("rezultatai.txt");

	skaitymas(Pazymiai, rows, fd);
	skaiciavimas(Vidurkiai, Pazymiai, rows);

	rezultatai << "Mokiniu vidurkiai: " << std::endl;
	spausdinti(Vidurkiai, rows, rezultatai);

	return 0;
}