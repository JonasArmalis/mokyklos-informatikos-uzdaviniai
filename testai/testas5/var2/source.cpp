#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void ivedimas(int A[][100], int& n, ifstream& in);
void spausdinimas(int A[][100], int n, int m, ofstream& out);
int skaiciavimas(int A[][100], int n);
void salinimas(int A[][100], int n, int& m, int indeksas);

int main()
{
	int n, m;
	int A[100][100];
	int indeksas;

	ifstream in("Duomenys.txt");
	ofstream out("Rezultatai.txt");

	ivedimas(A, n, in);
	m = n;

	out << "Pries: " << endl;
	spausdinimas(A, n, m, out);

	indeksas = skaiciavimas(A, n);
	salinimas(A,n,m,indeksas);

	out << endl << "Po: " << endl;
	spausdinimas(A, n, m, out);

	return 0;
}

void ivedimas(int A[][100],int& n, ifstream& in)
{
	in >> n;

	for (size_t i =0; i < n; i ++)
	{
		for (size_t j = 0; j < n; j++)
		{
			in >> A[i][j];
		}
	}
}

void spausdinimas(int A[][100],int n,int m, ofstream& out)
{
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			out << setw(3) << A[i][j] << " ";
		}
		out << endl;
	}
}

int skaiciavimas(int A[][100],int n)
{
	int indeksas = 0;
	int didziausias = 0;

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 1; j < 1 + i; j++)
		{
			if (A[i][ n- j] > didziausias)
			{
				didziausias = A[i][n - j];
				indeksas = i;
			}
		}
	}
	cout << "Didziausias : " << didziausias << endl;
	return indeksas;
}

void salinimas(int A[][100],int n, int& m, int indeksas)
{
	for (size_t i = indeksas; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			A[i][j] = A[i + 1][j + 1];
		}
	}

	m = n - 1;
}