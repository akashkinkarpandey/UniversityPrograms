#include<stdio.h>
void DecToBin(int num)
{
    int a[33];
    int c = 0;
    while (num) 
    {
        a[c++] = num % 2;
        num = num / 2;
        
    }
    for (int i = c - 1; i>= 0; i--)
        printf("%d",a[i]);
        printf("\n");
}
int main()
{
    int n;
    printf("Enter Decimal Number\n");
    scanf("%d",&n);
    printf("Binary Number is\n");
    DecToBin(n);
}