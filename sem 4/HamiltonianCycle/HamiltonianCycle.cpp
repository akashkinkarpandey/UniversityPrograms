#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
int g[101][101];
int n, e;
int x[100];
// Hamiltonian Cycle Program
// Inpu
//  Enter number of nodes,edges
//  5 8
//  Enter source,destination
//  1 2
//  Enter source,destination
//  1 5
//  Enter source,destination
//  2 5
//  Enter source,destination
//  2 4
//  Enter source,destination
//  4 5
//  Enter source,destination
//  4 3
//  Enter source,destination
//  1 3
//  Enter source,destination
//  2 3
// output
// Hamiltonian Cycles are
//  1 2 3 4 5
//  1 2 5 4 3
//  1 3 2 4 5
//  1 3 4 2 5
//  1 3 4 5 2
//  1 5 2 4 3
//  1 5 4 2 3
//  1 5 4 3 2
void nextValue(int k)
{
    while (1)
    {
        x[k] = (x[k] + 1) % (n + 1);
        if (x[k] == 0 || (k == 1 && x[k] == 1)) // k=1 and x[k]=1 so that we dont get same cycles
            return;
        // if we are trying to find node for kth position
        // it means k-1 positions already have nodes
        if (g[x[k]][x[k - 1]] == 1) // nodes at kth position and k-1 th have an edge
        {
            int j;
            for (j = 1; j <= k - 1; j++)
            {
                // check if node at kth position has already been included or not
                if (x[j] == x[k])
                    break;
            }
            if (j == k) // means node at kth position has not been included previously at previous k-1 positions
            {
                // return if position k is not last position where node has to be placed
                // return if k is last position and node at last position has path with node at first position
                if (k < n || (k == n && g[x[k]][x[1]] == 1))
                    return;
            }
        }
    }
}
void HamiltonianCycle(int k)
{
    // x[k] denotes at kth position which node was included for hamiltonian cycle
    while (1)
    {
        nextValue(k);
        if (x[k] == 0)
            return;
        if (k == n)
        {
            int i;
            for (i = 1; i <= n; i++)
                printf("%d ", x[i]);
            printf("\n");
        }
        else
        {
            HamiltonianCycle(k + 1);
        }
    }
}
int main()
{
    int i, j;
    printf("Enter number of nodes,edges\n");
    scanf("%d %d", &n, &e);
    for (i = 0; i < e; i++)
    {
        printf("Enter source,destination\n");
        int u, v;
        scanf("%d %d", &u, &v);
        g[u][v] = 1;
        g[v][u] = 1;
    }
    for (int i = 1; i <= n; i++)
        x[i] = 0;
    printf("Hamiltonian Cycles are\n");
    HamiltonianCycle(1);
}

// input
//  Enter number of nodes,edges
//  7
//  9
//  Enter source,destination
//  1 2
//  Enter source,destination
//  2 3
//  Enter source,destination
//  3 6
//  Enter source,destination
//  6 7
//  Enter source,destination
//  7 5
//  Enter source,destination
//  5 4
//  Enter source,destination
//  4 1
//  Enter source,destination
//  4 3
//  Enter source,destination
//  5 6

// output
//  Hamiltonian Cycles are
//  1 2 3 6 7 5 4
//  1 4 5 7 6 3 2
