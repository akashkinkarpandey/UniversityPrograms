#include<stdio.h>
#include<stdbool.h>
//dfs using:-
// 1) recursion
// 2) adjacency matrix (statically) for graphs

//1-Based indexing of graphs

//input
// Enter number of nodes,edges
// 13
// 11
// Enter source,destination
// 1 2
// Enter source,destination
// 1 7
// Enter source,destination
// 1 8
// Enter source,destination
// 2 3
// Enter source,destination
// 2 6
// Enter source,destination
// 3 4
// Enter source,destination
// 3 5
// Enter source,destination
// 8 9
// Enter source,destination
// 8 12
// Enter source,destination
// 9 10
// Enter source,destination
// 9 11

// output
// DFS is
// 1 2 3 4 5 6 7 8 9 10 11 12 13
int a[101][101];
bool vis[101];
int n,e;
void dfs(int vertex)
{
    if(vis[vertex])
    return;
    printf("%d ",vertex);
    vis[vertex]=1;
    for(int adjacentVertex=1;adjacentVertex<=n;adjacentVertex++)
    {
        if(a[vertex][adjacentVertex]==1 && !vis[adjacentVertex])
            dfs(adjacentVertex);
    }
}
int main()
{
    printf("Enter number of nodes,edges\n");
    scanf("%d",&n);
    scanf("%d",&e);
    for(int i=0;i<e;i++)
    {
        int u,v,wt;
        printf("Enter source,destination\n");
        scanf("%d %d",&u,&v);
        a[u][v]=1;
        a[v][u]=1;
    }
    printf("DFS is\n");
    for(int i=1;i<=e;i++)
    {
        if(!vis[i])
        dfs(i);
    }
    printf("\n");
}

//input
// Enter number of nodes,edges
// 6
// 5
// Enter source,destination
// 1 5
// Enter source,destination
// 5 6
// Enter source,destination
// 5 4
// Enter source,destination
// 4 2
// Enter source,destination
// 4 3
//output
// 1 5 4 2 3 6