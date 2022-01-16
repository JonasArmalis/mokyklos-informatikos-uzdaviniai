#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

struct zaidejas
{
	string name;
	double height;
	int points;

private:
	zaidejas()
	{
		height = 0;
		points = 0;
	};
public:
	zaidejas(string Name, double Height, int Points) :
		name(Name)
		, height(Height)
		, points(Points)
	{}

};

void PrintResults(ofstream& output, vector<zaidejas>& KOMANDA);
void ReadFile(ifstream& input, vector<zaidejas>& ZAIDEJAI, int & p, int & k);
void Selection(vector<zaidejas>& ZAIDEJAI, vector<zaidejas>& KOMANDA, double maxheight, double maxpoint, int p, int k);
void FindMaxValues(vector<zaidejas>& ZAIDEJAI, int& maxPoints, double& maxHeight);
