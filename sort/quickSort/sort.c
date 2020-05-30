#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEST_SIZE 10

void swap (int *dataA, int *dataB)
{
    int tmp = *dataA;
    *dataA = *dataB;
    *dataB = tmp;
}

int partition (int *arr, int left, int right)
{
    /* Choose arr[right] as pivot */
    int i = left;
    for (int j = left; j <= right-1; j++)
    {
        if (arr[j] < arr[right])
        {
            swap (&arr[i], &arr[j]);
            i++;
        }
    }
    swap (&arr[i], &arr[right]);
    return i; 
}

void quickSort (int *arr, int left, int right)
{
    if (left < right)
    {
        int pivot = partition (arr, left, right);

        quickSort (arr, left, pivot-1);
        quickSort (arr, pivot+1, right);
    }
}

void sort (int *array, int size)
{
    quickSort (array, 0, size-1);
    printf ("\nAfter quick sort:\n");
    for(int i=0; i<TEST_SIZE; i++)
    {
        printf("%d ", array[i]);
    }
}

int main ()
{
    srand(time(NULL));
    int arr[TEST_SIZE];
    for(int i=0; i<TEST_SIZE; i++)
    {
        arr[i] = (rand()%100) + 1;
        printf("%d ", arr[i]);
    }
    sort (&arr[0], TEST_SIZE);
    return 0;
}
