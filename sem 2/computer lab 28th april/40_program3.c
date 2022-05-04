#include <stdio.h>
int main() 
{
	int a=0;
	scanf("%d",&a);
	int d=a%10;
    int e=(a%100)/10;
    printf("Digit in units place %d\n",d);
    printf("Digit in tens place %d\n",e);
      


}