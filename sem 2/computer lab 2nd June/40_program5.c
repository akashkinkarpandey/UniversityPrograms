#include <stdio.h>
int main()
{//bubble sort
  int n;
   printf("Enter size of array\n");
scanf("%d",&n);
int a[n];
printf("Enter array elements\n");
for(int i=0;i<n;i++)
scanf("%d",&a[i]);
  for(int i=0;i<n-1;i++)
  {
    for(int j=0;j<n-i-1;j++)
    {
      if(a[j]>a[j+1])
      {
        int t=a[j];
        a[j]=a[j+1];
        a[j+1]=t;
      }
    }
  }
  for(int i=0;i<n;i++)
    printf("%d\n",a[i]);
}