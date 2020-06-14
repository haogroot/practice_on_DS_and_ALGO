#include "graph.h"

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
    bfsTraversal(g1, 0, 6);

    dfsTraversal(g1, 0, 6);

    return 0;
}
