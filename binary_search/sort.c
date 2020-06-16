#include "sort.h"

void merge (int arr[], int left, int mid, int right)
{
    int buffer_size = right - left +1;
    int temp[buffer_size];
    int i = left, j = mid +1;
    int index = 0;
    while (i <= mid && j <= right)
    {
        if (arr[i] > arr[j])
        {
            temp[index] = arr[j];
            j++;
        }
        else
        {
            temp[index] = arr[i];
            i++;
        }
        index++;
    }
    while(i <= mid)
    {
        temp[index] = arr[i];
        index++;
        i++;
    }
    while(j <= right)
    {
        temp[index] = arr[j];
        index++;
        j++;
    }
    for (int p=left, q=0; p<=right; p++, q++)
    {
        arr[p] = temp[q];
    }
}

void mergeSort (int *arr, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right)/2;
        mergeSort (arr, left, mid);
        mergeSort (arr, mid+1, right);

        merge (arr, left, mid, right);
    }
}

void sort (int *array, int size)
{
    mergeSort (array, 0, size-1);
    printf ("\nAfter merge sort:\n");
    for(int i=0; i<TEST_SIZE; i++)
    {
        printf("%d ", array[i]);
    }
}

