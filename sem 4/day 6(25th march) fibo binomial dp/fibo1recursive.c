#include<stdio.h>
//Program using recursion
int fibo(int n)
{
    if(n==1 || n==0)
    return n;
    return fibo(n-1)+fibo(n-2);
}
int main()
{
    int i,n;
    printf("Enter a number\n");
    scanf("%d",&n);
    printf("%d-th fibonacci number is %d\n",n,fibo(n));
    printf("Series is\n");
    for(i=0;i<=n;i++)
    printf("%d ",fibo(i));
}