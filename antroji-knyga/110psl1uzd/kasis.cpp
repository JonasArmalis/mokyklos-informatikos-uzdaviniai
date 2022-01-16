#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct zaidejas
{
	string name;
	double height;
	int points;
};

void PrintResults(ofstream& output, zaidejas KOMANDA[], int m);
void ReadFile(ifstream& input, zaidejas ZAIDEJAI[], int & n, int & p, int & k);
int Selection(zaidejas ZAIDEJAI[], zaidejas KOMANDA[], int n, double maxheight, double maxpoint, int p, int k);
void FindMaxValues(zaidejas ZAIDEJAI[], int n, int& maxPoints, double& maxHeight);


int main()
{
	ifstream input("Data.txt");
	ofstream output("Out.txt");
	int n, m;
	int p, k;

	double maxHeight;
	int maxPoints;

	zaidejas ZAIDEJAI[100];
	zaidejas KOMANDA[100];

	ReadFile(input, ZAIDEJAI, n, p, k);
	FindMaxValues(ZAIDEJAI, n, maxPoints, maxHeight);
	m = Selection(ZAIDEJAI, KOMANDA, n, maxHeight , maxPoints, p, k);
	PrintResults(output, KOMANDA, m);

	return 0;
}

void ReadFile(ifstream& input,zaidejas ZAIDEJAI[], int & n, int & p, int & k)
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

int Selection(zaidejas ZAIDEJAI[],zaidejas KOMANDA[], int n, double maxheight, double maxpoint, int p,int k)
{
	int m = 0;
	double heightRequired, pointsRequired;

	heightRequired = maxheight * (1 - (double)p / 100);
	pointsRequired = maxpoint * (1 - (double)k / 100);

	for (int i = 0; i < n; i++)
	{
		if (ZAIDEJAI[i].height >= heightRequired || ZAIDEJAI[i].points >= pointsRequired)
		{
			KOMANDA[m] = ZAIDEJAI[i];
			m++;
		}
	}
	return m;
}

void FindMaxValues(zaidejas ZAIDEJAI[], int n, int& maxPoints, double& maxHeight)
{
	maxHeight = ZAIDEJAI[0].height;
	maxPoints = ZAIDEJAI[0].points;

	for (int i = 1; i < n; i++)
	{
		if (ZAIDEJAI[i].height > maxHeight)
			maxHeight = ZAIDEJAI[i].height;
		if (ZAIDEJAI[i].points > maxPoints)
			maxPoints = ZAIDEJAI[i].points;
	}
} 

void PrintResults(ofstream& output,zaidejas KOMANDA[], int m)
{
	output << "---------------------------------------------------\n";
	output << setw(15) << "Vardas" << setw(10) << "Ugis" << setw(10) << "Taskai" << endl;
	output << "--------------------------------------------------- \n";
	for (int i = 0; i < m; i++)
		output << setw(15) << KOMANDA[i].name << setw(10) << KOMANDA[i].height << setw(10) << KOMANDA[i].points << endl;
	output << "--------------------------------------------------- \n";
}