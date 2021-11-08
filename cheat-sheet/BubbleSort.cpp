void BubbleSort(int array[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (array[j] > array[j+1])
                swap(array[j], array[j+1]);
        }
    }
}

/*
Burbulo rikiavimo algoritmas
    array - rikuojamas masyvas
    n - masyvo dydis (paskutinio elemento indexas bus n-1)
*/