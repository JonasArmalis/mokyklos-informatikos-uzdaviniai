#include "Person.h"

person::person()
{ 
	n = 1;
}
void person::SetName(string n)
{
	name = n;
}
string person::GetName()
{
	return name;
}
void person::SetSurname(string n)
{
	surname = n;
}
int person::GetN()
{
	return n;
}
void person::SetN(int m)
{
	n = m;
}

void Reader(ifstream & input, vector <person>& people)
{
	int n;
	input >> n;
	input.ignore(256, '\n');

	for (int i = 0; i < n; i++)
	{
		person a;
		char str[20];
		input.get(str, 20);
		a.SetSurname(str);
		input.get(str, 20);
		a.SetName(str);
		people.push_back(a);
		input.ignore(256, '\n');
	}
}
void CountNames(vector <person>& people)
{
	for (size_t i = 0; i < people.size(); i++)
	{
		for (size_t j = i + 1; j < people.size(); j++)
		{
			if (people[i].GetName() == people[j].GetName())
			{
				people[i].SetN(people[i].GetN() + 1);
				people.erase(people.begin() + j);
				j--;
			}
		}
	}
}
void SortNames(vector <person>& people)
{
	sort(people.begin(), people.end(), ByName);
	sort(people.begin(), people.end(), ByN);
}
bool ByName(person a, person b)
{
	return a.GetName() < b.GetName();
}
bool ByN(person a, person b)
{
	return a.GetN() < b.GetN();
}
void Print(vector <person>& people, ofstream& out)
{
	for (size_t i = 0; i < people.size(); i++)
		out << setw(8) << people[i].GetName() << setw(5) << people[i].GetN() << endl;
}