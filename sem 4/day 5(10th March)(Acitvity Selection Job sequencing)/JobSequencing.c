#include<stdio.h>
#include<limits.h>
// Enter number of items
// 5
// Enter id,profit,deadline
// 1 100 2
// Enter id,profit,deadline
// 2 19 1
// Enter id,profit,deadline
// 3 27 2
// Enter id,profit,deadline
// 4 25 1
// Enter id,profit,deadline
// 5 15 3
// Jobs done are ->3,Profit is->142
// Job ids order in which they were performed are given -> 1 3 5
void swap(int a[],int i,int j)
{
    int t=a[i];
    a[i]=a[j];
    a[j]=t;
}
void sort(int id[],int profit[],int deadline[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(profit[j]<profit[j+1])
            {
                swap(profit,i,j);
                swap(id,i,j);
                swap(deadline,i,j);
            }
        }
    }
}
int main()
{
    int n;
    printf("Enter number of items\n");
    scanf("%d",&n);
    int profit[n],id[n],deadline[n];
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        printf("Enter id,profit,deadline\n");
        scanf("%d %d %d",&id[i],&profit[i],&deadline[i]);
        // maxi=max(maxi,deadline[i]);
        if(deadline[i]>maxi)
        maxi=deadline[i];
    }
    sort(id,profit,deadline,n);
    int max_dead[maxi+1];
    for(int i=0;i<=maxi;i++)
        max_dead[i]=-1;
    int count=0;
    int profi=0;
    int jobs_id[n];
    for(int i=0;i<n;i++)
    {
        int j=deadline[i];
        while(j>0)
        {
            if(max_dead[j]==-1)
            {
                jobs_id[count]=id[i];
                count++;
                profi+=profit[i];
                max_dead[j]=1;//assign anything apart from -1
                break; 
           }
           else j--;
        }
    }
    printf("Jobs done are ->%d,Profit is->%d\n",count,profi);
    printf("Job ids order in which they were performed are given-> ");
    for(int i=0;i<count;i++)
    {
        printf("%d ",jobs_id[i]);
    }
    printf("\n");
}
