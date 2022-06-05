#include<stdio.h>
int fact(int n)
{
if(n==0 ||n==1)//base case
    return 1;
return n*fact(n-1);
}
int main()
{
    int n;
    printf("Enter the limit\n");
    scanf("%d",&n);//taking input
    double sum=0.0;
    for(int i=1;i<=n;i++)
    {
     sum=sum+((1.0)*(2*i-1)*(i+2)/fact(i));
    }
    printf("Sum is %0.2lf \n",sum);
    return 0;
}