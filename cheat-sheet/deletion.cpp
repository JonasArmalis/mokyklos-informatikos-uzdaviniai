void Deletion(int array[], int v, int& n)
{
	for (int i = v; i <= n; i++)
	{
		array[i] = array[i + 1];
	}
	n--;
}

/*
Vieno elemento salinimo is masyvo funkcija
    array - masyvas is kurio salinama
    v - salinamo elemento indexas
    n - masyvo dydis (paskutinio elemento indexas bus n-1)
*/