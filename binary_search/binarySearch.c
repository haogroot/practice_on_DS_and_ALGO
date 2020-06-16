#include "sort.h"
#include <time.h>
/**
 * Execute binary search iteraively.
 * \param arr   sorted data array
 * \param n     array size
 * \param value search value
 * \return -1 if no value in array or index if found the value.
 */
int iterBinarySearch(int *arr, int n, int value)
{
    int left = 0;
    int right = n -1;
    
    while (left <= right)
    {
        int mid = left + ((right-left)>>1);
        if (arr[mid] == value)
            return mid;
        if (arr[mid] < value)
        {
            left = mid + 1;
        }
        else if (arr[mid] > value)
        {
            right = mid - 1;
        }
    }    
    return -1;
}

int recuBinarySearch(int *arr, int left, int right, int value)
{
    if (left > right)
       return -1;
   int mid = left + ((right-left)>>1); 
   if (arr[mid] == value)
       return mid;
   else if (arr[mid] < value)
       return recuBinarySearch (arr, mid+1, right, value);
   else
       return recuBinarySearch (arr, left, mid-1, value);
}

int main ()
{
    srand(time(NULL));
    int arr[TEST_SIZE];
    for(int i=0; i<TEST_SIZE; i++)
    {
        arr[i] = (rand()%1000) + 1;
        printf("%d ", arr[i]);
    }
    sort (&arr[0], TEST_SIZE);

    printf ("\nInput search number:\n");
    int search = 0;
    scanf ("%d", &search);
    int ans = iterBinarySearch(&arr[0], TEST_SIZE, search);
    printf("Search result: %d\n", ans);
    ans = recuBinarySearch(&arr[0], 0, TEST_SIZE, search);
    printf("Search result: %d\n", ans);
    return 0;
}
