#include<stdio.h>
int main()
{
int n;
scanf("%d",&n);
int t=n,s=0;
while(n>0)
{
	int d=n%10;
	s=s+(d*d*d);
	n=n/10;
}
if(s==t)
printf("Number is armstrong");
else 
printf("Number is not armstrong");


}