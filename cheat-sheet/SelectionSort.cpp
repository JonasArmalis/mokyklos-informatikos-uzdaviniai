void SelectionSort(int array[], int n)
{
    int index;
 
    for (int i = 0; i < n-1; i++)
    {
        index = i;

        for (int j = i+1; j < n; j++)
            if (array[j] < array[index])
                index = j;

        swap(array[index], array[i]);
    }
}

/*
Destytojo vadinamas "Min Max" rikiavimo algoritmas :Dd
    array - rikuojamas masyvas
    n - masyvo dydis (paskutinio elemento indexas bus n-1)
*/