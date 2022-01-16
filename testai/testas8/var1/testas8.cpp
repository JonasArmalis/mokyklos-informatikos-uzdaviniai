#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct Butas {
	int nr;
	string surname;
	int men[6];
	double UsageEur;

	Butas(int Nr, string Surname)
	{
		nr = Nr;
		surname = Surname;
	}

	void CalcUsage(int x)
	{
		int sum = 0;

		for (int i = 0; i < 6; i++)
			sum += men[i];
		
		UsageEur = sum * (double)x / 100;
	}
};

double CalculateUsageAll(vector<Butas>& butai, int x);
void Read(ifstream& input, vector<Butas> & butai, int&x);
void Printer(ofstream& out, vector<Butas>& butai, double allUsage);

int main()
{
	ifstream input("Namas.txt");
	ofstream output("NamasRez.txt");

	vector<Butas> butai;
	double AllUsage;
	int x;

	Read(input, butai, x);
	AllUsage = CalculateUsageAll(butai,x);
	Printer(output, butai, AllUsage);

	input.close();
	output.close();
	return 0;
}

void Read(ifstream& input, vector<Butas> & butai, int&x)
{
	int n;
	input >> n;

	for (int i = 0; i < n; i++)
	{
		string name;
		int nr;

		input >> nr >> name;
		Butas but(nr, name);
		

		for (int j = 0; j < 6; j++)
		{
			input >> but.men[j];
		}
		
		butai.push_back(but);
	}
	cin >> x;
}

double CalculateUsageAll(vector<Butas>& butai, int x)
{
	double AllUsage = 0;
	for (size_t i = 0; i < butai.size(); i++)
	{
		butai[i].CalcUsage(x);
		AllUsage += butai[i].UsageEur;
	}
	return AllUsage;
}

void Printer(ofstream& out, vector<Butas>& butai, double allUsage)
{
	out << setw(8) << "Buto Nr." << setw(12) << "Pavarde" << setw(20) << "puse metu eurais" << endl;
	for (size_t i = 0; i < butai.size(); i++)
	{
		out << setw(8) << butai[i].nr << setw(12) << butai[i].surname << setw(20) << butai[i].UsageEur << endl;
	}

	out << endl << "Is viso name buvo sunaudota: " << allUsage << " energijos eurais.";

}