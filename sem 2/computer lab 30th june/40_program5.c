#include<stdio.h>
int sum(int n)
{
	if(n==0)
		return 0;
	return sum(n/10)+(n%10);
}
int main()
{
    int n;
    printf("Enter  a number\n");
    scanf("%d",&n);
    printf("Sum of digits is %d\n",sum((n>=0)?n:(-n)));
}