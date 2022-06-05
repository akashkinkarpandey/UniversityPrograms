#include<stdio.h>
int main()
{   //BINARY SEARCH
    int num;//declaration of variable that is to be found
    printf("Enter number to be found in array\n");
    scanf("%d",&num);
    int n;//declaration of variable that will hold size of array
    printf("Enter size of array\n");
    scanf("%d",&n);
    int flag=0;
    int a[n];//declaration of array
    printf("Enter array elements\n");
	int low=0,high=n-1;//initializing the upper and lower limits
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);//taking input of array elements
	while(low<=high)
	{
	int mid=low+(high-low)/2;//finding the middle element
	if(num>a[mid])
	low=mid+1;//changing the lower limit
	else if(num<a[mid])
	high=mid-1;//changing the upper limit
	else if(num==a[mid])
	{
		flag=1;
		printf("Number found at position %d\n",(mid+1));break;//breaking since number is found
	}
	}
	if(flag==0)//printing number is not found
	printf("Number not found\n");
}