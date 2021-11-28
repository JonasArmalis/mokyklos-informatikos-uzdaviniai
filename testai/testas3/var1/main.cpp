#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void ReadArr(ifstream& input, int& n, int arr[]);
void PrintArr(ofstream& output, int n, int arr[]);
void Deletion(int array[], int v, int& n);
void Calculation(int &n, int A[]);

int main()
{
	int n;
	int A[100];

	ifstream input("Duomenys.txt");
	ofstream output("Rezultatai.txt");

	ReadArr(input, n, A);

	output << "Masyvas pries salinima" << endl;
	PrintArr(output, n, A);

	Calculation(n, A);

	output << "Masyvas po salinimo" << endl;
	PrintArr(output, n, A);
	
	return 0;
}

void Calculation(int &n, int A[])
{
	for (int i = 0; i < n; i++)
	{
		while (A[i] == A[i + 1])
		{
			Deletion(A, i + 1, n);
		}
	}
}

void PrintArr(ofstream& output, int n, int arr[])
{
	output << setw(4) << "Indexas" << setw(10) << "Reiksme" << endl;
	for (int i = 0; i < n; i++)
	{
		output << setw(4) << i << setw(8) << arr[i] << endl;
	}
	output << endl;
}

void ReadArr(ifstream& input, int& n, int arr[])
{
	input >> n;
	for (int i = 0; i < n; i++)
	{
		input >> arr[i];
	}
}

void Deletion(int array[], int v, int& n)
{
	for (int i = v; i <= n; i++)
	{
		array[i] = array[i + 1];
	}
	n--;
}
