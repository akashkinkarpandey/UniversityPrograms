#include<stdio.h>
int hcf(int a,int b)
{
    if(b==0)
    return a;
    return hcf(b,a%b);
}
int main()
{
    printf("Enter 2 numbers\n");
    int a,b;
    scanf("%d %d",&a,&b);
    printf("HCF is %d\n",hcf(a,b));
}
