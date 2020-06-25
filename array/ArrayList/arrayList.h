#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct arrayList
{
    size_t size;
    size_t used_size;
    int *data;
} arrayList;

/* Return the capacity size of arrayList. */
int size(arrayList *array);

/**
 * Initialize arrayList.
 * \return true if initialize successful, 
 *         false if array is not NULL.
 */
bool init(arrayList *array, int size);

/**
 * Add element to the end of arrayList.
 * If the capacity is not enough, add 10 more capacity.
 */ 
bool add(arrayList *array, int element);

/**
 * Add element to the index of arrayList and the original element
 * shall be move to the end of array.
 * \return false if index is larger than the used_size-1.
 */
bool addIndex(arrayList *array, size_t index, int element);

/** 
 * Delete element at the index of arrayList. 
 * \return false if index is larger than the used_size -1
 */
bool delIndex(arrayList *array, size_t index);

void printAll(arrayList *array);

/**
 * If the argument size is larger than the size of arrayList,
 * enlarge its size to the argument size. 
 */
bool ensureCapacity(arrayList *array, size_t size);

