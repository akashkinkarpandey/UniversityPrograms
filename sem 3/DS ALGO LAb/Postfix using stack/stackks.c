#include<stdio.h>
int a[100];
int i=-1;
//focus more on operations rather than implementations in stacks ADT
//LIFO or FILO principle for stacks
void push1(int x)
{
    if(i==99)//max size reached
    {
        printf("Overflow\n");
        return;
    }
    a[++i]=x;//insert
}
int isEmpty1()
{
    return (i==-1);//if no element has been inserted yet
}
int size1()
{
    return (i+1);
}
void pop1()
{
    if(isEmpty1())//underflow checking
    {
        printf("Nothing to be deleted\n");
        return;
    }
    printf("%d deleted\n",a[i]);
    i--;//reducing index
}
int top1()
{
return a[i];
}

void print1()
{
    if(isEmpty1())//underflow checking
    {
        printf("Nothing to be printed\n");return;
    }
    for(int j=i;j>=0;j--)//topmost elements printed first 
    printf("%d ",a[j]);
    printf("\n");
}
int main()
{
    int val;
    while(1)
    {
        printf("Enter 1 for push\n");
        printf("Enter 2 for pop\n");
        printf("Enter 3 for display\n");
        printf("Enter any other value to exit\n");
        int n;
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            printf("Enter a value\n");
            scanf("%d",&val);
            push1(val);
            break;
            case 2:
            pop1();
            break;
            case 3:
            print1();
            break;
            default:
            printf("EXITING\n");
            break;
        }
    }
}