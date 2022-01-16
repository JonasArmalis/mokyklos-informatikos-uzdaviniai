#include "zaidejas.h"

int main()
{
	ifstream input("Data.txt");
	ofstream output("Out.txt");
	int p, k;

	double maxHeight;
	int maxPoints;

	vector<zaidejas> ZAIDEJAI;
	vector<zaidejas> KOMANDA;

	ReadFile(input, ZAIDEJAI, p, k);
	FindMaxValues(ZAIDEJAI, maxPoints, maxHeight);
	Selection(ZAIDEJAI, KOMANDA, maxHeight , maxPoints, p, k);
	PrintResults(output, KOMANDA);

	return 0;
}