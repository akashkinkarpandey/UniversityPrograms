#include<stdio.h>
int po(int a,int b)
{
    if(b==0)//base case
    return 1;
    return a*po(a,b-1);
}
int main()
{
    int a,b;
    printf("Enter 2 numbers for calculating a to the power b\n");
    scanf("%d %d",&a,&b);
    if(a==0 &&b==0)
    {
        printf("Indeterminate Form\n");
        return 0;
    }
    if(b<0)
    {
        printf("%d to the power %d is %lf\n",a,b,1.0/po(a,b*(-1)));
        return 0;
    }
printf("%d to the power %d is %d\n",a,b,po(a,b));
}