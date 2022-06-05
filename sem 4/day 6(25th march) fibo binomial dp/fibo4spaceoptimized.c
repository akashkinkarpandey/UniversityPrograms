#include<stdio.h>
//tabular(space optimized)
int main()
{
    int i,n;
    printf("Enter a number\n");
    scanf("%d",&n);
    int a=0,b=0,c=1;
    for(i=0;i<=n;i++)
    {
        printf("%d ",a);
        a=b+c;
        
    }
}