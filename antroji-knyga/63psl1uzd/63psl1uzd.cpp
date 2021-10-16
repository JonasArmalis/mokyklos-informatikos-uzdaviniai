#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void Skaityti(ifstream& input, int& n, int MONTH[], int DAY[], double MASS[], int BOLETUS[], int REDHEADS[]);
template <typename T> int FindMaxBy(int n, T keyVal[]);
void Isvedimas(ofstream& output, int MONTH[], int DAY[], int maxAll, int maxBoletus, int maxRedheads);


int main()
{
	ifstream input("grybai.txt");
	ofstream output("rez.txt");

	int n;
	int MONTH[100];
	int DAY[100];
	double MASS[100];
	int BOLETUS[100];
	int REDHEADS[100];

	Skaityti(input, n, MONTH, DAY, MASS, BOLETUS, REDHEADS);

	//Derlingiausios dienos per sezona indexas
	int allIndex = FindMaxBy(n, MASS);  
	//Derlingiausios dienos pagal baravykus indexas
	int boletusIndex = FindMaxBy(n, BOLETUS); 
	//Derlingiausios dienos pagal raudonvirsius indexas
	int redheadIndex = FindMaxBy(n, REDHEADS); 

	Isvedimas(output, MONTH, DAY, allIndex, boletusIndex, redheadIndex);

	input.close();
	output.close();
}
void Skaityti(ifstream& input, int& n, int MONTH[], int DAY[], double MASS[], int BOLETUS[], int REDHEADS[])
{
	input >> n;

	for (int i = 0; i < n; i++)
	{
		input >> MONTH[i] >> DAY[i] >> MASS[i] >> BOLETUS[i] >> REDHEADS[i];
	}
}
template <typename T>
int FindMaxBy(int n, T keyVal[])
{
	T max = keyVal[0];
	int index = 0;

	for (int i = 1; i < n; i++)
	{
		if (keyVal[i] > max)
		{
			max = keyVal[i];
			index = i;
		}
	}
	return index;
}

void Isvedimas(ofstream& output, int MONTH[], int DAY[], int maxAll, int maxBoletus, int maxRedheads)
{
	output << "Derlingiausia diena: " << MONTH[maxAll] <<" "<< DAY[maxAll] << endl;
	output << "Derlingiausia baravyku diena: " << MONTH[maxBoletus] <<" "<< DAY[maxRedheads] << endl;
	output << "Derlingiausia raudonvirsiu diena: " << MONTH[maxRedheads] <<" " << DAY[maxRedheads] << endl;
}