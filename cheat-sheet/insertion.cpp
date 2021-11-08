void Insertion(int array[], int v, int& n, int element)
{
	for (int i = n; i > v; i--)
	{
		array[i] = array[i - 1];
	}
	array[v] = element;
	n++;
}

/*
Iterpimo i masyva funkcija
    array - masyvas i kuri iterpsime
    v - indexas, kuriame norime, kad atsirastu naujas elementas
    n - masyvo dydis (paskutinio elemento indexas bus n-1)
    element - elementas, kuri iterpiame
*/