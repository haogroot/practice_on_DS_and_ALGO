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

bool enqueue(Queue *queue, int data)
{
   if (queue->tail == QUEUE_SIZE)
   {
        if (queue->head == 0)
           return false;
        for (int i=0; i < (queue->tail - queue->head); i++) 
        {
            queue->val[i] = queue->val[i+queue->head];
        }
        queue->tail = queue->tail - queue->head;
        queue->head = 0;
   }
   queue->val[queue->tail++] = data;
   return true;
}

bool dequeue(Queue *queue)
{
    if (queue->head == QUEUE_SIZE)
        return false;
    queue->head++;
    return true;
}

void print (Queue *queue)
{
    printf ("Queue = ");
    for (int i=queue->head; i<queue->tail; i++)
    {
        printf ("%d ", queue->val[i]);
    }
    printf ("\n");
}


int main ()
{
    Queue queue;
    queue.tail = 0;
    queue.head = 0;
    for (int i=0;i<10;i++)
        enqueue(&queue, i);
    print (&queue);
    for (int i=0;i<10;i++)
        dequeue(&queue);
    print (&queue);

    printf ("%d, %d\n", queue.head, queue.tail);

    for (int i=0;i<3;i++)
        enqueue(&queue, i);
    print (&queue);
}
