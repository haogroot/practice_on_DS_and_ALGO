#include "graph.h"
#include "queue.h"

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

void addEdge (struct Graph *graph, int src, int dst)
{
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = dst;
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

void printGraph (struct Graph *graph)
{
    printf("Print the Graph: \n");
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

void printPath (int *prev, int s, int d)
{
    if(prev[d] != -1 && s != d)
    {
        printPath (prev, s, prev[d]);
    }
    printf("%d ", d);
}

void bfsTraversal(struct Graph *graph, int src, int dst)
{
    //Init queue
    Queue waitqueue;
    waitqueue.head = 0;
    waitqueue.tail = 0;
    
    int *visited = (int *)malloc ((graph->V) * sizeof(int));
    for(int i=0; i<graph->V; i++)
    {
        visited[i] = 0;
    }
    int *prev = (int *)malloc ((graph->V) * sizeof(int));
    for(int i=0; i<graph->V; i++)
    {
        prev[i] = -1;
    }

    struct Node *tmp = graph->array[src].head;
    int previousNode = src;
    enqueue(&waitqueue, src);

    while (queueSize(&waitqueue) > 0)
    {
        previousNode = waitqueue.val[waitqueue.head]; 
        tmp = graph->array[previousNode].head;
        while(tmp != NULL)
        {
            if (visited[tmp->data] == 0)
            {
                enqueue(&waitqueue, tmp->data);
                visited[tmp->data] = 1;
                prev[tmp->data] = previousNode;
            }
            tmp = tmp->next;
        }
        dequeue(&waitqueue);
    }

    printf("After BFS traversal, prev[] result: \n");
    for(int i=0; i<graph->V; i++)
    {
        printf("%d ", prev[i]);
    }
    printf ("\n");

    /* Change dst to check different src-dst path */
    printf("Path from %d to %d: \n", src, dst);
    printPath (prev, src, dst);
    printf("\n");

    free(visited);
    free(prev);
}

void recurDFS(struct Graph* graph, int src, int dst, int *visited, int *prev)
{
    if (src == dst)
        return;
    struct Node *tmp = graph->array[src].head;
    while (tmp != NULL)
    {
        if (visited[tmp->data] == 0)
        {
            visited[tmp->data] = 1;   
            prev[tmp->data] = src;
            printf("%d ", tmp->data);
            recurDFS (graph, tmp->data, dst, visited, prev);
        }
        tmp = tmp->next;
    }
}

void dfsTraversal(struct Graph *graph, int src, int dst)
{
    int *visited = (int *) malloc(graph->V * sizeof(int));
    for(int i=0; i<graph->V; i++)
    {
        visited[i] = 0;
    }
    int *prev = (int *) malloc(graph->V * sizeof(int));
    for(int i=0; i<graph->V; i++)
    {
        prev[i] = -1;
    }
    printf("The order to traverse graph dfs...\n");

    recurDFS(graph, src, dst, visited, prev);
    printf("\n");

    printf("After DFS traversal, prev[] result: \n");
    for(int i=0; i<graph->V; i++)
    {
        printf("%d ", prev[i]);
    }
    printf ("\n");

    /* Change dst to check different src-dst path */
    printf("Path from %d to %d:\n", src, dst);
    printPath (prev, src, dst);
    printf("\n");

    free(visited);
    free(prev);
}

