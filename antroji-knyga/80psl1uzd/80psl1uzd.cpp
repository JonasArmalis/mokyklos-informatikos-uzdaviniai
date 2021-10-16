#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void Skaityti(ifstream& input, int& nA, int& nB, int A[], int B[]);
void Iterpimas(int v, int& n, int arr[], int iterpinys);

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




	input.close();
	output.close();
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

void Iterpimas(int v, int& n, int arr[], int iterpinys)
{
	for (size_t i = n; n > v; i--)
	{
		arr[n] = arr[n - 1];
	}
	arr[v] = iterpinys;
	n++;
}

void Iterpinejimas(int A[], int B[], int nA, int nB)
{
	int index = 0;

	for (size_t i = 0; i < nA; i++)
	{
		for (size_t j = 0; j < nB; j++)
		{
			if (B[j] % A[i] == 0)
			{
				Iterpimas(index + 1, nA, A, B[j]);
				index++;
			}
		}
	}
}

void Isvesti(ofstream& )
{

}
