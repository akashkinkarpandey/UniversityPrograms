#include<stdio.h>
int fact(int n)
{   //fatorial
    if(n==0 || n==1)
    return 1;//base condition
    return n*fact(n-1);
}
int main()
{
    int n;
    printf("Enter a number\n");
    scanf("%d",&n);
    if(n<0)//negative number checking
    {
        printf("You cant find factorial of negative number\n");
    }
    else
    {
    printf("Factorial of %d is %d\n",n,fact(n));
    }
}