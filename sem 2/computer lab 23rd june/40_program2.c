#include<stdio.h>
int prime(int n)
{
    //we return 0 if not prime
    //else we return 1 if prime

//1,n
//extra 2 to n-1
if(n<=1)
return 0;
for(int i=2;i<n;i++)
if(n%i==0)
return 0;
return 1;
}
int main()
{
    int a,b;
    printf("Enter the lower limit\n");
    scanf("%d",&a);
    printf("Enter the upper limit\n");
    scanf("%d",&b);
    for(int i=a;i<=b;i++)
    {
        if(prime(i))
         printf("%d is prime \n",i);
    }
    return 0;
}