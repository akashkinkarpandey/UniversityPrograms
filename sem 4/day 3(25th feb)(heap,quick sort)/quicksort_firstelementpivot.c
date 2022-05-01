#include<stdio.h>
int partition(int a[],int l,int h)
{
    int pivot=a[l];
    int c=0;
    for(int i=l+1;i<=h;i++)
        if(a[i]<=pivot)
            c++;
    int pindex=l+c;
    int t=a[l];
    a[l]=a[pindex];
    a[pindex]=t;
    int i=l,j=h;
    while(i<pindex && j>pindex)
    {
        while(a[i]<=a[pindex])
        i++;
        while(a[j]>a[pindex])
        j--;
        if(i<pindex && j>pindex)
        {
            int t=a[i];
            a[i]=a[j];
            a[j]=t;
            i++;j--;
        }
    }
    return pindex;
}
void quickSort(int a[],int l,int h)
{
    if(l>=h)
    return;
    int part=partition(a,l,h);
    quickSort(a,l,part-1);
    quickSort(a,part+1,h);
}
int main()
{
    int n;
    printf("Enter size of array\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    quickSort(a,0,n-1);
    printf("Array after sorting is\n");
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
}