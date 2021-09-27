#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void perskaityti(ifstream& in, int& n);
void skaiciavimai();
int marsrutoIlgis(ifstream& in, int k);
void isvesti(ofstream& out, int suma);

int main()
{
	skaiciavimai();
	cout << "Programa baige darba \n";
	return 0;
}
void perskaityti(ifstream& in, int& n)
{
	in >> n;
}
void skaiciavimai()
{
	ifstream in("Troleibusai.txt");
	ofstream out("Marsrutai.txt");

	int n;
	perskaityti(in, n);
	int suma;
	int k;

	for (int i = 0; i < n; i++)
	{
		in >> k;
		suma = marsrutoIlgis(in, k);
		isvesti(out, suma);
	}

	
	in.close();
	out.close();
}
int marsrutoIlgis(ifstream& in, int k)
{
	int sk;
	int suma = 0;
	for (int j = 0; j < k - 1; j++)
	{
		in >> sk;
		suma += sk;
	}
	return suma;
}

void isvesti(ofstream& out, int suma)
{
	out << suma << endl;
}