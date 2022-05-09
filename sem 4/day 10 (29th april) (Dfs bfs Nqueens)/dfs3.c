#include<stdio.h>
#include<stdbool.h>
//dfs using:-
// 1) stacks via arrays
// 2) adjacency matrix (statically) for 1-indexed graphs

// part 2(there is slight variation in dfs function)
//both part 1(in dfs2) and part 2 are correct

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
// 1 8 12 9 11 10 7 2 6 3 5 4

//variables for graph declared here
int mat[101][101];//adjacency matrix
bool vis[101];//visited array
int n;
int e;

//stack implementation
int a[101];//this is the stack
int i = -1;
void push(int x)
{
    if (i == 100) //max size reached
    {
        return;
    }
    a[++i] = x; //insert
}
int isEmpty()
{
    return (i == -1); //if no element has been inserted yet
}
int size()
{
    return (i + 1);
}
void pop()
{
    if (isEmpty()) //underflow checking
    {
        return;
    }
    i--; //reducing index
}
int top()
{
    return a[i];
}
//dfs function
void dfs(int v)
{
    push(v);//pushing source vertex in stack
    vis[v]=1;
    while(!isEmpty())
    {
        int take=top();
        pop();
        printf("%d ",take);
        for(int adjacentVertex=1;adjacentVertex<=n;adjacentVertex++)
        {
            //push adjacent vertex if it is not visited
            if(mat[take][adjacentVertex]==1 && !vis[adjacentVertex])
            {
                push(adjacentVertex);
                vis[adjacentVertex]=1;
            }
        }
    }
}
int main()
{
    printf("Enter number of nodes,edges\n");
    scanf("%d",&n);
    scanf("%d",&e);
    for(int j=0;j<e;j++)
    {
        int u,v,wt;
        printf("Enter source,destination\n");
        scanf("%d %d",&u,&v);
        mat[u][v]=1;
        mat[v][u]=1;
    }
    printf("DFS is\n");
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        dfs(i);
    }
    printf("\n");
}
