#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list *next;
};

/** 
 * This global variable is for storing new list head 
 * when reverse linked list recursivly.
 */
struct list *newHead = NULL;

int list_add(struct list *head, int data)
{
    struct list *new = (struct list*) malloc(sizeof(struct list));
    new->data = data;
    while(head->next != NULL)
        head = head->next;

    head->next = new;
    return 0;
}

void print(struct list *head)
{
    //head = head->next;
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void reverseIterative(struct list *head)
{
    struct list *tmp, *current, *prev = NULL;
    current = head->next;
    while(current != NULL)
    {
        tmp = current;
        current = current->next;
        tmp->next = prev;
        prev = tmp;
    }
    head->next = tmp;
}

struct list *recurHelper (struct list *node)
{
    if (node->next == NULL)
    {
        newHead = node;
        return node;
    }
    struct list *tmp = recurHelper (node->next);
    tmp->next = node;
    node->next = NULL;
    return node;
}

void reverseRecursive (struct list *head)
{
    recurHelper (head->next);
    head->next = newHead;

}
        
int main()
{
    struct list guard_head;
    guard_head.next = NULL;
    /* Use this value to denoted this node as head */
    guard_head.data = 5566;
    for(int i=0; i<10; i++)
    {
        list_add(&guard_head, i);
    }
    print(&guard_head);

    reverseIterative(&guard_head);
    print(&guard_head);

    reverseRecursive(&guard_head);
    print(&guard_head);

    return 0;
}
