#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct Gatve{
	string city;
	string title;
	int length;
	int houses;

	Gatve() {};
	Gatve(string c, string t, int l, int num)
	{
		city = c;
		title = t;
		length = l;
		houses = num;
	}

	Gatve operator= (Gatve val)
	{
		city = val.city;
		houses = val.houses;
		length = val.length;
		title = val.title;
		return *this;
	}

};
void Read(ifstream& input, Gatve G[], int& n);
void Filter(Gatve G[], Gatve Ga[], int n, int &k, int x, int z);
void BubbleSort(Gatve array[], int n);
void PrintData(ofstream& out, Gatve G[], int n);
void PrintResults(ofstream& out, Gatve Ga[], int n);


int main()
{
	ifstream input1("Miestas1.txt");
	ifstream input2("Miestas2.txt");
	ofstream output("Rezultatai.txt");

	int x, z;
	int n, m, k = 0;
	Gatve G1[50];
	Gatve G2[50];
	Gatve Ga[100];

	Read(input1, G1, n);
	Read(input2, G2, m);

	cout << "Iveskite x: " << endl;
	cin >> x;
	cout << "Iveskite z: " << endl;
	cin >> z;


	Filter(G1, Ga, n, k, x, z);
	Filter(G2, Ga, m, k, x, z);
	BubbleSort(Ga, k);
	PrintData(output, G1, n);
	PrintData(output, G2, m);
	PrintResults(output, Ga, k);
}
void Read(ifstream& input, Gatve G[], int& n)
{
	string city;
	input >> city;

	n = 0;

	for (int i = 0; !input.eof(); i++, n++)
	{
		G[i].city = city;
		input >> G[i].title >> G[i].length >> G[i].houses;
	}	
}

void Filter(Gatve G[], Gatve Ga[], int n, int &k, int x, int z)
{
	for (int i = 0; i < n; i++)
	{
		if (G[i].length < x && G[i].houses > z)
		{
			Ga[k] = G[i];
			k++;
		}
	}
}

void BubbleSort(Gatve array[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (array[j].length > array[j + 1].length)
			{
				Gatve temp;
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

void PrintData(ofstream& out, Gatve G[], int n)
{
	out << setw(15) << "Gatves pavadinimas" << setw(15) << "ilgis" << setw(15) << "namu skaicius"  << endl;

	for (int i = 0; i < n; i++)
	{
		out << setw(15) << G[i].title << setw(15) << G[i].length << setw(10) << G[i].houses << endl;
	}
	out << endl;
}


void PrintResults(ofstream& out, Gatve Ga[], int n)
{
	out << setw(15) << "Gatves pavadinimas" << setw(15) << "ilgis" << setw(15) << "namu skaicius" << setw(10) << "miestas" << endl;

	for (int i = 0; i < n; i++)
	{
		out << setw(15) << Ga[i].title << setw(15) << Ga[i].length << setw(10) << Ga[i].houses << setw(20) << Ga[i].city << endl;
	}
	out << endl;
}