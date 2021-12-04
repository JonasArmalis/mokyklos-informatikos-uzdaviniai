#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void PrintArr2D(ofstream& output, int n, int m, int arr[][100]);
void ReadArr2D(ifstream& input, int& n, int& m, int arr[][100]);
int MaxTens(int B[][100], int n, int m);
int PositiveOnlyAmount(int B[][100], int n, int m);

int main()
{
	int n;
	int m;
	int B[100][100];

	ifstream input("Dalykai.txt");
	ofstream output("Rezultatai.txt");

	ReadArr2D(input, n, m, B);
	PrintArr2D(output, n, m, B);

	int maxTenIndex = MaxTens(B, n, m);
	int positives = PositiveOnlyAmount(B, n, m);

	cout << "Daugiausia 10-tuku turi: " << maxTenIndex + 1 << " mokinys. \n";
	cout << "Mokiniu kiekis kurie turi tik teigiamus pazymius: " << positives;
	
	input.close();
	output.close();
	return 0;
}

void PrintArr2D(ofstream& output, int n, int m, int arr[][100])
{
	output << setw(2) << "Mok. nr." << setw(15) << "Ivertinimai" << endl;
	for (int i = 0; i < n; i++)
	{
		output << setw(2) << i + 1 << setw(15);
		for (int j = 0; j < m; j++)
		{
			output << arr[i][j] << setw(4);
		}
		output << endl;
	}
	output << endl;
}

void ReadArr2D(ifstream& input, int& n, int& m, int arr[][100])
{
	input >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			input >> arr[i][j];
		}
	}
}

//Finds the index of the student, with the most 10s
int MaxTens(int B[][100], int n, int m)
{
	int index = 0;
	int maxK = 0;

	for (int i = 0; i < n; i++)
	{
		int k = 0;
		for (int j = 0; j < m; j++)
		{
			if (B[i][j] == 10)
				k++;
		}

		if (maxK < k)
		{
			maxK = k;
			index = i;
		}
	}
	return index;
}

//Returns the amount of students, who only have positive grades
int PositiveOnlyAmount(int B[][100], int n, int m)
{
	int numOfPos = 0;
	for (int i = 0; i < n; i++)
	{
		bool positive = true;
		for (int j = 0; j < m; j++)
		{
			if (B[i][j] < 4)
				positive = false;
		}
		if (positive) numOfPos++;
	}
	return numOfPos;
}