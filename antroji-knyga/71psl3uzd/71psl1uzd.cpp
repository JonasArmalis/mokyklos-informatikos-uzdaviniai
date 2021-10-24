#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

void skaitymas(ifstream& in, int mas[], int& n);
void skaiciavimas(int& n, int& m, int VAR[], int VER[]);
void salinimas(int mas[], int v, int& n);
void isvedimas(ofstream& out, int VAR[], int VER[], int n, int m);

int main()
{
	ifstream in("Pradiniai.txt");
	ofstream out("Rezultatai.txt");
	
	int n, m;
	int VAR[100];
	int VER[100];

	skaitymas(in, VAR, n);
	skaitymas(in, VER, m);
	skaiciavimas(n, m, VAR, VER);
	isvedimas(out, VAR, VER, n, m);

	in.close();
	out.close();
	return 0;
}

void skaitymas(ifstream& in, int mas[], int& n)
{
	in >> n;
	for (size_t i = 0; i < n; i++)
	{
		in >> mas[i];
	}
}

void skaiciavimas(int& n, int& m, int VAR[], int VER[]) 
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			if (VAR[i] == VER[j])
			{
				salinimas(VAR, i, n);
				salinimas(VER, j, m);
				i--;
				j--;
			}
		}
	}
	
}

void salinimas (int mas[], int v, int& n)
{
	for (size_t i = v; i <= n; i++)
	{
		mas[i] = mas[i + 1];
	}
	n--;
}

void isvedimas(ofstream& out, int VAR[], int VER[], int n, int m) 
{
	if (n != 0) 
	{
		out << "Reikes varztu: " << endl;

		for (size_t i = 0; i < n; i++)
		{
			out << VAR[i] << " ";
		}
		out << endl;
	}

	if (m != 0)
	{
		out << "Reikes verzliu: " << endl;

		for (size_t i = 0; i < m; i++)
		{
			out << VER[i] << " ";
		}
		out << endl;
	}
}