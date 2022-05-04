#include<stdio.h>
int main()
{
int n;
scanf("%d",&n);
int s=0;
for(int i=1;i<=n;i++)
{
	if(i&1)
		s+=(i*i*i);
	else s-=(i*i);
}
printf("Sum is %d\n",s);

}