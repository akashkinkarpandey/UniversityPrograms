#include<stdio.h>
int main()
{
for(int i=100;i<=1000;i++)
{
int n=i;int s=0;
while(n>0)
{
    int d=n%10;
    s=s+(d*d*d);
    n=n/10;
}
if(s==i)
printf("%d is Armstrong number\n",i);
}


}