#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void ReadLine(char EILE[], int &n, ifstream& input);
void Skaiciavimai(int KIEKIAI[], char SKYRIAI[], char EILE[], ifstream& input, int& eilSk);
int KiekisMasyve(char EILE[], char SKYRIAI[], int n);
int MaxIndx(int KIEKIAI[], int eilSk);
void Isvedimas(ofstream& output, int KIEKIAI[], int eilSk, int maxIndx);

int main()
{
	int eilSk = 0;
	char EILE[1000];
	int KIEKIAI[100];
	char SKYRIAI[3] = { ' ', '.', ',' };

	ifstream input("Tekstas.txt");
	ofstream output("Rezultatai.txt");

	Skaiciavimai(KIEKIAI, SKYRIAI, EILE, input, eilSk);
	int index = MaxIndx(KIEKIAI, eilSk);
	Isvedimas(output, KIEKIAI, eilSk, index);

	input.close();
	output.close();
	return 0;
}

void ReadLine(char EILE[], int &n, ifstream& input)
{
	input.getline(EILE, 1000);
	n = strlen(EILE);
	
}

int KiekisMasyve(char EILE[], char SKYRIAI[], int n)
{
	int sum = 0;

	for (int i = 0; EILE[i] != '\0'; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (EILE[i] == SKYRIAI[j])
			{
				sum++;
			}
		}	
	}
	return sum;
}

void Skaiciavimai(int KIEKIAI[], char SKYRIAI[], char EILE[], ifstream& input, int& eilSk)
{
	for (int i = 0; !input.eof(); i++)
	{
		int n;
		ReadLine(EILE, n, input);
		KIEKIAI[i] = KiekisMasyve(EILE, SKYRIAI, n);
		eilSk++;
	}
}

int MaxIndx(int KIEKIAI[], int eilSk)
{
	int index = 0;
	int max = KIEKIAI[0];
	for (int i = 0; i < eilSk; i++)
	{
		if (max < KIEKIAI[i])
		{
			max = KIEKIAI[i];
			index = i;
		}
	}
	return index;
}

void Isvedimas(ofstream& output, int KIEKIAI[], int eilSk, int maxIndx)
{
	output << "Eil Nr." << setw(8) << "skyriai" << endl;

	for (int i = 0; i < eilSk; i++)
	{
		output << i + 1 << setw(8) << KIEKIAI[i] << endl;
	}
	output << endl;

	output << "Daugiausia skyriu yra " << maxIndx +1 << " eiluteje \n";
}
