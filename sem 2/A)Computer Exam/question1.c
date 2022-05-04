#include<stdio.h>
int hcf(int a,int b)
{
if(b==0)
return a;
return hcf(b,a%b);
}
int main()
{
int a;int b;
printf("Enter two numbers\n");
scanf("%d %d",&a,&b);
printf("HCF of %d and %d is %d\n",a,b,hcf(a,b));
}
