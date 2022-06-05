#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
//dfs using:-
// 1) stacks via Linked List
// 2) adjacency matrix (statically) for 1-indexed graphs
//this is part2 ,part 1 is in dfs4.c,both are correct
//there is slight change in dfs function from previous part

//input
//Enter number of nodes,edges
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
//output
// DFS is
// 1 8 12 9 11 10 7 2 6 3 5 4

//variables for graph declared here
int mat[101][101];//adjacency matrix
bool vis[101];//visited array
int n;
int e;
//stack functions
struct node
{
    int data;
    struct node *link;
};
struct node *top_element;
int c = 0;
int isEmpty()
{
    return top_element == NULL;
    //if empty returns true
}
void push(int val)
{
    c++;
    //inserting at head of stack
    struct node *newnode = (struct node *)(malloc(sizeof(struct node)));
    newnode->data = val;
    newnode->link = top_element;
    top_element = newnode;
}
void pop()
{
    if (isEmpty()) //zero elements in stack
    {
        return;
    }
    c--;
    //deleting top_element/head of stack
    struct node *ptr = top_element;
    top_element = top_element->link;
    free(ptr);
}
int top()
{
    return top_element->data;
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

//input
// Enter number of nodes,edges
// 6 5
// Enter source,destination
// 1 5
// Enter source,destination
// 5 6
// Enter source,destination
// 5 4
// Enter source,destination
// 4 3
// Enter source,destination
// 4 2

//output
// DFS is
// 1 5 6 4 3 2
