#include <stdio.h>
int main( ) 
{
int n,fl=0;
printf("Enter size of array\n");
scanf("%d",&n);//size of array
int a[n];
printf("Enter array elements\n");
for(int i=0;i<n;i++)
scanf("%d",&a[i]);
int max=a[0],min=a[0];
for(int i=1;i<n;i++)
{
  if(a[i]>max)
    {max=a[i];}
  if(a[i]<min)
    {min=a[i];}
}
for(int i=0;i<n;i++)
{
  if(a[i]==max)
  {a[i]=min;continue;}
  if(a[i]==min)
  {a[i]=max;}
}
printf("Max element is %d\n",max);  
printf("Min element is %d\n",min);
printf("Array elements after swapping max and min elements are\n");
for(int i=0;i<n;i++)
printf("%d\n",a[i]);
return 0;
}