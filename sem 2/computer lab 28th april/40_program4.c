#include <stdio.h>
#include <stdlib.h>
int main() 
{
	int a=0,b=0;
	scanf("%d",&a);
	scanf("%d",&b);
	if(abs(a)>abs(b))
		printf("a has greater magnitude");
	else printf("b has greater magnitude");

}