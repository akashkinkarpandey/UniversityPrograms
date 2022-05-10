#include <stdio.h>
#include <stdbool.h>
//TC->O(N^M)
//SC->O(N^2)
int a[100][100];
int color[100];
//color array denotes node i(index i) is painted with which color 
// input
// Enter number of nodes,edges
// 4 5
// Enter source,destination
// 0 1
// Enter source,destination
// 0 2
// Enter source,destination
// 0 3
// Enter source,destination
// 1 2
// Enter source,destination
// 1 3
// Enter number of colors
// 3
// output
// Yes its possible to color

//another input
// Enter number of nodes,edges
// 4 5
// Enter source,destination
// 0 1
// Enter source,destination
// 0 2
// Enter source,destination
// 0 3
// Enter source,destination
// 2 1
// Enter source,destination
// 1 3
// Enter number of colors
// 2
//output
// No its not possible to color
bool isPossibletoColorNodeWithCol(int node, int col, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        //checking if adjacent nodes of node are painted with same color col or not
        if (a[node][i] == 1 && color[i] == col)
            return false;
    }
    return true;
}
bool solve(int node, int n, int m)
{
    if (node == n)
    {
        return true;
    }
    int col;
    for (col = 1; col <= m; col++)
    {
        if (isPossibletoColorNodeWithCol(node, col, n))
        {
            color[node] = col;
            if (solve(node + 1, n, m))
                return true;
            color[node] = 0;
        }
    }
    return false;
}
int main()
{
    int n, e, m, i;
    printf("Enter number of nodes,edges\n");
    scanf("%d %d", &n, &e);
    for (i = 0; i < e; i++)
    {
        int u, v;
        printf("Enter source,destination\n");
        scanf("%d %d", &u, &v);
        a[u][v] = 1;
        a[v][u] = 1;
    }
    printf("Enter number of colors\n");
    scanf("%d", &m);
    if (solve(0, n, m))
    {
        printf("Yes its possible to color\n");
    }
    else
    {
        printf("No its not possible to color\n");
    }
}
