#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void ReadArr2D(ifstream& input, int& n, char S[][85], int sizes[]);
void Manipulation(char S[][85], char REZ[], int sizes[], int n);

int main()
{
	ifstream input("Duomenys.txt");
	ofstream output("Rezultatai.txt");

	int n;
	char S[100][85];
	char REZ[100];
	int sizes[10];


	ReadArr2D(input, n, S, sizes);
	Manipulation(S, REZ, sizes, n);


	input.close();
	output.close();
}

void ReadArr2D(ifstream& input, int& n, char S[][85], int sizes[])
{
	input >> n;

	for (int i = 0; i < n; i++)
	{
		input >> sizes[i];
		sizes[i] += 1;
		input.ignore(1);
		input.get(S[i], sizes[i]);
		input.ignore(256, '\n');
	}
}

void Manipulation(char S[][85], char REZ[], int sizes[], int n)
{
	int sum = 0;
	for (int i = 0; i < 85; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << S[j][sizes[j] - i];
			sum += S[j][sizes[j] - i] - '0' + 101;
		}
		REZ[i] = sum % 10;
		sum = sum / 10;
	}
}