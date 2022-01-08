#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void ReadFile(char TEKSTAS[], int &n, ifstream& input);
void ClearArray(int Arr[], int n);
void CalculateAmounts(char TEXT[], int n, int AMOUNTS[], char DIGITS[]);
int FindMaxDigit(int AMOUNTS[], int n);
void Isvedimas(ofstream& out, int max, int AMOUNTS[], int n);

int main()
{
	char DIGITS[10] = { '0', '1', '2', '3', '4', '5', '6','7', '8', '9' };
	int AMOUNTS[10];
	char TEXT[1000];
	int n;

	int max;

	ifstream input("Tekstas.txt");
	ofstream output("Rezultatai.txt");

	ReadFile(TEXT, n, input);
	ClearArray(AMOUNTS, 10);
	CalculateAmounts(TEXT, n, AMOUNTS, DIGITS);
	max = FindMaxDigit(AMOUNTS, 10);

	Isvedimas(output, max, AMOUNTS, 10);


	input.close();
	output.close();
	return 0;
}

void ReadFile(char TEXT[], int &n, ifstream& input)
{
	for (n = 0; !input.eof(); n++)
		input >> TEXT[n];
}

void ClearArray(int Arr[], int n)
{
	for (int i = 0; i < n; i++)
		Arr[i] = 0;
}


void CalculateAmounts(char TEXT[], int n, int AMOUNTS[], char DIGITS[])
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 10; j++)
			if (TEXT[i] == DIGITS[j])
				AMOUNTS[j]++;
}

int FindMaxDigit(int AMOUNTS[], int n)
{
	int max = AMOUNTS[0];
	int maxIndx = 0;

	for (int i = 1; i < n; i++)
	{
		if (AMOUNTS[i] > max)
		{
			max = AMOUNTS[i];
			maxIndx = i;
		}
	}
		
	return maxIndx;
}

void Isvedimas(ofstream& out, int max, int AMOUNTS[], int n)
{
	cout << "Daugiausiai pasikartojes skaitmuo: " << max << endl;

	out << setw(8) << "Skaitmuo|" << setw(8) << "Kiekis" << endl;

	for (int i = 0; i < n; i++)
		out << setw(8) << i << "|" << setw(8) << AMOUNTS[i] << endl;
}

