#include <stdio.h>
void bubble(int a[],int n)
{
    //sort in ascending order
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
             if(a[j]>a[j+1])
            {
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}
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
        bubble(a[i],c);
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