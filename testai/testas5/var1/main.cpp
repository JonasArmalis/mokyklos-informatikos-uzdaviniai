#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void PrintArr2D(ofstream& output, int n, int m, int arr[][100]);
void ReadArr2D(ifstream& input, int& n,  int arr[][100]);
int MinElement(int A[][100], int n, int &indexJ);
void DeleteColumn(int A[][100], int &n, int indexJ);


int main()
{
	int n;
	int A[100][100];

	int minElement;
	int minIndexJ;

	ifstream input("Duomenys.txt");
	ofstream output("Rezultatai.txt");

	ReadArr2D(input, n, A);
	PrintArr2D(output, n, n, A);

	minElement = MinElement(A, n, minIndexJ);
	DeleteColumn(A, n, minIndexJ);

	cout << "Maziausia reiksme virs salutines istrizaines yra: " << minElement <<endl;

	output << "Pakeistas masyvas" << endl;
	PrintArr2D(output, n, n - 1, A);

	input.close();
	output.close();
	return 0;
}

void PrintArr2D(ofstream& output, int n, int m, int arr[][100])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			output << setw(4) << arr[i][j];
		}
		output << endl;
	}
	output << endl;
}

void ReadArr2D(ifstream& input, int& n, int arr[][100])
{
	input >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			input >> arr[i][j];
		}
	}
}

int MinElement(int A[][100], int n, int &indexJ)
{
	int min = A[0][0];
	indexJ = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (A[i][j] < min)
			{
				min = A[i][j];
				indexJ = j;
			}
		}
	}
	return min;
}

void DeleteColumn(int A[][100], int &n, int indexJ)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = indexJ; j <= n; j++)
		{
			A[i][j] = A[i][j+1];
		}
	}
}
	