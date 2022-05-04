#include <stdio.h>
#include <stdlib.h>
//errror delete head
struct node
{
    int data;
    struct node *link;
};
void deleteHead();
void deleteEnd();
int count();
struct node *start;
void insertAtEnd(int val)
{
    struct node *newnode = (struct node *)(malloc(sizeof(struct node *)));
    newnode->data = val;
    if (start == NULL)
    {
        start = (struct node *)(malloc(sizeof(struct node *)));
        start->data = 1; //counting nodes
        start->link = newnode;
        newnode->link = start;
        return;
    }
    start->data = start->data + 1; //counting nodes
    struct node *ptr = start->link;
    while (ptr->link != start)
        ptr = ptr->link;
    ptr->link = newnode;
    newnode->link = start;
}
void insertAtHead(int val)
{
    struct node *newnode = (struct node *)(malloc(sizeof(struct node *)));
    newnode->data = val;
    if (start == NULL)
    {
        start = (struct node *)(malloc(sizeof(struct node *)));
        start->data = 1; //counting nodes
        start->link = newnode;
        newnode->link = start;
        return;
    }
    start->data = start->data + 1; //counting nodes
    newnode->link = start->link;
    start->link = newnode;
}
void print()
{
    if (start == NULL)
    {
        printf("Empty Linked List\n");
        return;
    }
    struct node *ptr = start->link;
    while (ptr != start)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}
void deletefromanypos(int pos)
{
    if (start == NULL)
    {
        printf("No nodes to be deleted\n");
        return;
    }
    if (pos == 1)
    {
        deleteHead();
        return;
    }
    int t = count();
    if (pos == t)
    {
        deleteEnd();
        return;
    }
    if (pos > t)
    {
        printf("Not enough nodes to be deleted\n");
        return;
    }
    struct node *ptr1 = start->link, *ptr2 = start->link;
    int c = 0;
    pos--;
    while (1)
    {
        c++;
        ptr1 = ptr1->link;
        if (pos == c)
            break;
        ptr2 = ptr2->link;
    }
    ptr2->link = ptr1->link;
    printf("%d data deleted\n", ptr1->data);
    free(ptr1);
}
int count()
{
    if (start == NULL)
        return 0;
    int c = 0;
    struct node *ptr = start->link;
    while (ptr != start)
    {
        c++;
        ptr = ptr->link;
    }
    return c;
}
void insertAtPos(int val, int pos)
{
    if (start == NULL || pos == 1)
    {
        insertAtHead(val);
        return;
    }
    int t = count();
    if (pos > t)
    {
        insertAtEnd(val);
        return;
    }
    struct node *ptr1 = start->link, *ptr2 = start->link;
    int c = 0;
    pos--;
    while (1)
    {
        c++;
        ptr1 = ptr1->link;
        if (pos == c)
            break;
        ptr2 = ptr2->link;
    }
    struct node *newnode = (struct node *)(malloc(sizeof(struct node *)));
    newnode->data = val;
    ptr2->link = newnode;
    newnode->link = ptr1;
}
void deleteEnd()
{
    if (start == NULL) //zero nodes
    {
        printf("No nodes found\n");
        return;
    }
    if (start->link->link == start) //one node
    {
        printf("%d data deleted\n", start->link->data);
        start = NULL;
        return;
    }
    struct node *ptr = start->link;
    while (ptr->link->link != start)
    {
        ptr = ptr->link;
    }
    struct node *last = ptr->link;
    ptr->link = start;
    printf("%d data deleted\n", last->data);
    free(last);
}
void deleteHead()
{
    if (start == NULL) //zero nodes
    {
        printf("No nodes found\n");
        return;
    }
    if (start->link->link == start) //one node
    {
        printf("%d data deleted\n", start->link->data);
        start = NULL;
        return;
    }
    struct node *afterstart = start->link;
    start->link = start->link->link;
    printf("%d data deleted\n", afterstart->data);
    free(afterstart);
}
int main()
{
    while (1)
    {
        printf("Enter 0 to create Header (Circular) Linked List\n");
        printf("Enter 1 to add a node at the end of the list\n ");
        printf("Enter 2 to add a new node at the beginning of the list\n");
        printf("Enter 3 to add a new node at a particular position\n");
        printf("Enter 4 to display the contents of the list\n");
        printf("Enter 5 to delete head of Linked List\n");
        printf("Enter 6 to delete last node of Linked List\n");
        printf("Enter 7 to delete from a particular position of Linked List\n");
        printf("Enter any other number to exit\n");
        int n;
        scanf(" %d", &n);
        switch (n)
        {
        case 0:
            printf("Enter -1 to exit\n");
            while (1)
            {
                printf("Enter value for Linked List\n");
                int vale;
                scanf("%d", &vale);
                if (vale == -1)
                    break;
                insertAtEnd(vale);
            }
            break;
        case 1:
            printf("Enter a value\n");
            int v2;
            scanf("%d", &v2);
            insertAtEnd(v2);
            break;
        case 2:
            printf("Enter value to be inserted at beginning\n");
            int v;
            scanf("%d", &v);
            insertAtHead(v);
            break;
        case 3:
            printf("Enter position\n");
            int pos;
            scanf("%d", &pos);
            printf("Enter value to be inserted\n");
            int v1;
            scanf("%d", &v1);
            insertAtPos(v1, pos);
            break;
        case 4:
            // if(count()==0)
            // {
            //     printf("Empty\n");break;
            // }
            printf("Contents of Linked List are\n");
            print();
            break;
        case 5:
            deleteHead();
            break;
        case 6:
            // deletefromposition(count());
            deleteEnd();
            break;
        case 7:
            printf("Enter a postion\n");
            int t1;
            scanf("%d", &t1);
            deletefromanypos(t1);
            break;
        default:
            printf("Exiting program\n");
            return 0;
        }
    }
}
