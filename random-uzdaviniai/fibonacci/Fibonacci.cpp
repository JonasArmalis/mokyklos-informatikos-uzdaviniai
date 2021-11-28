#include <iostream>
using namespace std;

int main() 
{
	int n;
	int num1 = 1, num2 = 1;

	cout << "Kiek skaiciu isvesti? " << endl;
	cin >> n;

	cout << num1 << " " << num2 << endl;

	for (int i = 0; i < n; i++)
	{
		int temp;
		temp = num2;
		num2 += num1;
		num1 = temp;
		cout << num2 <<endl;
	}
}