//Circular queue
#include <stdio.h>
#include <stdlib.h>
//if space is left in queue:-
//we will insert an item at beginning
int a[100];
int c = 0;
int front = -1;
int rear = -1;
int size;
int isEmpty()
{
    return (front == rear);
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
    printf("%d deleted\n", a[front]);
    c--; //dec count of number of elements
    front++;
}
void push(int x)
{
    //enqueue operation(insertion)
    if (c == size)
    {
        printf("Overflow\n");
        return;
    }
    c++;           //increasing count of elements
    if (isEmpty()) //inserting 1st element
    {
        front = 0;
        rear = 0;
        a[rear++] = x; //a[rear]=x;rear++;
        return;
    }
    a[rear++] = x;
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
    for (int i = front; i < rear; i++) //printing from front to end
        printf("%d ", a[i]);
    printf("\n");
}
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
    if (rear1 == NULL) //when queue is empty
    {
        front1 = rear1 = newnode;
        rear1->link = front1;
        return;
    }
    else
    {
        rear1->link = newnode; //insert1 at end
        rear1 = newnode;
        newnode->link = front1;
    }
}
void pop1()
{
    if (front1 == NULL && rear1 == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }
    // c1--;
    if (front1 == rear1) //if only one node was there
    {
        struct node *tobedeleted = front1;
        free(tobedeleted);
        printf("%d deleted\n", front1->data);
        front1 = rear1 = NULL; //make the list empty
        return;
    }
    struct node *tobedeleted = front1;
    front1 = front1->link;
    rear1->link = front1;
    printf("%d deleted\n", tobedeleted->data);
    free(tobedeleted);
}
void top1()
{
    if (front1 == NULL) //underflow
    {
        printf("Empty queue\n");
        return;
    }
    printf("%d is front element\n", front1->data);
}
void print1()
{
    if (front1 == NULL)
    {
        printf("Nothing to be printed\n");
        return;
    }
    printf("Queue elements are\n");
    struct node *ptr = front1;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }while (ptr != front1);

    printf("\n");
}
int main()
{
    int choice;
    printf("Enter 1 for Implement Circular Queue using array\n");
    printf("Enter 2 for Implement Circular Queue using Linked List\n");
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
