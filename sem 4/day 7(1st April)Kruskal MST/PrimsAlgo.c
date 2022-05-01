//Prim's Algo perfectly working
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
// Input
// Enter number of nodes,edges
// 5 7
// Enter source,destination,weight
// 0 1 4
// Enter source,destination,weight
// 0 2 8
// Enter source,destination,weight
// 1 3 6
// Enter source,destination,weight
// 1 2 2
// Enter source,destination,weight
// 2 3 3
// Enter source,destination,weight
// 2 4 9
// Enter source,destination,weight
// 3 4 5

//Output
// MST is
// 0 1 4
// 1 2 2
// 2 3 3
// 3 4 5
int findMinVertex(int weights[], bool visited[], int n)
{
    int minVertex = -1;
    int i;
    for (i = 0; i < n; i++)
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
    int edges[n][n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
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

    int parent[n];
    int weights[n];//keeps track of min weight required to reach that node
    bool visited[n];
    for (i = 0; i < n; i++)
    {
        weights[i] = INT_MAX;
        visited[i] = false;
    }
    parent[0] = -1;
    weights[0] = 0;
    for (i = 0; i < n; i++)
    {
        int minVertex = findMinVertex(weights, visited, n);
        visited[minVertex] = true;
        for (j = 0; j < n; j++)
        {
            if (edges[minVertex][j] != 0 && visited[j] == false)
            {
                if(edges[minVertex][j] < weights[j])
                {
                    weights[j] = edges[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }
    printf("MST is\n");
    for (i = 1; i < n; i++)
    {
        if (parent[i] < i)
        {
            printf("%d %d %d\n", parent[i], i, weights[i]);
        }
        else
        {
            printf("%d %d %d\n", i, parent[i], weights[i]);
        }
    }
}