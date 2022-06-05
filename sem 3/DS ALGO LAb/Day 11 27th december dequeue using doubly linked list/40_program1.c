//deque implemented through doubly linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *front;
struct node *rear;
int isEmpty()
{
    return (front == NULL);
}
void insertHead(int val)
{
    struct node *newnode = (struct node *)(malloc(sizeof(struct node)));
    newnode->data = val;
    if (front == NULL)
    {
        newnode->next = NULL;
        newnode->prev = NULL;
        rear = front = newnode;
        printf("%d inserted at front\n", val);
        return;
    }
    newnode->prev = NULL;
    newnode->next = front;
    front->prev = newnode;
    front = newnode;
    printf("%d inserted at front\n", val);
}
void insertEnd(int val)
{
    struct node *newnode = (struct node *)(malloc(sizeof(struct node)));
    newnode->data = val;
    newnode->next = NULL;
    if (rear == NULL)
    {
        newnode->prev = NULL;
        front = rear = newnode;
        printf("%d inserted at rear\n", val);
        return;
    }
    newnode->prev = rear;
    rear->next = newnode;
    rear = newnode;
    printf("%d inserted at rear\n", val);
}
void deleteFront()
{
    if (isEmpty())
    {
        printf("Underflow\n");
        return;
    }
    struct node *ptr = front;
    front = front->next;
    if (front == NULL) //if no node remains after deletion
        rear = NULL;
    else //if there are many nodes after deletion
        front->prev = NULL;
    printf("%d data deleted\n", ptr->data);
    free(ptr);
}
void deleteEnd()
{
    if (isEmpty())
    {
        printf("Underflow\n");
        return;
    }
    struct node *ptr = rear;
    rear = rear->prev;
    if (rear == NULL) //if no element remains after deletion
        front = NULL;
    else //if many elements remain after deletion
        rear->next = NULL;
    printf("%d data deleted\n", ptr->data);
    free(ptr);
}
void print()
{
    if (isEmpty())
    {
        printf("Empty Deque\n");
        return;
    }
    printf("Deque elements are:-\n");
    struct node *ptr = front;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
void getFront()
{
    if (isEmpty())
    {
        printf("Empty Deque\n");
        return;
    }
    printf("Front is %d", front->data);
    printf("\n");
}
int main()
{

    printf("Enter 1 to save choice for inserting at front\n");
    printf("Enter 2 to save choice for inserting at end\n");
    int a;
    scanf("%d", &a);
    if (a != 1 && a != 2)
    {
        printf("Wrong choice..exiting\n");
        return 0;
    }
    while (1)
    {
        printf("Enter 1 to insert\n");
        printf("Enter 2 to delete at front\n");
        printf("Enter 3 to delete at end\n");
        printf("Enter 4 to print\n");
        printf("Enter 5 to get front element\n");
        printf("Enter any other number for exiting\n");
        int choice;
        int value = -1;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter a value\n");
            scanf("%d", &value);
            if (a == 1)
            {
                insertHead(value);
                break;
            }
            else
            {
                insertEnd(value);
                break;
            }
            break;
        case 2:
            deleteFront();
            break;
        case 3:
            deleteEnd();
            break;
        case 4:
            print();
            break;
        case 5:
            getFront();
            break;
        default:
            printf("Thanks for exiting\n");
            return 0;
        }
    }
}
