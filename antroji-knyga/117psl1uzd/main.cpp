#include "person.h"

int main()
{
	vector <person> people;
	ifstream input("Data.txt");
	ofstream out("Rezult.txt");

	Reader(input, people);
	CountNames(people);
	SortNames(people);
	Print(people, out);

	return 0;
}