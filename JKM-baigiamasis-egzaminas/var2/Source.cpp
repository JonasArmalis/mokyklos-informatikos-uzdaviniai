#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Leidiniai
{
	string pavadinimas = "";
	int kiekis = 0;
	double kaina = 0;
};

struct Kainorastis
{
	string pavadinimas = "";
	double Men3 = 0;
	double Men6 = 0;
	double Men12 = 0;
};

int Pigiausias(vector<Kainorastis>& C);
void Rikiavimas(vector<Kainorastis>& C);
void Sudarymas(vector<Leidiniai>& A, vector<Kainorastis>& C);
void Koregavimas(vector<Leidiniai>& A, vector<Leidiniai>& B);
void Skaitymas(vector<Leidiniai>& x, ifstream& in);
void KainSpa(ofstream& out, vector <Kainorastis>& x, int index);
void LeidSpa(ofstream& out, vector <Leidiniai>& x);
bool Lyginimas(Kainorastis a, Kainorastis b);

int main()
{
	ifstream inS("LeidiniaiS.txt");
	ifstream inN("LeidiniaiN.txt");
	ofstream out("Rezultatai.txt");

	vector <Leidiniai> A;
	vector <Leidiniai> B;
	vector <Kainorastis> C;
	int index;

	Skaitymas(A, inS);
	Skaitymas(B, inN);
	out << "Pradiniai : " << endl;
	LeidSpa(out, A);
	LeidSpa(out, B);
	
	Koregavimas(A, B);
	out << "Papildytas: " << endl;
	LeidSpa(out, A);

	Sudarymas(A, C);
	Rikiavimas(C);
	index = Pigiausias(C);
	out << "Kainorastis:" << endl;
	KainSpa(out, C, index);

	inS.close();
	inN.close();
	out.close();

	return 0;
}

void Skaitymas(vector<Leidiniai>& x, ifstream& in)
{
	Leidiniai z;

	for (size_t i = 0; !in.eof(); i++)
	{
		in >> z.pavadinimas;
		in >> z.kiekis;
		in >> z.kaina;

		x.push_back(z);
	}
}

void Koregavimas(vector<Leidiniai>& A, vector<Leidiniai>& B)
{
	for (size_t i = 0; i < B.size(); i++)
	{
		bool x = false;

		for (size_t j = 0; j < A.size(); j++)
		{
			if (B[i].pavadinimas == A[i].pavadinimas)
			{
				A[i] = B[i];
				x = true;
				break;
			}
		}
		if (x == false)
		{
			A.push_back(B[i]);
		}
	}
}

void Sudarymas(vector<Leidiniai>& A, vector<Kainorastis>& C)
{
	Kainorastis x;
	double men;
	for (size_t i = 0; i < A.size(); i++)
	{
		x.pavadinimas =	A[i].pavadinimas;
		men = A[i].kaina * A[i].kiekis;
		x.Men3 = men * 3;
		x.Men6 = men * 6;
		x.Men12 = men * 12;
		C.push_back(x);
	}
}

void Rikiavimas(vector<Kainorastis>& C)
{
	sort(C.begin(), C.end(), Lyginimas);
}

bool Lyginimas(Kainorastis a, Kainorastis b)
{
	return a.pavadinimas < b.pavadinimas;
}

int Pigiausias(vector<Kainorastis>& C)
{
	int index = 0;
	double pigiausias = C[0].Men12;

	for (size_t i = 0; i < C.size(); i++)
	{
		if (C[i].Men12 < pigiausias)
		{
			pigiausias = C[i].Men12;
			index = i;
		}
	}

	return index;
}

void LeidSpa(ofstream& out, vector <Leidiniai>& x)
{
	out << "Pavadinimas   Kiekis   Kaina" << endl;
	for (size_t i = 0; i < x.size(); i++)
	{
		out << setw(10)<< x[i].pavadinimas << setw(8)<< x[i].kiekis << setw(8) << x[i].kaina << endl;
	}
	out << endl;
}

void KainSpa(ofstream& out, vector <Kainorastis>& x,int index)
{
	out << "Pavadinimas   3 men.   6 men.   12 men." << endl;
	for (size_t i = 0; i < x.size(); i++)
	{
		out << setw(10) << x[i].pavadinimas << setw(8) << x[i].Men3 << setw(8) << x[i].Men6 << setw(8) << x[i].Men12 << endl;
	}

	out << endl << "Pigiausias metinis: " << endl << setw(10) << x[index].pavadinimas << setw(5) << x[index].Men12 << " per metus" << endl << endl;
}