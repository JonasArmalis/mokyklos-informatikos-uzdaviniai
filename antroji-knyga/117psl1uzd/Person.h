#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

class person
{
	string name;
	string surname;
	int n;

public:
	person();
	void SetName(string n);
	string GetName();
	void SetSurname(string n);
	int GetN();
	void SetN(int m);
};

void Reader(ifstream & input, vector <person>& people);
void CountNames(vector <person>& people);
void SortNames(vector <person>& people);
bool ByName(person a, person b);
bool ByN(person a, person b);
void Print(vector <person>& people, ofstream& out);
