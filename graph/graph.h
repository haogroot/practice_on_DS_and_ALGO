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

struct Graph* createGraph(int vertexNum);
void addEdge(struct Graph *graph, int src, int dst);
void printGraph(struct Graph *graph);

void bfsTraversal(struct Graph *graph, int src, int dst);
void dfsTraversal(struct Graph *graph, int src, int dst);
