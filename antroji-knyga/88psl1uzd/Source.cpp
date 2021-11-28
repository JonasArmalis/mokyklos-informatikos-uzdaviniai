#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void Skaiciavimas(int SK[], ifstream& input);
void isvedimas(ofstream& output, int SK[]);

int main()
{
	ifstream input("Duomenys.txt");
	ofstream output("Rezultatai.txt");

	int SK[10];

	Skaiciavimas(SK, input);
	isvedimas(output, SK);


	input.close();
	output.close();
}

void Skaiciavimas(int SK[], ifstream& input)
{
	for (int i = 0; i < 10; i++)
	{
		SK[i] = 0;
	}

	char symbol;
	while (!input.eof())
	{
		input >> symbol;
		for (int i = 0; i < 10; i++)
		{
			if ((int)symbol == int('0')+ i)
			{
				SK[i]++;
			}
		}
	}
}

void isvedimas(ofstream& output, int SK[])
{
	for (int i = 0; i < 9; i++)
	{
		output << setw(3) << i << setw(3) << SK[i] << endl;
	}
}