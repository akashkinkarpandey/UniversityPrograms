#include <stdio.h>
int main() 
{
   //swapping with temporary variable
	int a,b;
	scanf("%d",&a);
    scanf("%d",&b);
    int t=a;
    a=b;
    b=t;
    printf("a is %d\n",a);
    printf("b is %d\n",b);
    //swapping without temporary variable
    int c,d;
    scanf("%d",&c);
    scanf("%d",&d);
    c=c^d;
    d=d^c;
    c=c^d;
    printf("c is %d\n",c);
    printf("d is %d\n",d);


}