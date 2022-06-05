#include<stdio.h>
int c[10],d[10];
int main()
{
int a;int b;
printf("Enter two numbers\n");
scanf("%d %d",&a,&b);
while(a>0)
{
    c[a%10]++;
    a=a/10;
}
while(b>0)
{
    c[b%10]++;
    b=b/10;
}
int fl=0;
for(int i=0;i<10;i++)
{
    if(c[i]!=d[i])
    {
        fl=1;break;
    }
}
if(fl==0)
printf("same");
else printf("not same");

}
