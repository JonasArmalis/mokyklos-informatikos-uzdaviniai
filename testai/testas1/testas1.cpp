#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

void ReadArray(ifstream& input, vector<double>& A);
double CalculateAvg(vector<double>& A);
void PrintArray(ofstream& output, vector<double>& A, double avg);

int main() {
	ifstream input("Autobusai.txt");
	ofstream output("Rezultatai.txt");

	vector<double> A;

	ReadArray(input, A);
	double average = CalculateAvg(A);
	PrintArray(output, A, average);

	input.close();
	output.close();
	return 0;
}

void ReadArray(ifstream& input, vector<double>& A)
{
	while (!input.eof())
	{
		int a;
		input >> a;
		A.push_back(a);
	}
}

double CalculateAvg(vector<double>& A)
{
	double sum = 0;

	for (size_t i = 0; i < A.size(); i++)
	{
		sum += A[i];
	}
	return sum / A.size();
}

void PrintArray(ofstream& output, vector<double>& A, double avg)
{
	for (int i = 0; i < A.size(); i++)
	{
		output << setw(2) << i + 1 << setw(5) << A[i] << endl;
	}
	output << "Vidurkis: "<< fixed << setprecision(2) <<avg << endl;
}