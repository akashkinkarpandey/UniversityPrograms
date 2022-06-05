#include<stdio.h>
int main()
{
int n;int c=0;
scanf("%d",&n);
for(int i=1;i<=n;i++)
{
for(int j=1;j<=i;j++)
printf("%d ",++c);
printf("\n");
}
}