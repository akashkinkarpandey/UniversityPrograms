#include<stdio.h>
int main()
{
double sum=0;int n;scanf("%d",&n);
for(int i=1;i<=n;i++)
{
int t=i*2;
int a=(2*i)-1;
int b=(2*i)+1;
sum=sum+(1.0*t)/(a*b);
}
printf("Sum of series is %lf\n",sum);
}