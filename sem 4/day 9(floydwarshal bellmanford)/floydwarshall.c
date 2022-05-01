#include <stdio.h>
#include <limits.h>
//floyd warshall
//no negative edge should be included
//input:-
// Enter number of nodes,edges
// 4 7
// Enter source,destination,edge
// 1 2 3
// Enter source,destination,edge
// 1 4 7
// Enter source,destination,edge
// 2 3 2
// Enter source,destination,edge
// 2 1 8
// Enter source,destination,edge
// 3 4 1
// Enter source,destination,edge
// 3 1 5
// Enter source,destination,edge
// 4 1 2

//output:-
// Output Matrix is
// 0 3 5 6
// 5 0 2 3
// 3 6 0 1
// 2 5 7 0
long long min(long long a, long long b)
{
    if (a > b)
        return b;
    return a;
}
int main()
{
    int i, j, n, e, k;
    printf("Enter number of nodes,edges\n");
    scanf("%d %d", &n, &e);
    long long g[n + 1][n + 1];
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            g[i][j] = INT_MAX;
            if (i == j)
                g[i][j] = 0;
        }
    }
    for (i = 0; i < e; i++)
    {
        int u, v, wt;
        printf("Enter source,destination,edge\n");
        scanf("%d %d %d", &u, &v, &wt);
        g[u][v] = wt;
    }
    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (i == j)
                    continue;
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                // if (g[i][k] != INT_MAX)
                // {
                //     if (g[k][j] != INT_MAX)
                //     {
                //         g[i][j] = min(g[i][j], (g[i][k] + g[k][j]));
                //     }
                // }
            }
        }
    }
    printf("Output Matrix is\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%li ", g[i][j]);
        }
        printf("\n");
    }
}