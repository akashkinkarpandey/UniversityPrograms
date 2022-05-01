#include<stdio.h>
#include<limits.h>
#include<math.h>
//using dp
//travelling salesman
//time complexity->O(N)*O(2^N)
//space complexity->O(N)*O(2^N)
int dist[101][101];
int dp[101][101];int n;
int find(int citiesVisitedTillNow,int city_from,int allNodesVisited,int n)
{
    if(allNodesVisited==citiesVisitedTillNow)
    {
        return dist[city_from][0];
    }
    if(dp[citiesVisitedTillNow][city_from]!=-1)
        return dp[citiesVisitedTillNow][city_from];

    int city_to;
    int min_cost=INT_MAX;
    for(city_to=0;city_to<n;city_to++)
    {
        if((citiesVisitedTillNow&(1<<city_to))==0)
        {
            int newCitiesVisitedTillNow=citiesVisitedTillNow|(1<<city_to);
            int answer=dist[city_from][city_to]+find(newCitiesVisitedTillNow,city_to,allNodesVisited,n);
            min_cost=fmin(min_cost,answer);
        }
    }
    return dp[citiesVisitedTillNow][city_from]=min_cost;
}
int main()
{
    int e;
    int i,j;
    printf("Enter number of nodes,edges\n");
    scanf("%d %d",&n,&e);
    for(i=0;i<e;i++)
    {
        int u,v,wt;
        printf("Enter source,weight,destination\n");
        scanf("%d %d %d",&u,&v,&wt);
        dist[u][v]=wt;
        dist[v][u]=wt;
    }
    for(i=0;i<(1<<n);++i)
    {
        for(j=0;j<n;j++)
        {
            dp[i][j]=-1;
        }
    }
    int allNodesVisited=(1<<n)-1;
    int t=find(1,0,allNodesVisited,n);
    printf("Minimum cost is %d\n",t);
}

//another input
// Enter number of nodes,edges
// 4
// 12
// Enter source,weight,destination
// 0 1 20
// Enter source,weight,destination
// 0 2 42
// Enter source,weight,destination
// 0 3 25
// Enter source,weight,destination
// 1 0 20
// Enter source,weight,destination
// 1 2 30
// Enter source,weight,destination
// 1 3 34
// Enter source,weight,destination
// 2 0 42
// Enter source,weight,destination
// 2 1 30
// Enter source,weight,destination
// 2 3 10
// Enter source,weight,destination
// 3 0 25
// Enter source,weight,destination
// 3 1 34
// Enter source,weight,destination
// 3 2 10
// output
// Minimum cost is 85