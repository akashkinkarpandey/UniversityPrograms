#include<stdio.h>
int poww(int a,int b)
{
    if(b==0)
        return 1;
    return a*poww(a,b-1);
}
int BintoDec(int n)
{
    int c=0,sum=0;
    while(n>0)
    {
    int d=n%10;
    if(d!=0 && d!=1)
    return -1;
    sum+=(d*(poww(2,c++)));
    n=n/10;
    }
    return sum;
}
int main()
{
    int n;
    printf("Enter Binary Number\n");
    scanf("%d",&n);
    int t=BintoDec(n);
    if(t!=-1)
    printf("Decimal Number is %d\n",t);
    else printf("Wrong Input\n");
}