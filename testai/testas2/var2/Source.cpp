#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int Min(int masyvas[], int n);
void ivedimas(ifstream& X, int& n, int masyvas[]);
void keitimas(int masyvas[], int indeksas, int a, int b);
void spausdinimas(ofstream& X, int masyvas[], int n);

int main () 
{
	int n, m;
	int Xduom[1000];
	int Yduom[1000];
	int Xmin, Ymin;

	ifstream X("DuomenysX.txt");
	ifstream Y("DuomenysY.txt");
	ofstream Rez("Rezultatai.txt");

	ivedimas(X, n, Xduom);
	Rez << "X pradiniai : " << endl;
	spausdinimas(Rez, Xduom, n);
	Xmin = Min(Xduom, n);
	keitimas(Xduom, Xmin, 0, n - 1);
	Rez << "X galutiniai : " << endl;
	spausdinimas(Rez, Xduom, n);

	ivedimas(Y, m, Yduom);
	Rez << "Y pradiniai : " << endl;
	spausdinimas(Rez, Yduom, m);
	Ymin = Min(Yduom, m);
	keitimas(Yduom, Ymin, 0, 1);
	Rez << "Y galutiniai : " << endl;
	spausdinimas(Rez, Yduom, m);

	return 0;
}

void ivedimas(ifstream& X, int& n, int masyvas[])
{
	X >> n;

	for (size_t i = 0; i < n; i++)
	{
		X >> masyvas[i];
	}
}

int Min(int masyvas[],int n)
{
	int laikinas;
	int indeksas;

	laikinas = masyvas[0];
	indeksas = 0;

	for (size_t i = 0; i < n; i++)
	{
		if (masyvas[i] < laikinas)
		{
			laikinas = masyvas[i];
			indeksas = i;
		}
	}

	return indeksas;
}

void keitimas(int masyvas[],int indeksas, int a, int b)
{
	masyvas[indeksas] = masyvas[a] + masyvas[b];
}

void spausdinimas(ofstream& X, int masyvas[],int n)
{
	for (size_t i = 0; i < n; i++)
	{
		X << setw (3) << i + 1 << "  " << setw(3) << masyvas[i] << endl;
	}

	X << endl;
}