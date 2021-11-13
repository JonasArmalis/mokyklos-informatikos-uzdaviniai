#include "Funkcijos.h"
#include <iomanip>

using namespace std;

void skaitymas(int Mas[][maxKiekis], int & eilutes, ifstream &data)
{
	data >> eilutes;
	for (int j = 0; j < eilutes; j++)
	{
		data >> Mas[j][0];
		for (int i = 1; i < Mas[j][0] + 1; i++)
		{
			data >> Mas[j][i];
		}
	}
}

void spausdinti2D(int Mas[][maxKiekis], int stulpeliai, int eilutes, ofstream &rez)
{
	for (int i = 0; i < eilutes; i++)
	{
		rez << "eil. nr.:" << setw(3) << i << "|";
		for (int j = 0; j < stulpeliai; j++)
		{
			rez << setw(4) << Mas[i][j];
		}
		rez << endl;
	}
}

void spausdinti(double Mas[], int eilutes, ofstream &rez)
{
	for (int j = 0; j < eilutes; j++)
	{
		rez << setw(5) <<fixed << setprecision(2) << Mas[j];
	}
	rez << endl;
}


template <class T> // ðablono formatas - T
double vidurkis(T Mas[])
{
	T suma = 0;

	std::cout << Mas[0] << " ";

	for (int i = 1; i < Mas[0] + 1; i++)
	{
		suma = suma + Mas[i];
	}
		
	return (double)suma / Mas[0];
}

void skaiciavimas(double Vidurkiai[], int Mas[][maxKiekis], int eilutes)
{
	for (int i = 0; i < eilutes; i++)
	{
		Vidurkiai[i] = vidurkis(Mas[i]);
	}
}