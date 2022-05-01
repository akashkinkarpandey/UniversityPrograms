#include<stdio.h>
//Memoization
int dp[101][101];
int bino(int n,int r)
{
    if(n==r)
    {
        dp[n][r]=1;
        return 1;
    }
    if(r==0)
    {
        dp[n][r]=1;
        return 1;
    }
    if(dp[n][r]==0)
    return 0;
    if(dp[n][r]!=-1)
        return dp[n][r];
    dp[n][r]=bino(n-1,r)+bino(n-1,r-1);
    return dp[n][r];
}
int main()
{
    int i,j,n,r;
    printf("Enter n and r\n");
    scanf("%d %d",&n,&r);
    if(r>n || r<0 || n<0)
    {
        printf("Wrong Input\n");
        return 0;
    }
    for(i=1;i<=100;i++)
    {
        for(j=1;j<=100;j++)
        {
            dp[i][j]=-1;
        }
    }
    bino(n,r);
    printf("%dC%d is %d\n",n,r,dp[n][r]);
}