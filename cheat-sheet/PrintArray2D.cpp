void PrintArr2D(ofstream& output, int n, int m, int arr[][100])
{
	output << setw(2) << "Eil. nr." << setw(15) << "Skaiciai" << endl;
	for (int i = 0; i < n; i++)
	{
		output << setw(2) << i + 1 << setw(10);
		for (int j = 0; j < m; j++)
		{
			output << arr[i][j] << setw(4);
		}
		output << endl;
	}
	output << endl;
}

/*
Dvimacio masyvo nuskaitymo funkcija
	output - failas i kuri rasoma
	n - masyvo eiluciu kiekis
	m - masyvo stulpeliu kiekis
	arr - spausdinamas masyvas
*/