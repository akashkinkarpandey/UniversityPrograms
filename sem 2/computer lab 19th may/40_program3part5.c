#include<stdio.h>
int main()
{
int n;
scanf("%d",&n);
if(n%2==0)
{
    printf("Not possible with even number\n");return 0;
}
for(int i=1;i<=(n/2);i++)
{
for(int j=1;j<=i;j++)
printf("*");
printf("\n");
}
for(int i=n/2 +1;i>=1;i--)
{
for(int j=1;j<=i;j++)
printf("*");
printf("\n");
}
}