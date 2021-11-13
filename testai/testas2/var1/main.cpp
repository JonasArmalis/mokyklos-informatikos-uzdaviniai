#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void SkaitytiMas(ifstream & input, int mas[], int & n);
void SpausdintiMas(ofstream & output, int mas[], int n);
int MaxIndx(int mas[], int n);
void Keitimas(int& a, int &b);


int main()
{
	ifstream inputA("maspirmas.txt");
	ifstream inputB("masantras.txt");
	ofstream output("rez.txt");

	int n = 0;
	int m = 0;
	int A[100];
	int B[100];

	int maxIndexA;
	int maxIndexB;

	SkaitytiMas(inputA, A, n);
	SkaitytiMas(inputB, B, m);

	//Isvedimas pries keitima
	output << "A masyvas pries keitima: " << endl;
	SpausdintiMas(output, A, n);
	output << "B masyvas pries keitima: " << endl;
	SpausdintiMas(output, B, m);
	output << endl;

	//Didziausiu reiksmiu indexu radimas
	maxIndexA = MaxIndx(A, n);
	maxIndexB = MaxIndx(B, m);

	//Reiksmiu keitimas vietomis
	Keitimas(A[maxIndexA], A[0]);
	Keitimas(B[maxIndexB], B[m - 1]);

	//Isvedimas po keitimo
	output << "A masyvas po keitimo: " << endl;
	SpausdintiMas(output, A, n);
	output << "B masyvas po keitimo: " << endl;
	SpausdintiMas(output, B, m);


	inputA.close();
	inputB.close();
	output.close();
	return 0;
}

int MaxIndx(int mas[], int n)
{
	int max = mas[0];
	int index = 0;

	for (int i = 1; i < n; i++)
	{
		if (mas[i] > max)
		{
			max = mas[i];
			index = i;
		}
	}
	return index;
}

void Keitimas(int& a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void SkaitytiMas(ifstream & input, int mas[], int & n) 
{
	for (int i = 0; !input.eof(); i++)
	{
		input >> mas[i];
		n++;
	}
}

void SpausdintiMas(ofstream & output, int mas[], int n)
{
	for (int j = 0; j < n; j++)
		output << setw(3) << j + 1;
	
	output << endl;

	for (int i = 0; i < n; i++)
		output << setw(3) << mas[i];

	output << endl;
}