
#include<stdio.h>
int main()
{   //INSERTION SORT
    int n;//declaration of variable that will hold size of array
    printf("Enter size of array\n");
    scanf("%d",&n);
    int a[n];//declaration of array
    printf("Enter array elements in ascending order\n");
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);//taking input of array elements
	for(int i=1;i<n;i++)
	{
		int current=a[i];
		int j=i-1;
		while(a[j]>current&& j>=0)
		{
        a[j+1]=a[j];j--;
		}
		a[j+1]=current;
	}
    printf("Array after sorting is\n");
	for(int i=0;i<n;i++)
		printf("%d\n",a[i]);//printing array elements
}