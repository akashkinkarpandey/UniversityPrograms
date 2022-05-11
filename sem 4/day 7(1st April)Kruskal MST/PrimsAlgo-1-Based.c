// Prim's Algo perfectly working
// 1-Based Indexing
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
//input
// Enter number of nodes,edges
// 8 11
// Enter source,destination,weight
// 1 2 55
// Enter source,destination,weight
// 1 3 25
// Enter source,destination,weight
// 1 4 45
// Enter source,destination,weight
// 2 5 5
// Enter source,destination,weight
// 3 5 40
// Enter source,destination,weight
// 4 5 20
// Enter source,destination,weight
// 4 8 30
// Enter source,destination,weight
// 8 7 50
// Enter source,destination,weight
// 7 5 15
// Enter source,destination,weight
// 7 6 10
// Enter source,destination,weight
// 5 6 35

//output
// MST is
// 2 5 5
// 1 3 25
// 4 5 20
// 3 5 40
// 6 7 10
// 5 7 15
// 4 8 30
// Minimum sum of edges is 145

int findMinVertex(int weights[], bool visited[], int n)
{
    int minVertex = -1;
    int i;
    for (i = 1; i <= n; i++)
    {
        if (!visited[i] && (minVertex == -1 || weights[i] < weights[minVertex]))
            minVertex = i;
    }
    return minVertex;
}
int main()
{
    int n, e, i, j;
    printf("Enter number of nodes,edges\n");
    scanf("%d %d", &n, &e);
    int edges[n + 1][n + 1];
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            edges[i][j] = 0;
    }
    for (i = 0; i < e; i++)
    {
        int u, v, weight;
        printf("Enter source,destination,weight\n");
        scanf("%d %d %d", &u, &v, &weight);
        edges[u][v] = weight;
        edges[v][u] = weight;
    }
    printf("\n");

    int parent[n + 1];
    int weights[n + 1]; // keeps track of min weight required to reach that node
    bool visited[n + 1];
    for (i = 1; i <= n; i++)
    {
        weights[i] = INT_MAX;
        visited[i] = false;
    }
    parent[1] = -1;
    weights[1] = 0;
    for (i = 1; i <= n; i++)
    {
        int minVertex = findMinVertex(weights, visited, n);
        visited[minVertex] = true;
        for (j = 1; j <= n; j++)
        {
            if (edges[minVertex][j] != 0 && visited[j] == false)
            {
                if (edges[minVertex][j] < weights[j])
                {
                    weights[j] = edges[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }
    printf("MST is\n");
    int cost = 0;
    for (i = 2; i <=n; i++)
    {
        if (parent[i] < i)
        {
            cost += edges[parent[i]][i];
            printf("%d %d %d\n", parent[i], i, weights[i]);
        }
        else
        {
            cost += edges[i][parent[i]];
            printf("%d %d %d\n", i, parent[i], weights[i]);
        }
    }
    printf("Minimum sum of edges is %d\n", cost);
}
