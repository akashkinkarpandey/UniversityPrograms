#include<stdio.h>
int division(int a,int b,int c)
{   
    //2 base conditions
    //c is used for counting
    if(b==1)
    return a;
    if(a<0)
    return c-1;
    if(a==0)
    return c;
    return division(a-b,b,c+1);
	
}
int main()
{
    int t,a,b,c=0;
    printf("Enter  2 numbers to do a/b\n");
    //c is counting
    //number of times
    //b is subtracted from a
    scanf("%d %d",&a,&b);
    printf("Integer part after division is\n");
    if(a<0 &&b<0) 
    {
    t=division(-1*a,-1*b,c);
    printf("%d\n",t);
    }
    else if(a<0) 
    {
    t=division(-1*a,b,c);
    printf("%d\n",-t);
    }
    else if(b<0)
    {
    t=division(a,-1*b,c);
    printf("%d\n",-t);
    }
    else 
    {
    t=division(a,b,c);
    printf("%d\n",t);
    }

}