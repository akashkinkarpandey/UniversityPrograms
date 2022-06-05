#include <stdio.h>
#include <stdio.h>
int n;
// const int N = 1e3+10;
// int a[N];
int count,front,rear;
void push(int x,int a[])
{
    if(count==n)
    {
        printf("Queue is full\n");
        return;
    }
    a[rear%n]=x;
    rear++;
    count++;
}
int pop(int a[])
{
    if(count==0)
    {
        printf("Queue is empty\n");
        return 0;
    }
    int t=a[front%n];
    front++;
    count--;
return t;
}
int top(int a[])
{
    if(count==0)
    {   
        printf("No element present in array\n");
        return -1;
    }
    return a[front%n];
}
void print(int a[])
{
    if(count==0)
    {   
        printf("No element present in array\n");
        return ;
    }
    for(int i=front;i<rear;i++)
    printf("%d ",a[i%n]);
    printf("\n");
}
int main()
{
    printf("Enter size of array\n");
    scanf("%d",&n);
    int a[n];
    while (1)
    {
        printf("Enter 0 for exit\n");
        printf("Enter 1 for push\n");
        printf("Enter 2 for pop\n");
        printf("Enter 3 for top element\n");
        printf("Enter 4 for printing queue\n");
        int n1;
        scanf("%d",&n1);
        switch(n1)
        {
        case 0:
            printf("Thanks for exiting\n");
            return 0;
        case 1:
            printf("Enter a number to be pushed\n");
            int b;
            scanf("%d",&b);
            push(b,a);
            break;
        case 2:
            printf("%d has been popped out\n", pop(a));
            break;
        case 3:
            if(top(a)!=-1)
            printf("%d is top element\n", top(a));
            break;
        case 4:
        print(a);
        break;
        default:
            printf("Wrong Input\n");
            break;
        }
    }
}