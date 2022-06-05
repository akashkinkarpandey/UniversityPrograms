#include <stdio.h>
#include <limits.h>
//0-based indexing in graph
// Shortest path from any node to any node using Bellman Ford
// TC->O((N-1)*E)
// SC->O(N)
// Works for directed graph
// negative edges allowed in directed graph(but not in undirected graph)
// negative cycle not allowed
// we can detect negative edge weight cycle using Bellman Ford
// undirected graph can be converted to directed graph and then bellman ford algo can be applied
// if graph is undirected,then negative edge is not allowed in case bellman ford has to be applied on it as negative edge in undirected graph means negative cycle in directed graph

//input:-
// Enter number of nodes,edges
// 6
// 7
// Enter source,destination,weight
// 3 2 6
// Enter source,destination,weight
// 5 3 1
// Enter source,destination,weight
// 0 1 5
// Enter source,destination,weight
// 1 5 -3
// Enter source,destination,weight
// 1 2 -2
// Enter source,destination,weight
// 3 4 -2
// Enter source,destination,weight
// 2 4 3
// Enter source
//0

//output
// Matrix is
// 0 5 3 2147483647 6 2
// 0 5 3 3 1 2
// 0 5 3 3 1 2
// 0 5 3 3 1 2
// 0 5 3 3 1 2
//Node Distance
// 0 0
// 1 5
// 2 3
// 3 3
// 4 1
// 5 2
struct node
{
    int u, v, wt;
};
int main()
{
    int n, j, e, i;
    printf("Enter number of nodes,edges\n");
    scanf("%d %d", &n, &e);
    struct node edges[e];
    int mat[n-1][n];
    for (i = 0; i < e; i++)
    {
        int u, v, wt;
        printf("Enter source,destination,weight\n");
        scanf("%d %d %d", &u, &v, &wt);
        edges[i].u = u;
        edges[i].v = v;
        edges[i].wt = wt;
    }
    int src;
    printf("Enter source\n");
    scanf("%d", &src);
    int dist[n];
    for (i = 0; i < n; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
    int c=0;
    for (int i = 0; i < n - 1; i++)
    {
        for (j = 0; j < e; j++)
        {
            if (dist[edges[j].u] == INT_MAX)
                continue;
            if (dist[edges[j].u] + edges[j].wt < dist[edges[j].v])
            {
                dist[edges[j].v] = dist[edges[j].u] + edges[j].wt;
            }
        }
        for(j=0;j<n;j++)
        mat[c][j]=dist[j];
        c++;
    }
    int fl = 0;
    for (j = 0; j < e; j++)
    {
        if (dist[edges[j].u] + edges[j].wt < dist[edges[j].v])
        {
            printf("Negative Edge weight Cycle present\n");
            fl = 1;
            break;
        }
    }
    printf("Matrix is\n");
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    if (fl == 0)
    {
        printf("Node Distance\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d %d\n", i, dist[i]);
        }
    }
    return 0;
}