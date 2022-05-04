#include <stdio.h>
int main( ) 
{
int num;
printf("Enter number to be searched\n");
scanf("%d",&num);//enter number to be checked present or not
int n,fl=0;
printf("Enter size of array\n");
scanf("%d",&n);//size of array
int a[n];
printf("Enter array elements\n");
for(int i=0;i<n;i++)
scanf("%d",&a[i]);
for(int i=0;i<n;i++)
{
  if(a[i]==num)
    {
      printf("Number found at %d position in array\n",(i+1));
      fl=1;
      break;
    }
}
if(fl==0)
 printf("Number not found position in array");   
return 0;
}