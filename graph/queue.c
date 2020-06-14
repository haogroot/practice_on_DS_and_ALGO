#include "queue.h"

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

int queueSize(Queue *queue)
{
    return queue->tail - queue->head;
}


