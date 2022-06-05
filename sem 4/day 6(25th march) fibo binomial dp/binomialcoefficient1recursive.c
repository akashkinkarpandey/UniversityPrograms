#include<stdio.h>
int bino(int n,int r)
{
    if(r==0)
    return 1;
    if(n==r)
    return 1;
    return bino(n-1,r)+bino(n-1,r-1);
}
int main()
{
    int n,r;
    printf("Enter n and r\n");
    scanf("%d %d",&n,&r);
    printf("%dC%d is %d\n",n,r,bino(n,r));
}