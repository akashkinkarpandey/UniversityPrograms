#include<stdio.h>
int fact(int n)
{//factorial calculation
if(n==0 ||n==1)
    return 1;
return n*fact(n-1);
}
double func1(int a,int b)
{//nCr calculation
return (1.0*fact(a))/((fact(b))*fact(a-b));  
}
double func2(int a,int b)
{//nPr calculation
return (1.0*fact(a))/(fact(a-b));  
}
int main()
{
    int n;
    printf("Enter 1 for nCr or 2 for nPr\n");
    scanf("%d",&n);
    int a,b;
    printf("Enter n \n");
    scanf("%d",&a);
    printf("Enter r \n");
    scanf("%d",&b);
    if(a<b)
    {
        printf("Values of n and r not entered correctly\n");
        return 0;
    }
    switch(n)
    {
        case 1:printf(" nCr is %0.2lf\n",func1(a,b));
        break;
        case 2:printf(" nPr is %0.2lf\n",func2(a,b));
        break;
        deafult:printf("Wrong choice\n");break;
    }
return 0;
}