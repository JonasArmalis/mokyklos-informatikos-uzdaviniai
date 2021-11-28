void ReadArr(ifstream& input, int& n, int arr[])
{
	input >> n;
	for (int i = 0; i < n; i++)
	{
		input >> arr[i];
	}
}

/*
Masyvo nuskaitymo funkcija
	input - failas is kurio skaitoma
	n - masyvo dydis
	arr - skaitomas masyvas
*/