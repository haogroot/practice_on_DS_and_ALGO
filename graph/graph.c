#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct AdjList
{
    struct Node *head;
};

struct Graph
{
    int V;
    struct AdjList *array;
};

struct Graph* createGraph(int vertexNum)
{
    struct Graph *graph = (struct Graph*) malloc(sizeof(struct Graph)); 
    graph->V = vertexNum;
    graph->array = (struct AdjList*) malloc(vertexNum * sizeof(struct AdjList));
    for(int i=0; i<vertexNum; i++)
    {
        graph->array[i].head = NULL;
    }

    return graph;
}

void addEdge(struct Graph *graph, int src, int dst)
{
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = dst;
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

void printGraph(struct Graph *graph)
{
    struct Node *tmp = NULL;
    for(int i=0; i<graph->V; i++)
    {
        printf("%d: ", i);
        tmp = graph->array[i].head;
        while(tmp != NULL)
        {
            printf("%d ", tmp->data);
            tmp = tmp->next;
        }
        printf("\n");
    }
}

int main()
{
    struct Graph *g1 = createGraph(7);
    addEdge(g1, 0, 1);
    addEdge(g1, 0, 3);
    addEdge(g1, 1, 2);
    addEdge(g1, 2, 5);
    addEdge(g1, 3, 1);
    addEdge(g1, 3, 4);
    addEdge(g1, 3, 6);
    addEdge(g1, 4, 6);
    addEdge(g1, 5, 6);

    printGraph(g1);

    return 0;
}
