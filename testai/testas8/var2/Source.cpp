#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct Parametrai
{
	string Pavarde;
	string Vardas;
	int dalykai[8];
	double Vidurkiai;

	void parametrai()
	{
		double a = 0;
		for (int i = 0; i < 8; i++)
			a += dalykai[i];
		Vidurkiai = a / 8;
	}
};

void Read(ifstream& in, Parametrai Mokiniai[], int& n);
void spausdinimas(ofstream& out, Parametrai Mokiniai[], int n, double klasesVid);
double KlasesVid(Parametrai Mokiniai[], int n, double klasesVid);

int main()
{
	ifstream in ("Klase.txt");
	ofstream out("KlaseRez.txt");

	Parametrai Mokiniai[100];
	int n = 0;
	double klasesVid = 0;

	Read(in, Mokiniai, n);
	klasesVid = KlasesVid(Mokiniai, n, klasesVid);
	spausdinimas(out, Mokiniai, n, klasesVid);
	return 0;
}

void Read(ifstream& in,Parametrai Mokiniai[], int& n)
{
	for (int i = 0;!in.eof(); i++)
	{
		in >> Mokiniai[i].Pavarde;
		in >> Mokiniai[i].Vardas;
		for (int j = 0; j < 8; j++)
		{
			in >> Mokiniai[i].dalykai[j];
		}
		Mokiniai[i].parametrai();
		n++;
	}
}

double KlasesVid(Parametrai Mokiniai[], int n,double klasesVid)
{
	double bendras = 0;
	for (int i = 0; i < n; i++)
	{
		bendras += Mokiniai[i].Vidurkiai;
	}
	klasesVid = bendras / n;
	
	return klasesVid;
}

void spausdinimas(ofstream& out, Parametrai Mokiniai[],int n, double klasesVid)
{
	out << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Vidurkis" << endl;

	for (int i = 0; i < 50; i++)
		out << "-";

	out << endl;

	for (int i = 0; i < n; i++)
		out << setw(15) << Mokiniai[i].Pavarde << setw(15) << Mokiniai[i].Vardas << setw(15) << Mokiniai[i].Vidurkiai << endl;
	for (int i = 0; i < 50; i++)
		out << "-";

	out << endl;
	out << setw(15)  << "Klases"<< setw(15) << "Vidurkis" << setw(15) << klasesVid << endl;
}