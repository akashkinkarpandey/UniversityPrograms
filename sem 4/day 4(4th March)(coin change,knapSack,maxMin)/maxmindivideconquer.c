#include<stdio.h>
#include<limits.h>
int maxi,mini;
void find(int a[],int l,int h)
{
    if(l==h)
    {
        if(a[l]>maxi)
            maxi=a[l];
        if(a[l]<mini)
            mini=a[l];
        return;
    }
    int mid=l+(h-l)/2;
    find(a,l,mid);
    find(a,mid+1,h);
}
int main()
{
    maxi=INT_MIN;
    mini=INT_MAX;
    int n;
    printf("Enter size\n");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter element\n");
        scanf("%d",&a[i]);
    }
    find(a,0,n-1);
    printf("Max is %d\n",maxi);
    printf("Min is %d\n",mini);
}