#include <stdio.h>
int main()
{
    int r, c;
    printf("Enter rows\n");
    scanf("%d", &r);
    printf("Enter columns\n");
    scanf("%d", &c);
    int a[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Enter element\n");
            scanf("%d", &a[i][j]);
        }
    }
    // insertion sort
    for (int i = 0; i < c; i++)
    {
        for (int j = 1; j < r ; j++)
        {
            int k=j-1;
            while(k>=0)
            {
                if(a[k][i]>a[k+1][i])
                {
                    int t=a[k][i];
                    a[k][i]=a[k+1][i];
                    a[k+1][i]=t;
                }
                k--;
            }
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}