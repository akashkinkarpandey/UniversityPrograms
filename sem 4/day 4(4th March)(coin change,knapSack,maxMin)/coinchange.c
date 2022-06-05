#include <stdio.h>
void sort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]<a[j+1])
            {
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}
void find(int a[], int n, int target)
{
    sort(a,n);
    int taken = 0;
    int b[n];
    int c = 0, d = 0;
    for (int i = 0; i < n; i++)
    {
        if (taken + a[i] <= target)
        {
            taken = taken + a[i];
            c++;
            b[d++] = a[i];
        }
    }
    printf("Number of coins taken are %d\n", c);
    printf("Coins which were taken are\n");
    for (int i = 0; i < d; i++)
        printf("%d ", b[i]);
    printf("\n");
}
int main()
{
    int n, target;
    printf("Enter size\n");
    scanf("%d", &n);
    int a[n];
    printf("Enter target\n");
    scanf("%d", &target);
    printf("Enter array elements\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    find(a, n, target);
}