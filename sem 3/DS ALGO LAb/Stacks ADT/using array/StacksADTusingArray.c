#include<stdio.h>
int a[100];
int i=-1;
//focus more on operations rather than implementations in stacks ADT
//LIFO or FILO principle for stacks
void push(int x)
{
    if(i==99)//max size reached
    {
        printf("Overflow\n");
        return;
    }
    a[++i]=x;//insert
}
int isEmpty()
{
    return (i==-1);//if no element has been inserted yet
}
int size()
{
    return (i+1);
}
void pop()
{
    if(isEmpty())//underflow checking
    {
        printf("Nothing to be deleted\n");
        return;
    }
    i--;//reducing index
}
int top()
{
return a[i];
}

void print()
{
    if(isEmpty())//underflow checking
    {
        printf("Nothing to be printed\n");return;
    }
    for(int j=i;j>=0;j--)//topmost elements printed first 
    printf("%d ",a[j]);
    printf("\n");
}
int main()
{
push(5);//5 
push(6);//5 6
push(7);//5 6 7
pop();//5 6 (7 being topmost popped out)
printf("%d\n",top());// 6 printed
print();//print stack elements from top to bottom of stack
//6 5 printed
printf("%d\n",size());// 2 printed
printf("%d\n",isEmpty());// 0(falsee) printed as stack is not empty
}