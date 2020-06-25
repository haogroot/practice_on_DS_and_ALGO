#include <string.h>
#include <assert.h>
#include "arrayList.h"

int size(arrayList *array)
{
    return array->size;
}

bool init(arrayList *array, int size)
{
    array->data = (int *) calloc (size, sizeof(int));

    if (array->data != NULL)
    {
        array->size = size;
        array->used_size = 0;
        return true;
    }
    return false;
}

/* Add element to the end of arrayList. If the capacity is not enough,
 * add 10 more capacity. */ 
bool add(arrayList *array, int element)
{
    if (array->used_size == array->size)
    {
        if(!ensureCapacity (array, (array->size+10)))
            return false;
    }
    array->data[array->used_size] = element;
    array->used_size++;
    return true;
}

/* Add element to the index of arrayList. */
bool addIndex(arrayList *array, size_t index, int element)
{
    if (index < 0 || index > (array->used_size-1))
        return false;
    int tmp = array->data[index];
    array->data[index] = element;
    array->data[array->used_size] = tmp;
    array->used_size++;
    return true; 
}

/* Delete element to the index of arrayList.*/
bool delIndex(arrayList *array, size_t index)
{
    if (index < 0 || index > (array->used_size-1))
        return false;
    /* If the src and dest object in memcpy are overlapping, the behavior may be undefined. */
    //memcpy(&array->data[index], &array->data[index+1], array->used_size-(index+1));
    for (size_t i = index; i < (array->used_size-1); i++)
    {
        array->data[i] = array->data[i+1];
    }
    array->used_size--;
    return true;
}

void printAll(arrayList *array)
{
    for (size_t i=0; i<array->used_size; i++)
    {
        printf("%d ", array->data[i]);
    }
    printf ("\n");
}

/* If the argument size is larger than the size of arrayList,
 * enlarge its size to the argument size. */
bool ensureCapacity(arrayList *array, size_t size)
{
    if (size > array->size)
    {
        int *tempBuffer = (int *) calloc (size, sizeof(int));
        if (tempBuffer != NULL)
        {
            memcpy (tempBuffer, array->data, (array->used_size)*sizeof(int));
            free (array->data);
            array->data = tempBuffer;
            array->size = size;
            return true;
        }
    }
    return false;
}

int main()
{
    arrayList list;
    assert(init(&list, 10) == true);
    assert(size(&list) == 10);

    for(int i=0; i<12; i++)
    {
        add(&list, i);
    }
    printAll(&list);
    assert(size(&list) == 20);
    assert(list.used_size == 12);

    ensureCapacity(&list, 30);
    assert(list.size == 30);
    
    addIndex(&list, 2, 5566);
    printAll(&list);
    assert(list.data[2] == 5566);
    assert(list.data[12] == 2);
    assert(list.used_size == 13);

    delIndex(&list, 2);
    printAll(&list);
    assert(list.data[2] != 5566);
    assert(list.data[2] == 3);
    assert(list.used_size == 12);
    assert(list.data[list.used_size-1] == 2);
    return 0;
}
