#include <stdio.h>
#include <stdbool.h>
//bfs using:-
//1)queue using arrays
//2)adjacency matrix

//1-Based indexing of graphs

//input
// Enter number of nodes,edges
// 7 8
// Enter source,destination
// 1 2
// Enter source,destination
// 1 3
// Enter source,destination
// 1 4
// Enter source,destination
// 2 5
// Enter source,destination
// 2 6
// Enter source,destination
// 3 7
// Enter source,destination
// 3 8
// Enter source,destination
// 4 8

//output
// BFS is
// 1 2 3 4 5 6 7 8
int mat[101][101];
bool vis[101];
int n, e;

int a[100];
int c = 0;
int front = -1;
int rear = -1;
int size;
//Linear Queues using array
int isEmpty()
{
    return (front ==-1 && rear==-1);
    //returns 1 if queue is empty
}
void pop()
{
    //dequeue operation(deletion)
    if (isEmpty())//when queue is empty
    {
        front = rear = -1;
        return;
    }
    else if(front>=rear)//when the only element was deleted
    {
        front=rear=-1;
    }
    else
    {
        front++;
    }
    
}
//we insert only when front is -1 and rear is -1
//or we insert when last element of queue was deleted 
void push(int x)
{
    //enqueue operation(insertion)
    if(isEmpty())
    {
        front=rear=0;
        a[rear]=x;
    }
    else
    {
        a[++rear]=x;
    }
}
int top()
{
    //beginning element of queue
    return a[front];
}
void bfs(int vertex)
{
    push(vertex);
    vis[vertex]=1;
    while(!isEmpty())
    {
        int node=top();
        pop();
        printf("%d ",node);
        for(int adjacentVertex=1;adjacentVertex<=n;adjacentVertex++)
        {
            if(mat[node][adjacentVertex]==1 && !vis[adjacentVertex])
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
    scanf("%d", &n);
    scanf("%d", &e);
    for (int i = 0; i < e; i++)
    {
        int u, v, wt;
        printf("Enter source,destination\n");
        scanf("%d %d", &u, &v);
        mat[u][v] = 1;
        mat[v][u] = 1;
    }
    printf("BFS is\n");
    for (int i = 1; i <= e; i++)
    {
        if (!vis[i])
            bfs(i);
    }
    printf("\n");
}
