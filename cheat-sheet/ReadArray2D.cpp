void ReadArr2D(ifstream& input, int& n, int& m, int arr[][100])
{
	input >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			input >> arr[i][j];
		}
	}
}

/*
Dvimacio masyvo nuskaitymo funkcija
	input - failas is kurio skaitoma
	n - masyvo eiluciu kiekis
	m - masyvo stulpeliu kiekis
	arr - skaitomas masyvas
*/