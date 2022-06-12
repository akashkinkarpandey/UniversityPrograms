#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
int g[101][101];
bool vis[100];
int n, e;
// dijkstra algorithm
//1-Based Indexing
// Enter number of nodes,edges
// 6 9
// Enter source,destination,weight
// 1 2 1
// Enter source,destination,weight
// 1 3 5
// Enter source,destination,weight
// 2 3 2
// Enter source,destination,weight
// 3 5 2
// Enter source,destination,weight
// 2 5 1
// Enter source,destination,weight
// 2 4 2
// Enter source,destination,weight
// 4 5 3
// Enter source,destination,weight
// 4 6 1
// Enter source,destination,weight
// 5 6 2
// Enter source
// 1
// Node 1 is at distance 0
// Node 2 is at distance 1
// Node 3 is at distance 3
// Node 4 is at distance 3
// Node 5 is at distance 2
// Node 6 is at distance 4
int findMinVertex(int dist[],bool visited[],int n)
{
    //we return vertex(node) with minimum distance from source node
    //please note->we dont return minimum distance
    int minVertex=-1;
    for(int node=1;node<=n;node++)
    {
        if(!visited[node] && (minVertex==-1 || dist[node]<dist[minVertex]))
            minVertex=node;
    }
    return minVertex;
}
int main()
{
    int i,j,adjNode,number_of_nodes;
    printf("Enter number of nodes,edges\n");
    scanf("%d %d", &n, &e);
    for (i = 0; i < e; i++)
    {
        printf("Enter source,destination,weight\n");
        int u, v,wt;
        scanf("%d %d %d", &u, &v,&wt);
        g[u][v] = wt;
    }
    int dist[n + 1];
    for (i = 1; i <= n; i++)
    {
        dist[i]=INT_MAX;
        vis[i]=false;
    }
    printf("Enter source\n");
    int source;
    scanf("%d",&source);
    dist[source]=0;
    for(number_of_nodes=1;number_of_nodes<=n;number_of_nodes++)
    {
        int minVertex = findMinVertex(dist, vis, n);
        vis[minVertex] = true;
        for (adjNode = 1; adjNode <= n; adjNode++)
        {
            if(g[minVertex][adjNode]!=0 && !vis[adjNode])
            {
                if(dist[minVertex]+g[minVertex][adjNode]<dist[adjNode])
                dist[adjNode]=dist[minVertex]+g[minVertex][adjNode];
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        printf("Node %d is at distance %d\n",i,dist[i]);
    }

}
