#include <stdio.h>
// Kruskal's Algo perfectly working
// 1-Based Indexing
struct Edge
{
    int source;
    int destination;
    int weight;
};
//input
// Enter number of nodes,edges
// 8
// 11
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

// output
// MST is
// 2 5 5
// 7 6 10
// 7 5 15
// 4 5 20
// 1 3 25
// 4 8 30
// 3 5 40
// Minimum Sum of all edges is 145
void sort(struct Edge g[], int e)
{
    int i, j;
    for (i = 0; i < e - 1; i++)
    {
        for (j = 0; j < e - i - 1; j++)
        {
            if (g[j].weight > g[j + 1].weight)
            {
                int t = g[j].weight;
                g[j].weight = g[j + 1].weight;
                g[j + 1].weight = t;
                int t1 = g[j].source;
                g[j].source = g[j + 1].source;
                g[j + 1].source = t1;
                int t2 = g[j].destination;
                g[j].destination = g[j + 1].destination;
                g[j + 1].destination = t2;
            }
        }
    }
}
int find(int v, int parent[])
{
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v], parent);
}
void kruskals(struct Edge g[], int n, int e)
{
    int i;
    // sorting in increasing order of weight
    sort(g, e);
    // any tree has n-1 edges for n nodes
    struct Edge final[n - 1]; // output array
    int parent[n+1];
    for (i = 1; i <=n; i++)
        parent[i] = i;
    int count = 0;
    i = 0;
    while (count < n - 1)
    {
        struct Edge a = g[i];
        int sourceParent = find(g[i].source, parent);
        int destParent = find(g[i].destination, parent);
        if (sourceParent != destParent)
        {
            final[count] = a;
            count++;
            parent[destParent] = sourceParent;
        }
        i++;
    }
    int cost = 0;
    printf("MST is\n");
    for (i = 0; i < n - 1; i++)
    {
        cost += final[i].weight;
        printf("%d %d %d\n", final[i].source, final[i].destination, final[i].weight);
    }
    printf("Minimum Sum of all edges is %d\n", cost);
}
int main()
{
    int n, i, e;
    printf("Enter number of nodes,edges\n");
    scanf("%d %d", &n, &e);
    struct Edge g[e];
    for (i = 0; i < e; i++)
    {
        int s, d, ee;
        printf("Enter source,destination,weight\n");
        scanf("%d %d %d", &s, &d, &ee);
        g[i].source = s;
        g[i].destination = d;
        g[i].weight = ee;
    }
    kruskals(g, n, e);
}