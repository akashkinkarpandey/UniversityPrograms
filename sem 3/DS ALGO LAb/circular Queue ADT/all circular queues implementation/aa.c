#include <stdio.h>
//queue is based on FIFO/LILO operation.
//insertion in queue is enqueue operation
//deletion in queue is dequeue operation
int a[100];
int c = 0;
int front = -1;
int rear = -1;
int size;
int isEmpty()
{   
    return (front ==rear);
    //returns 1 if queue is empty
}
void pop()
{
    //dequeue operation(deletion)
    if (isEmpty())
    {
        front = rear = -1;
        printf("Nothing to be deleted\n");
        return;
    }
    c--;//dec count of number of elements
    front++;
}
void push(int x)
{
    //enqueue operation(insertion)
    if(c==size)
    {
        printf("Overflow\n");return;
    }
    c++;//increasing count of elements
    if (isEmpty()) //inserting 1st element
    {
        front = 0;rear=0;
        a[rear++] = x;//a[rear]=x;rear++;
        return;
    }
    a[rear++] = x;
}
void top()
{
    //beginning element of queue
    if(isEmpty())
    {
        printf("Queue is empty\n");return;
    }
    printf("%d is front\n",a[front]);
}
void print()
{
    if(isEmpty())
    {
        printf("Queue is empty\n");return;
    }
    for(int i=front;i<rear;i++)//printing from front to end
    printf("%d ",a[i]);
    printf("\n");
}
int main()
{
printf("Enter size\n");
scanf("%d",&size);
print();//empty queue printed
push(7);
push(8);//8
push(9);//8 9(like a railway ticket line where 8 will get the 1st ticket)
print();//8 9 printed
top();
pop();//9(8 is popped out)
print();//9 printed
pop();//9 popped out
print();//empty queue
push(7);
print();
top();

print();//empty queue printed
push(7);
push(8);//8
push(9);//8 9(like a railway ticket line where 8 will get the 1st ticket)
print();//8 9 printed
top();
pop();//9(8 is popped out)
print();//9 printed
pop();//9 popped out
print();//empty queue
push(7);
print();
top();
}