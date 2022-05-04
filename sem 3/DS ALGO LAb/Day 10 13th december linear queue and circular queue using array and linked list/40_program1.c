#include <stdio.h>
#include <stdlib.h>
int a[100];
int c = 0;
int front = -1;
int rear = -1;
int size;
//Linear Queues using array
int isEmpty()
{
    return (front ==-1 && rear==-1);
    //returns 1 if queue is empty
}
void pop()
{
    //dequeue operation(deletion)
    if (isEmpty())//when queue is empty
    {
        front = rear = -1;
        printf("Nothing to be deleted\n");
        return;
    }
    else if(front==rear)//when the only element was deleted
    {
        printf("%d is deleted\n",a[front]);
        front=rear=-1;
    }
    else
    {
        printf("%d is deleted\n",a[front]);
        front++;
    }
    
}
//we insert only when front is -1 and rear is -1
//or we insert when last element of queue was deleted 
void push(int x)
{
    //enqueue operation(insertion)
    if (rear==size-1)
    {
        printf("Overflow\n");
        return;
    }
    else if(isEmpty())
    {
        front=rear=0;
        a[rear]=x;
    }
    else
    {
        a[++rear]=x;
    }
}
void top()
{
    //beginning element of queue
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("%d is front\n", a[front]);
}
void print()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are\n");
    for (int i = front; i<=rear; i++) //printing from front to end
        printf("%d ", a[i]);
    printf("\n");
}
//Linear Queues using Linked List
struct node
{
    int data;
    struct node *link;
};
struct node *front1;
struct node *rear1;
int isEmpty1()
{
    return (front1 == NULL && rear1 == NULL);
    // returns 1 if empty
}
void insert1(int val)
{
    struct node *newnode = (struct node *)(malloc(sizeof(struct node)));
    newnode->data = val;
    newnode->link = NULL;
    if (isEmpty1()) //when queue is empty
    {
        front1 = rear1 = newnode;
        return;
    }
    rear1->link = newnode; //insert1 at end
    rear1 = newnode;
}
void pop1()
{
    if (front1 == NULL && rear1==NULL)
    {
        printf("Queue is Empty\n");
        return;
    }
    if (front1->link == NULL) //if only one node was there
    {
        printf("%d deleted\n",front1->data);
        front1 = rear1 = NULL; //make the list empty
        return;
    }
    struct node *tobedeleted = front1;
    front1 = front1->link;
    printf("%d deleted\n",tobedeleted->data);
    free(tobedeleted);
}
void top1()
{
    if (front1 == NULL && rear1==NULL) //underflow
    {
        printf("Empty queue\n");
        return;
    }
    printf("%d is front element\n", front1->data);
}
void print1()
{
    if (front1 == NULL && rear1==NULL)
    {
        printf("Nothing to be printed\n");
        return;
    }
    printf("Queue elements are\n");
    struct node *ptr = front1;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

int main()
{
    int choice;
    printf("Enter 1 for Implement Queue using array\n");
    printf("Enter 2 for Implement Queue using Linked List\n");
    printf("Enter any other number for exiting\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("Enter size of queue\n");
        scanf("%d", &size);
        while (1)
        {
            printf("Enter 1 for push\n");
            printf("Enter 2 for pop\n");
            printf("Enter 3 for front\n");
            printf("Enter 4 for print\n");
            printf("Enter any other number for exiting\n");
            int n;
            scanf("%d", &n);
            switch (n)
            {
            case 1:
                printf("Enter a number\n");
                int val;
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                top();
                break;
            case 4:
                print();
                break;
            default:
                printf("EXITING\n");
                return 0;
            }
        }
    }
    else if (choice == 2)
    {
        // printf("Enter size of queue\n");
        // scanf("%d", &size1);
        while (1)
        {

            printf("Enter 1 for push\n");
            printf("Enter 2 for pop\n");
            printf("Enter 3 for front\n");
            printf("Enter 4 for print\n");
            printf("Enter any other number for exiting\n");
            int n;
            scanf("%d", &n);
            switch (n)
            {
            case 1:
                printf("Enter a number\n");
                int val1;
                scanf("%d", &val1);
                insert1(val1);
                break;
            case 2:
                pop1();
                break;
            case 3:
                top1();
                break;
            case 4:
                print1();
                break;
            default:
                printf("EXITING\n");
                return 0;
            }
        }
    }
    else
    {
        printf("EXITING\n");
        return 0;
    }
}
