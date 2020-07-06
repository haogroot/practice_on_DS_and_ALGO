#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stackNode
{
    int data;
    struct stackNode *next;
    struct stackNode *prev;
};

bool isStart(char s)
{
    if (s == '{' || s == '[' || s == '(')
        return true;
    else
        return false;
}

bool isValid(char * s){
    struct stackNode head;
    head.next = NULL;
    struct stackNode *top = &head, *tmp;
    
    while (*s != '\0')
    {
        if (isStart(*s)) 
        {
            struct stackNode *new = malloc(sizeof(struct stackNode));
            new->data = *s;
            new->next = NULL;
            top->next = new;
            new->prev = top;
            top = new;
        }
        else
        {
            if (*s == ')')
            {
                if(top->data != '(')
                {
                    return false;
                }
            }
            if (*s == ']')
            {
                if (top->data != '[')
                {
                    return false;
                }
            }
            if (*s == '}')
            {
                if (top->data != '{')
                {
                    return false;
                }
            }
            
            tmp = top;
            top = tmp->prev;
            top->next = NULL;
            free(tmp);
        } 
        s++;
    }
    if (head.next == NULL)
        return true;
    else
        return false;
}

int main()
{
    char s[] = "({)}";
    if(isValid (s))
    {
        printf ("It is valid\n");
    }
    else
    {
        printf ("Sorry, not valid\n");
    }
    return 0;
}
