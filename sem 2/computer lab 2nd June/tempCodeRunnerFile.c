#include <stdio.h>
int main()
{
    //selection sort
  int n;
scanf("%d",&n);
int a[n];
for(int i=0;i<n;i++)
scanf("%d",&a[i]);
  for(int i=0;i<n-1;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      if(a[j]<a[i])
      {
        int t=a[j];
        a[j]=a[i];
        a[i]=t;
      }
    }
  }
  for(int i=0;i<n;i++)
    printf("%d\n",a[i]);
}