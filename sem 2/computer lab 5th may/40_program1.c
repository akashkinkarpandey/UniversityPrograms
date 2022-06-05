#include<stdio.h>
int main()
{
int a,d,n;
scanf("%d",&a);
scanf("%d",&d);
scanf("%d",&n);
for(int i=1;i<=n;i++)
{
	printf("%d\n",a);
	a=a+d;
}

}