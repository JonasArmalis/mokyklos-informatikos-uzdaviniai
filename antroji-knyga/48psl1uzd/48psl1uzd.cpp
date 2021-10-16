#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

void skaitymas(vector<int>& NAMAI, vector<int>& GYVENTOJAI, ifstream & input);
int gyventojuSK(vector<int>GYVENTOJAI);
void kairDesNamaiGyv(vector<int> NAMAI, vector<int> GYVENTOJAI, int& desGyv, int& kairGyv, int& kairNamai, int& desNamai);
void isvedimas(int gyvSk, int kairGyv, int desGyv, double kairVidurkis, double desVidurkis, ofstream & output);

int main() {
	ifstream input("gyventojai.txt");
	ofstream output("rez.txt");

	vector <int> NAMAI;
	vector <int> GYVENTOJAI;

	int gyvSk;
	int kairGyv = 0;
	int DesGyv = 0;
	int kairNamai = 0;
	int desNamai = 0;

	double kairVidurkis;
	double desVidurkis;

	skaitymas(NAMAI, GYVENTOJAI, input);
	gyvSk = gyventojuSK(GYVENTOJAI);

	kairDesNamaiGyv(NAMAI, GYVENTOJAI, DesGyv, kairGyv, kairNamai, desNamai);

	kairVidurkis = kairGyv / (double)kairNamai;
	desVidurkis = DesGyv / (double)desNamai;

	isvedimas(gyvSk, kairGyv, DesGyv, kairVidurkis, desVidurkis, output);

	input.close();
	output.close();

	return 0;
}

void skaitymas(vector<int>& NAMAI, vector<int>& GYVENTOJAI, ifstream & input) {
	for (int i = 0; !input.eof(); i++) {
		int nr, gyv;
		input >> nr;
		input >> gyv;

		NAMAI.push_back(nr);
		GYVENTOJAI.push_back(gyv);
	}
}

int gyventojuSK(vector<int> GYVENTOJAI) {
	int suma = 0;

	for (size_t i = 0; i < GYVENTOJAI.size(); i++) {
		suma += GYVENTOJAI[i];
	}
	return suma;
}

void kairDesNamaiGyv(vector<int> NAMAI, vector<int> GYVENTOJAI, int& desGyv, int& kairGyv, int& kairNamai, int& desNamai) {
	for (size_t i = 0; i < NAMAI.size(); i++) {
		int nr = NAMAI[i];
		int gyv = GYVENTOJAI[i];

		if (nr % 2) {
			kairGyv += gyv;
			kairNamai++;
		}
		else {
			desGyv += gyv;
			desNamai++;
		}
	}
}


void isvedimas(int gyvSk, int kairGyv, int desGyv, double kairVidurkis, double desVidurkis, ofstream & output) {
	output << gyvSk << endl;
	output << kairGyv << endl;
	output << desGyv << endl;
	output << fixed << setprecision(2) << kairVidurkis << endl;
	output << fixed << setprecision(2) << desVidurkis << endl;
}
