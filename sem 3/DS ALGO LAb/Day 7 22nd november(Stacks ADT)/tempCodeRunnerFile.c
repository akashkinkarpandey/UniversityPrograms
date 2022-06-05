#include <stdio.h>
#include <stdlib.h>
int a[100];
int i = -1;
//focus more on operations rather than implementations in stacks ADT
//LIFO or FILO principle for stacks
void push1(int x)
{
    if (i == 99) //max size reached
    {
        printf("Overflow\n");
        return;
    }
    a[++i] = x; //insert
}
int isEmpty1()
{
    return (i == -1); //if no element has been inserted yet
}
int size1()
{
    return (i + 1);
}
void pop1()
{
    if (isEmpty1()) //underflow checking
    {
        printf("Nothing to be deleted\n");
        return;
    }
    printf("%d deleted\n", a[i]);
    i--; //reducing index
}
int top1()
{
    return a[i];
}

void print1()
{
    if (isEmpty1()) //underflow checking
    {
        printf("Nothing to be printed\n");
        return;
    }
    for (int j = i; j >= 0; j--) //topmost elements printed first
        printf("%d ", a[j]);
    printf("\n");
}

struct node
{
    int data;
    struct node *link;
};
struct node *top;
int c = 0;
int isEmpty()
{
    return top == NULL;
    //if empty returns true
}
void push(int val)
{
    c++;
    //inserting at head of stack
    struct node *newnode = (struct node *)(malloc(sizeof(struct node)));
    newnode->data = val;
    newnode->link = top;
    top = newnode;
}
void pop()
{
    if (isEmpty()) //zero elements in stack
    {
        printf("Nothing to be deleted\n");
        return;
    }
    c--;
    //deleting top/head of stack
    struct node *ptr = top;
    printf("data %d from head node deleted\n", ptr->data);
    top = top->link;
    free(ptr);
}
void print()
{
    if (isEmpty())
    {
        printf("Nothing to be printed\n");
        return;
    }
    struct node *ptr = top;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}
void topp()
{
    if (isEmpty()) //zero elements in stack
    {
        printf("No top element found\n");
        return;
    }
    printf("%d\n", top->data);
}

int main()
{
    int choice;
    printf("Enter for 1 for stacks using arrays\n");
    printf("Enter for 2 for stacks using linked list\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        int val;
        while (1)
        {
            printf("Enter 1 for push\n");
            printf("Enter 2 for pop\n");
            printf("Enter 3 for display\n");
            printf("Enter any other value to exit\n");
            int n;
            scanf("%d", &n);
            switch (n)
            {
            case 1:
                printf("Enter a value\n");
                scanf("%d", &val);
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
                return 0;
                break;
            }
        }
    }
    else if (choice == 2)
    {
        int val;
        while (1)
        {
            printf("Enter 1 for push\n");
            printf("Enter 2 for pop\n");
            printf("Enter 3 for display\n");
            printf("Enter any other value to exit\n");
            int n;
            scanf("%d", &n);
            switch (n)
            {
            case 1:
                printf("Enter a value\n");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                print();
                break;
            default:
                printf("EXITING\n");
                return 0;
                break;
            }
        }
    }
    else printf("Wrong choice Exiting\n");
}