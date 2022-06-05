#include <stdio.h>
int main( ) 
{
int n;
printf("Enter size of array\n");
int positive=0,negative=0,zero=0;
scanf("%d",&n);//input of size
int a[n];
printf("Enter array elements\n");
for(int i=0;i<n;i++)
	{
    scanf("%d",&a[i]);//array input
    if(a[i]>0)
      positive++;
    else if(a[i]<0)
      negative++;
    else if(a[i]==0)
      zero++;
  }
  printf("Number of positives are %d\n",positive);
  printf("Number of negatives are %d\n",negative);
  printf("Number of zeroes are %d\n",zero);
return 0;
}