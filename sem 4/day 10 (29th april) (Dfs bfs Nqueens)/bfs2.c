#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// bfs using:-
// 1)queue using Linked List
// 2)adjacency matrix
// 1-Based indexing of graphs
// input
//  Enter number of nodes,edges
//  7 8
//  Enter source,destination
//  1 2
//  Enter source,destination
//  1 3
//  Enter source,destination
//  1 4
//  Enter source,destination
//  2 5
//  Enter source,destination
//  2 6
//  Enter source,destination
//  3 7
//  Enter source,destination
//  3 8
//  Enter source,destination
//  4 8

// output
//  BFS is
//  1 2 3 4 5 6 7 8
int mat[101][101];
bool vis[101];
int n, e;
struct node
{
    int data;
    struct node *link;
};
struct node *front;
struct node *rear;
int isEmpty()
{
    return (front == NULL && rear == NULL);
    // returns 1 if empty
}
void push(int val)
{
    struct node *newnode = (struct node *)(malloc(sizeof(struct node)));
    newnode->data = val;
    newnode->link = NULL;
    if (isEmpty()) // when queue is empty
    {
        front = rear = newnode;
        return;
    }
    // insert at rear
    rear->link = newnode; // insert1 at end
    rear = newnode;
}
void pop()
{
    // delete head or front
    if (front->link == NULL) // if only one node was there
    {
        front = rear = NULL; // make the list empty
        return;
    }
    struct node *tobedeleted = front;
    front = front->link;
    free(tobedeleted);
}
int top()
{
    return front->data;
}
void bfs(int vertex)
{
    push(vertex);
    vis[vertex] = 1;
    while (!isEmpty())
    {
        int node = top();
        pop();
        printf("%d ", node);
        for (int adjacentVertex = 1; adjacentVertex <= n; adjacentVertex++)
        {
            if (mat[node][adjacentVertex] == 1 && !vis[adjacentVertex])
            {
                push(adjacentVertex);
                vis[adjacentVertex] = 1;
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
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            bfs(i);
    }
    printf("\n");
}
