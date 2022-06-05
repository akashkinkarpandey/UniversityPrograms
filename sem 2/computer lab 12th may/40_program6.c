#include<stdio.h>
int main()
{
    int a=1,b=2;
    int sum=a+b;
    int c=0;
    int n;scanf("%d",&n);
    while(1)
    {
        a=b;b=sum;
        sum=a+b;
        for(int i=b+1;i<sum;i++)
        {
            if(i<=n)
            printf("%d\n",i);
            if(i>n)
            return 0;

        }

    }
}