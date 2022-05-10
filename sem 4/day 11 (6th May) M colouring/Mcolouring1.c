#include <stdio.h>
#include <stdbool.h>
int n, e,c,m;
int mat[100][100];
int x[100];
//input
// Enter number of nodes,edges
// 4
// 4
// Enter source,destination
// 1 2
// Enter source,destination
// 2 3
// Enter source,destination
// 3 4
// Enter source,destination
// 4 1
// Enter number of colors
// 2
//output
// Solution set is
// 1 2 1 2
// Solution set is
// 2 1 2 1
// Number of solutions are 2
void nextValue(int kthNode)
{
    //x[] is global array that denotes:-
    //color of the kth node at kth index
    //1-based indexing of graph
    //if we cant color kth node we put x[k]=0
    //if we can color we put x[k]=color<=m
    while(1)
    {
        x[kthNode]=(x[kthNode]+1)%(m+1);
        if(x[kthNode]==0)//if number of colors are not enough to color this node
        return;
        int adjNode;
        for(adjNode=1;adjNode<=n;adjNode++)
        {
            if(mat[kthNode][adjNode]==1 && x[kthNode]==x[adjNode])//if adjacent nodes have same color
                break;
        }
        if(adjNode==(n+1))//end of loop reached,we can color kth node
        return ;
    }
}
void mColoring(int k)
{
    while(1)
    {
        nextValue(k);
        if(x[k]==0)
        return;
        if(k==n)//if we reach final node that means all nodes have been colored correctly
        {
            int j;
            printf("Solution set is\n");
            for(j=1;j<=n;j++)
            printf("%d ",x[j]);
            c++;
            printf("\n");
        }
        else 
        mColoring(k+1);//color the k+1 th node if kth node colored properly
    }
}
int main()
{
    printf("Enter number of nodes,edges\n");
    scanf("%d %d", &n, &e);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        printf("Enter source,destination\n");
        scanf("%d %d", &u, &v);
        mat[u][v] = 1;
        mat[v][u] = 1;
    }
    printf("Enter number of colors\n");
    scanf("%d",&m);
    mColoring(1);//start by coloring 1st node
    printf("Number of solutions are %d\n",c);
}