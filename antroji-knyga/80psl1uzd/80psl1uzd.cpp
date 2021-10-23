#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void Skaityti(ifstream& input, int& nA, int& nB, int A[], int B[]);
void Iterpimas(int v, int& nA, int arr[], int iterpinys);
void Iterpinejimas(int A[], int B[], int& nA, int& nB);
void Isvesti(ofstream& output, int A[], int n);

int main()
{
	ifstream input("seka.txt");
	ofstream output("rez.txt");

	int nA;
	int nB;
	int A[100];
	int B[100];

	Skaityti(input, nA, nB, A, B);
	Iterpinejimas(A, B, nA, nB);
	Isvesti(output, A, nA);

	input.close();
	output.close();
	return 0;
}
void Skaityti(ifstream& input, int& nA, int& nB, int A[], int B[])
{
	input >> nA;
	for (int i = 0; i < nA; i++)
	{
		input >> A[i];
	}

	input >> nB;
	for (int j = 0; j < nB; j++)
	{
		input >> B[j];
	}
}

void Iterpimas(int v, int& nA, int arr[], int iterpinys)
{
	for (int i = nA - 1; i > v; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[v] = iterpinys;
	nA++;
}

void Iterpinejimas(int A[], int B[], int& nA, int& nB)
{
	int startingN = nA;
	int index = 0;

	for (int i = 0; i < startingN; i++)
	{
		for (int j = 0; j < nB; j++)
		{
			if (B[j] % A[index] == 0)
			{
				Iterpimas(index + 1, nA, A, B[j]);
			}
		}
		index++;
	}
}

void Isvesti(ofstream& output, int A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
		output << A[i] << " ";
	}
}