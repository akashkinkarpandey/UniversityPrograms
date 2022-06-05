#include<stdio.h>
void callByValue(int a)
{
a=a+6;//no change occurs 
}
void callByReference(int *b)
{
*b=*b+6;//change occurs in a of main()
}
int main()
{
    printf("Enter 1 number\n");
    int a;
    scanf("%d",&a);
    printf("Before call by value, a is %d\n",a);
    callByValue(a);
    printf("After call by value, a is %d\n",a);
    printf("Before call by reference, a is %d\n",a);
    callByReference(&a);
    printf("After call by reference, a is %d\n",a);
}