#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

namespace komanda
{
	struct zaidejas
	{
		//variables
		string name;
		double height;
		int points;

		//constructor
		zaidejas();

		//destructor
		~zaidejas();
	};
}

int main()
{
	ifstream input("Data.txt");
	int n;
	int p, k;

	double maxHeight;
	int maxPoints;

	komanda::zaidejas ZAIDEJAI[20];
	komanda::zaidejas KOMANDA[10];



	return 0;
}

void ReadFile(ifstream& input, komanda::zaidejas ZAIDEJAI[], int & n, int & p, int & k)
{
	input >> n;
	for (int i = 0; i < n; i++)
	{
		input >> ZAIDEJAI[i].name;
		input >> ZAIDEJAI[i].height;
		input >> ZAIDEJAI[i].points;
	}
	input >> p >> k;
}

int Selection(komanda::zaidejas ZAIDEJAI[], komanda::zaidejas KOMANDA[], int n, double heightRequired, double pointsRequired)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (ZAIDEJAI[i].height >= heightRequired && ZAIDEJAI[i].points >= pointsRequired)
		{
			KOMANDA[k] = ZAIDEJAI[i];
			k++;
		}
	}
	return k;
}

void FindMaxValues(komanda::zaidejas ZAIDEJAI[], int n, int& maxPoints, double& maxHeight)
{
	maxHeight = ZAIDEJAI[0].height;
	maxPoints = ZAIDEJAI[0].points;

	for (int i = 1; i < n; i++)
	{
		if (ZAIDEJAI[i].height > maxHeight)
			maxHeight = ZAIDEJAI[i].height;
		if (ZAIDEJAI[i].points > maxPoints)
			maxHeight = ZAIDEJAI[i].points;
	}
}

void PrintResults(ofstream& output, komanda::zaidejas KOMANDA[], int k)
{
	output << "--------------------------------------------------- \n";
	output << setw(5) << "Vardas" << setw(10) << "Ugis" << setw(10) << "Taskai \n";
	output << "--------------------------------------------------- \n";
	for (int )
	output << "--------------------------------------------------- \n";
}