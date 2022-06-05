//doubly linked list:-
//prev pointer of head node is null ,rest nodes have 2 pointers
//prev pointer points to prev node,next one points to next node
//next of last node also points to NULL
#include <stdio.h>
#include <stdlib.h>
int count(void);
struct node
{
    int data;
    struct node *link;
    struct node *prev;
};
struct node *head;
//1,2 insert at end of list
void insertAtEnd(int val)
{
    struct node *newnode = (struct node *)(malloc(sizeof(struct node)));
    newnode->data = val;
    newnode->link = NULL;
    if (head == NULL) //if zero nodes are there
    {
        newnode->prev = NULL;
        head = newnode;
        return;
    }
    struct node *ptr = head;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    //ptr is last node
    //ptr->link is null which is linked to new node
    ptr->link = newnode;
    newnode->prev = ptr;
}
//3 insert at head
void insertAtHead(int val)
{
    struct node *newnode = (struct node *)(malloc(sizeof(struct node)));
    newnode->data = val;
    newnode->link = head;
    newnode->prev = NULL;
    head = newnode;
}
//4, 5
void insertAfterGivenPos(int pos, int val)
{
    struct node *newnode = (struct node *)(malloc(sizeof(struct node)));
    newnode->data = val;
    if (head == NULL)
    {
        //newnode->data=val;
        newnode->link = NULL;
        newnode->prev = NULL;
        head = newnode;
        return;
    }
    if (pos == 1)
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
    pos--;
    struct node *ptr1 = head, *ptr2 = head;
    int c = 0;
    while (1)
    {
        c++;
        ptr1 = ptr1->link;
        if (pos == c)
            break;
        ptr2 = ptr2->link;
    }
    newnode->prev = ptr2;
    newnode->link = ptr1;
    ptr2->link = newnode;
    ptr1->prev = newnode;
}
//6 print the list
void print()
{
    if (head == NULL)
    {
        printf("Empty Linked List\n");
        return;
    }
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}
//count nodes
int count()
{
    int c = 0;
    struct node *ptr = head;
    while (ptr != NULL)
    {
        c++;
        ptr = ptr->link;
    }
    return c;
    //printf("total number of nodes:-%d",c);
}
//find position of node
int find(int val)
{
    int c = 0;
    struct node *curr = head;
    while (curr != NULL)
    {
        c++;
        if (curr->data == val)
            return c;
        curr = curr->link;
    }
    return -1;
}

int main()
{
    while (1)
    {
        printf("Enter 1 to create Doubly Linked List\n");
        printf("Enter 2 to add a new node at the beginning of the list\n");
        printf("Enter 3 to add a node at the end of the list\n ");
        printf("Enter 4 to insert a given node after a given node\n");
        printf("Enter 5 to insert a given node before a given node\n");
        printf("Enter 6 to display contents of Linked List\n");
        printf("Enter any another number to exit\n");
        int n;
        scanf(" %d", &n);
        switch (n)
        {
        case 1:
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
        case 2:
            printf("Enter value to be inserted at beginning\n");
            int v;
            scanf("%d", &v);
            insertAtHead(v);
            break;
        case 3:
            printf("Enter a value\n");
            int v2;
            scanf("%d", &v2);
            insertAtEnd(v2);
            break;
        case 4:
            printf("Enter a data to be found in Linked List\n");
            int t2;
            scanf("%d", &t2);
            int f2 = find(t2);
            if (f2 == -1)
                printf("No such node found\n");
            else
            {
                int value1;
                printf("Enter a data to be inserted after in Linked List\n");
                scanf("%d", &value1);
                insertAfterGivenPos(f2 + 1, value1);
            }
            break;
        case 5:
            printf("Enter a data to be found in Linked List\n");
            int t1;
            scanf("%d", &t1);
            int f1 = find(t1);
            if (f1 == -1)
                printf("No such node found\n");
            else
            {
                int value1;
                printf("Enter a data to be inserted before in Linked List\n");
                scanf("%d", &value1);
                insertAfterGivenPos(f1 , value1);
            }
            break;
        case 6:
            // if(count()==0)
            // {
            //     printf("Empty\n");break;
            // }
            printf("Contents of Linked List are\n");
            print();
            break;
        default:
            printf("Exiting program\n");
            return 0;
        }
    }
}