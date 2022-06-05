#include<stdio.h>
void bin(int a[],int l,int h,int search,int position[])
{
    if(l>h)
    {
        printf("%d not found\n",search);
        return;
    }
    int mid=l+(h-l)/2;
    if(a[mid]==search)
    {
        printf("Number found at index %d\n",position[mid]);
        return;
    }
    if(a[mid]>search)
    bin(a,l,mid-1,search,position);
    if(a[mid]<search)
    bin(a,mid+1,h,search,position);
}
void sort(int a[],int n,int position[])
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                int t1=position[j];
                position[j]=position[j+1];
                position[j+1]=t1;
            }
        }
    }
}
int main()
{
    int i,n,search;
    printf("Enter size of array,element to be searched\n");
    scanf("%d %d",&n,&search);
    int a[n];
    int position[n];
    printf("Enter array elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        position[i]=i;
    }
    sort(a,n,position);
    bin(a,0,n-1,search,position);
}