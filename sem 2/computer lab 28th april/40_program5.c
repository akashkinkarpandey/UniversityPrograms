#include <stdio.h>
int main() 
{
   int a,b,c;
	scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    int t,t1,max,min;
    t=(a>b)?a:b;
    max=(t>c)?t:c;
    t1=(a<b)?a:b;
    min=(t1<c)?t1:c;
    printf("MAX IS %d\n",max);
    printf("MIN IS %d\n",min);
}
