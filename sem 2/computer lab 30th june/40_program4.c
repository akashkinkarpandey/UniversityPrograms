#include<stdio.h>
int count(int x)//definition
{
	if(x==0)
		return 0;
	return count(x/10)+1;
}
int main()
{
    int n;
    int count(int);//declarartion
    printf("Enter  a number\n");
    scanf("%d",&n);
    printf("Number of digits is %d\n",count(n));
}