#include<stdio.h>
void max_heap(int a[],int n,int i)
{
    int l=2*i;
    int r=2*i+1;
    int largest=i;
    if(l<=n && a[l]>a[i])
    largest=l;
    if(r<=n && a[r]>a[largest])
    largest=r;
    if(largest!=i)
    {
        int t=a[i];
        a[i]=a[largest];
        a[largest]=t;
        max_heap(a,n,largest);
    }
}
void build_heap(int a[],int n)
{
    for(int i=n/2;i>=1;i--)
        max_heap(a,n,i);
}
void heapsort(int a[],int n)
{
    build_heap(a,n);

    for(int i=n;i>1;i--)
    {
        int t=a[1];
        a[1]=a[i];
        a[i]=t;
        n--;
        max_heap(a,n,1);
    }
}
int main()
{
    int n;
    printf("enter size\n");
    scanf("%d",&n);
    int a[n];
    for(int i=1;i<=n;i++)
    {
    printf("enter element\n");
        scanf("%d",&a[i]);
    }
    heapsort(a,n);
    for(int i=1;i<=n;i++)
    printf("%d ",a[i]);
}