#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

class Player {
	string name;
	string surname;
	double height;
	int fines;
	int twoPointers;
	int threePointers;
	int total;

public:
	Player()
	{
		height = 0;
		fines = 0;
		twoPointers = 0;
		threePointers = 0;
		total = 0;
	}

	Player(string n, string sur, double h, int f, int two, int three)
	{
		name = n;
		surname = sur;
		height = h;
		fines = f;
		twoPointers = two;
		threePointers = three;
		total = 0;
	}

	Player operator + (Player param) 
	{
		fines = fines + param.GetFines();
		twoPointers = twoPointers + param.Get2Pointers();
		threePointers = threePointers + param.Get3Pointers();

		return *this;
	}

	void CalculateTotal()
	{
		total = fines + twoPointers + threePointers;
	}

	string GetName()
	{
		return name;
	}
	string GetSurname()
	{
		return surname;
	}
	double GetHeight()
	{
		return height;
	}
	int GetFines() 
	{
		return fines;
	}
	int Get2Pointers()
	{
		return twoPointers;
	}
	int Get3Pointers()
	{
		return threePointers;
	}

	void SetName(string val)
	{
		name = val;
	}
	void SetSurname(string val)
	{
		surname = val;
	}
	void SetHeight(double val)
	{
		height = val;
	}
	void SetFines(int val)
	{
		fines = val;
	}
	void Get2Pointers(int val)
	{
		twoPointers = val;
	}
	void Get3Pointers(int val)
	{
		threePointers = val;
	}
	int GetTotal()
	{
		return total;
	}

};

void ReadFile(ifstream & in, vector<Player> & Arr);
void Filter(vector<Player> & A, vector<Player> & B);
void Form(vector<Player> & A, vector<Player> & C);
bool compare(Player a, Player b);
Player FindBestPlayer(vector<Player> & C);
void PrintArr(ofstream & out, vector<Player> & X);
void PrintResults(ofstream & out, vector<Player> & A, vector<Player> & B, vector<Player> & C, Player best);

int main()
{
	ifstream in1("Zalgiris.txt");
	ifstream in2("Rungtynes.txt");
	ofstream out("Rezultatai.txt");

	vector<Player> A;
	vector<Player> B;
	vector<Player> C;

	Player bestPlayer;

	ReadFile(in1, A);
	ReadFile(in2, B);

	//Pradiniu duomenu spausdinimas
	{
		out << "Zalgirio komanda: " << endl;
		PrintArr(out, A);
		out << endl; 
	}

	Filter(A, B);
	Form(A, C);

	sort(C.begin(), C.end(), compare);

	bestPlayer = FindBestPlayer(C);
	
	PrintResults(out, A, B, C, bestPlayer);
	
	in1.close();
	in2.close();
	out.close();

	cout << "Programa baige darba.";
	return 0;
}

void ReadFile(ifstream & in, vector<Player> & Arr)
{
	while (!in.eof())
	{
		string name;
		string surname;
		double height;
		int fines;
		int twoPointers;
		int threePointers;

		in >> name >> surname >> height >> fines >> twoPointers >> threePointers;
		Player val(name, surname, height, fines, twoPointers, threePointers);
		Arr.push_back(val);
	}
}

void Filter(vector<Player> & A, vector<Player> & B)
{
	for (size_t i = 0; i < B.size(); i++)
	{
		bool match = false;
		for (size_t j = 0; j < A.size() && !match; j++)
		{
			if (B[i].GetName() == A[j].GetName() && B[i].GetSurname() == A[j].GetSurname())
			{
				A[j] = A[j] + B[i];
				match = true;
				break;
			}
		}
		if (!match)
		{
			A.push_back(B[i]);
		}
	}
}

void Form(vector<Player> & A, vector<Player> & C)
{
	for (size_t i = 0; i < A.size(); i++)
	{
		A[i].CalculateTotal();
		C.push_back(A[i]);
	}
}

bool compare (Player a, Player b)
{
	return a.GetSurname() < b.GetSurname();
}

Player FindBestPlayer(vector<Player> & C)
{
	Player best = C[0];

	for (size_t i = 1; i < C.size(); i++)
	{
		if (C[i].GetTotal() > best.GetTotal())
			best = C[i];
	}
	return best;
}

void PrintResults(ofstream & out, vector<Player> & A, vector<Player> & B, vector<Player> & C, Player best)
{

	out << "Rungtyniu zaidejai: " << endl;
	PrintArr(out, B);
	out << endl;

	out << "Visi zaidejai: " << endl;

	out << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15) << "Ugis" << setw(15) << "Viso imesta" << endl;
	for (size_t i = 0; i < C.size(); i++)
	{
		out << setw(15) << C[i].GetSurname() << setw(15) << C[i].GetName() << setw(15) << C[i].GetHeight() << setw(15) << C[i].GetTotal() << endl;
	}

	out << endl;
	out << "Taikliausias zaidejas: " << best.GetName() << " " << best.GetSurname() << endl;
	out << "Sis zaidejas is viso imete: " << best.GetTotal() << " metimu." << endl;

}

void PrintArr(ofstream & out, vector<Player> & X)
{
	out << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15) << "Baudos" << setw(15) << "Dvitaskiai" << setw(15) << "Tritaskiai" << endl;
	for (size_t i = 0; i < X.size(); i++)
	{
		out << setw(15) << X[i].GetSurname() << setw(15) << X[i].GetName() << setw(15) << X[i].GetFines() << setw(15) << X[i].Get2Pointers() << setw(15) << X[i].Get3Pointers() << endl;
	}
}