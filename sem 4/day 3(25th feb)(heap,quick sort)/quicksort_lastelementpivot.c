#include<stdio.h>
int partition(int a[],int p,int r)
{
    int pivot=a[r];
    int i=p-1;
    for(int j=p;j<=r-1;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            int t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    int t=a[i+1];
    a[i+1]=a[r];
    a[r]=t;
    return i+1;
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
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    quickSort(a,0,n-1);
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
}