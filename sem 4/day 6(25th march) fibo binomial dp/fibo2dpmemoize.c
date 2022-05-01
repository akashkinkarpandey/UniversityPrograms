#include<stdio.h>
//memoization
int fibo(int n,int dp[])
{
    if(n==1 || n==0)
    return n;
    if(dp[n]!=-1)
    return dp[n];
    dp[n]= fibo(n-1,dp)+fibo(n-2,dp);
    return dp[n];
}
int main()
{
    int i,n;
    printf("Enter a number\n");
    scanf("%d",&n);
    if(n==0)
    {
    printf("0-th fibonacci number is %d\n",n);
    printf("Series is\n");
    printf("0\n");
    return 0;
    }
    int dp[n];
    for(i=2;i<=n;i++)
    dp[i]=-1;
    dp[0]=0;dp[1]=1;
    fibo(n,dp);
    printf("%d-th fibonacci number is %d\n",n,dp[n]);
    printf("Series is\n");
    for(i=0;i<=n;i++)
    printf("%d ",dp[i]);
    printf("\n");
}