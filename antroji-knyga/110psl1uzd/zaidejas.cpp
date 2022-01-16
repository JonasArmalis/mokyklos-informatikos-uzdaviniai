#include "zaidejas.h"

void ReadFile(ifstream& input, vector<zaidejas>& ZAIDEJAI, int & p, int & k)
{
	string name;
	double height;
	int points;
	int n;
	input >> n;
	for (int i = 0; i < n; i++)
	{
		input >> name;
		input >> height;
		input >> points;
		zaidejas a(name, height, points);
		ZAIDEJAI.push_back(a);
	}
	input >> p >> k;
}

void Selection(vector<zaidejas>& ZAIDEJAI, vector<zaidejas>& KOMANDA, double maxheight, double maxpoint, int p, int k)
{
	double heightRequired, pointsRequired;

	heightRequired = maxheight * (1 - (double)p / 100);
	pointsRequired = maxpoint * (1 - (double)k / 100);

	for (size_t i = 0; i < ZAIDEJAI.size(); i++)
	{
		if (ZAIDEJAI[i].height >= heightRequired || ZAIDEJAI[i].points >= pointsRequired)
		{
			KOMANDA.push_back(ZAIDEJAI[i]);
		}
	}
}

void FindMaxValues(vector<zaidejas>& ZAIDEJAI, int& maxPoints, double& maxHeight)
{
	maxHeight = ZAIDEJAI[0].height;
	maxPoints = ZAIDEJAI[0].points;

	for (size_t i = 1; i < ZAIDEJAI.size(); i++)
	{
		if (ZAIDEJAI[i].height > maxHeight)
			maxHeight = ZAIDEJAI[i].height;
		if (ZAIDEJAI[i].points > maxPoints)
			maxPoints = ZAIDEJAI[i].points;
	}
}

void PrintResults(ofstream& output, vector<zaidejas>& KOMANDA)
{
	output << "---------------------------------------------------\n";
	output << setw(15) << "Vardas" << setw(10) << "Ugis" << setw(10) << "Taskai" << endl;
	output << "--------------------------------------------------- \n";
	for (size_t i = 0; i < KOMANDA.size(); i++)
		output << setw(15) << KOMANDA[i].name << setw(10) << KOMANDA[i].height << setw(10) << KOMANDA[i].points << endl;
	output << "--------------------------------------------------- \n";
}