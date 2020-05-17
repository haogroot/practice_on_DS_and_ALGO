#include <string.h>
#include <assert.h>
#include "arrayList.h"

int init(arrayList *array, int size)
{
    array->data = calloc(size, sizeof(int));
    array->size = size;
    array->used_size = 0;
    return 0;
}

int size(arrayList *array)
{
    return array->size;
}

int add(arrayList *array, int element)
{
    if (array->used_size == array->size)
    {
        ensureCapacity(array, (array->size + 10));
    } 
    array->data[array->used_size] = element;
    array->used_size++;
    return 0;
}

int addIndex(arrayList *array, int index, int element)
{
    if(index < 0 || index > array->used_size)
    {
        printf("index is out of range\n");
        return -1;
    }
    /* Swap the array[index] and array[used_size] */
    array->data[array->used_size] = array->data[index];
    array->data[index] = element;
    return 0;
}

int delIndex(arrayList *array, int index)
{
    if(index < 0 || index > array->used_size)
    {
        printf("index is out of range\n");
        return -1;
    }
    memcpy(&array->data[index], &array->data[index+1], array->used_size - index -1);
    array->used_size--;
    return 0;
}

void printAll(arrayList *array)
{
    printf ("size of ArrayList = %ld, used_size = %ld\n", array->size, array->used_size);
    for(int i = 0; i < array->used_size; i++)
    {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

void ensureCapacity(arrayList *array, int size)
{
    if (size > array->size)
    {
        int *temp_buffer = calloc(size, sizeof(int));
        memcpy(temp_buffer, array->data, (array->used_size)*sizeof(int));
        free(array->data);
        array->data = temp_buffer;
        array->size = size;
    }
}

int main()
{
    arrayList list;
    init(&list, 10);
    assert(size(&list) == 10);
    for(int i=0; i<12; i++)
    {
        add(&list, i);
    }
    printAll(&list);
    assert(size(&list) == 20);
    ensureCapacity(&list, 30);
    assert(list.size == 30);
    addIndex(&list, 2, 5566);
    assert(list.data[2] == 5566);
    printAll(&list);
    delIndex(&list, 2);
    assert(list.data[2] != 5566);
    printAll(&list);
    return 0;
}
