#include <stdio.h>
#include <stdlib.h>

typedef struct arrayList
{
    size_t size;
    size_t used_size;
    int *data;
} arrayList;

/* Return the capacity size of arrayList. */
int size(arrayList *array);

/* Initialize arrayList. */
int init(arrayList *array, int size);

/* Add element to the end of arrayList. If the capacity is not enough,
 * add 10 more capacity. */ 
int add(arrayList *array, int element);

/* Add element to the index of arrayList. If the index is out of range,
 * return -1. */
int addIndex(arrayList *array, int index, int element);

/* Delete element to the index of arrayList. If the index is out of range,
 * return -1. */
int delIndex(arrayList *array, int index);

void printAll(arrayList *array);

/* If the argument size is larger than the size of arrayList,
 * enlarge its size to the argument size. */
void ensureCapacity(arrayList *array, int size);

