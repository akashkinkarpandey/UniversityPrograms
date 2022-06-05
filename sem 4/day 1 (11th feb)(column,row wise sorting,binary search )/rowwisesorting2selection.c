#include <stdio.h>
void selection(int a[],int n)
{
    //sort in ascending order
    for(int i=0;i<n-1;i++)
    {
        int mini=a[i],min_ind=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<mini)
            {
                mini=a[j];
                min_ind=j;
            }
        }
        int t=a[i];
        a[i]=a[min_ind];
        a[min_ind]=t;
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
        selection(a[i],c);
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