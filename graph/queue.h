#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUEUE_SIZE 10

typedef struct queue
{
    int tail;
    int head;
    int val[QUEUE_SIZE];
} Queue;


bool enqueue(Queue *queue, int data);
bool dequeue(Queue *queue);
void print (Queue *queue);
int queueSize(Queue *queue);
