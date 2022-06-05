#include<stdio.h>
int main()
{
printf("Enter 2 numbers\n");       
int a,b;
scanf("%d %d",&a,&b);    
printf("Enter choice\n");
printf("Press 1 for sum\n");
printf("Press 2 for difference \n");
printf("Press 3 for product\n");
printf("Press 4 for quotient\n");
int n;scanf("%d",&n);
switch(n)
{
	case 1:printf("Sum is %d\n",(a+b));break;
	case 2:printf("Difference is %d\n",(a-b));break;
	case 3:printf("Product is %d\n",(a*b));break;
	case 4:printf("Quotient is %d\n",(a/b));break;	
    default:printf("Wrong Number entered\n");break;

}
}