#include <stdio.h>
int main()
{
int n;
printf("Enter size of array\n");
scanf("%d",&n);
int a[n];
printf("Enter array elements\n");
for(int i=0;i<n;i++)
scanf("%d",&a[i]);
int max=a[0];
for(int i=1;i<n;i++)
{
  if(a[i]>max)
    max=a[i];
}
int max2=a[0];
for(int i=1;i<n;i++)
{
  if(a[i]>max2 && a[i]<max)
    max2=a[i];
}
printf("Second largest element is %d\n",max2);
}