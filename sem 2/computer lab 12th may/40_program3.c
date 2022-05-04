#include<stdio.h>
int main()
{
for(int i=1;i<=1000;i++)
{ 
	int s=0;
for(int j=1;j<i;j++)
{
    if(i%j==0)
     s=s+j;
}
if(s==i) printf("%d is perfect\n",i);
}


}