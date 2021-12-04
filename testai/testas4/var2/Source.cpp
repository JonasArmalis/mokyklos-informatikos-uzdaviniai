#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

void ivedimas(ifstream& in, int& n, int& m, int A[][100]);
void skaiciavimas(int n, int m, int A[][100], int& neigiami, int& indeksas, int vid[]);
void isvedimas(ofstream& out, int A[][100], int n, int m);

int main()
{
	int A[100][100];
	int vid[100];
	int n = 0, m = 0, neigiami, indeksas;
	
	ifstream in("Dalykai.txt");
	ofstream out("Rezultatai.txt");

	ivedimas(in, n, m, A);
	skaiciavimas(n, m, A, neigiami, indeksas, vid);
	isvedimas(out, A, n, m);

	cout << "Geriausiai besimokines mokinys yra: " << indeksas + 1 << " su vidurkiu: " << vid[indeksas] << endl;
	cout << neigiami << " mokiniu turejo neigiamu ivertinimu" << endl;

	return 0;
}


void ivedimas(ifstream& in,int& n, int& m, int A[][100])
{
	in >> n >> m;

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			in >> A[i][j];
		}
	}
}

void skaiciavimas(int n, int m, int A[][100], int& neigiami, int& indeksas, int vid[])
{
	int x = 0;
	neigiami = 0;
	indeksas = 0;
	
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			x += A[i][j];
		}
		vid[i] = x / m;
		x = 0;
	}

	for (size_t i = 0; i < n; i++)
	{
		if (vid[i] > x)
		{
			x = vid[i];
			indeksas = i;
		}
	}

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			if (A[i][j] < 4)
			{
				neigiami++;

				break;
			}
		}
	}
}

void isvedimas(ofstream& out, int A[][100], int n, int m)
{
	out << setw(5) << "Mokinys " << setw(10) << "Pazimys" << endl;

	for (size_t i = 0; i < n; i ++)
	{
		out << setw(5) << i + 1 << ". " << setw(5);

		for (size_t j = 0; j < m; j++)
		{
			
			out << A[i][j] << " ";
		}
		out << endl;
	}
}