#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void nuskaitymas(int B[], int& m, ifstream& in);
void spausdinimas(int B[], ofstream& out, int m);
void iterpimas(int x, int j, int& m, int B[]);
void ieskojimas(int x, int k, int& m, int B[]);

int main()
{
	int B[100];
	int x, k;
	int m = 0;

	ifstream in("Duomenys.txt");
	ofstream out("Rezultatai.txt");
	
	nuskaitymas(B, m, in);
	out << "Pries: " << endl;
	spausdinimas(B, out, m);
	out << endl;

	cout << "Kiek ir kokiu reiksmiu reikia iterpti?" << endl;
	cin >> k >> x;

	ieskojimas(x, k, m, B);
	out << "Po: " << endl;
	spausdinimas(B, out, m);

	return 0;
}

void nuskaitymas(int B[],int& m, ifstream& in)
{	
	m = 0;
	for (size_t i = 0; !in.eof(); i++)
	{
		in >> B[i];
		m++;
	}
}

void iterpimas(int x, int j, int& m, int B[])
{
	for (int i = m; i > j; i--)
	{
		B[i] = B[i - 1];
	}
	B[j] = x;
}

void spausdinimas(int B[], ofstream& out, int m)
{
	for (size_t i = 0; i < m; i++)
	{
		out << B[i] << " ";
	}
}

void ieskojimas(int x, int k, int& m, int B[])
{
	for (int j = 0; j < m; j++)
	{
		if (x <= B[j])
		{
			for (size_t i = 0; i < k; i++)
			{
				iterpimas(x, j, m, B);
				m++;
			}
			return;
		}
	}
}