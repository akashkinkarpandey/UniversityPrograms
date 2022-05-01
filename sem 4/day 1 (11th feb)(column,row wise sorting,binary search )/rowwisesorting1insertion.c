#include <stdio.h>
void insertion(int a[],int n)
{
    //sort in ascending order
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        while(j>=0)
        {
            if(a[j]>a[j+1])
            {
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
            j--;
            // else break;
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
        insertion(a[i],c);
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