//doubly circular linked list:-
//prev pointer of head node points to last node
//next pointer of last node points to head node
//each node has 2 pointers:-
//prev pointer points to previous node
//next pointer points to next node
//-->No pointer points to NULL
#include <stdio.h>
#include <stdlib.h>
int count();
struct node
{
    int data;
    struct node *link;
    struct node *prev;
};
struct node *head;
int count()
{
    int c = 0;
    if (head == NULL)
        return c;
    struct node *ptr = head;
    do
    {
        c++;
        ptr = ptr->link;
    } while (ptr != head);
    return c;
}

//1 insert at end of list
void insertAtEnd(int val)
{
    //insert 1st node
    if (head == NULL)
    {
        struct node *newnode = (struct node *)(malloc(sizeof(struct node)));
        newnode->data = val;
        newnode->link = newnode;
        newnode->prev = newnode;
        //both pointers point to itself in case of 1st node
        head = newnode;
        return;
    }
    //insert a node at end
    struct node *newlastnode = (struct node *)(malloc(sizeof(struct node)));
    newlastnode->data = val;
    //prev pointer of head points to last node
    struct node *last = head->prev; //find last node
    last->link = newlastnode;
    newlastnode->link = head;
    newlastnode->prev = last;
    head->prev = newlastnode;
}
//insert at head of list
void insertAtHead(int val)
{
    if (head == NULL) //insert 1st node when 0 nodes present
    {
        struct node *newnode = (struct node *)(malloc(sizeof(struct node)));
        newnode->data = val;
        newnode->link = newnode;
        newnode->prev = newnode;
        head = newnode;
        return;
    }
    struct node *newheadnode = (struct node *)(malloc(sizeof(struct node)));
    newheadnode->data = val;
    struct node *last = head->prev; //find last node
    last->link = newheadnode;
    newheadnode->prev = last;
    newheadnode->link = head;
    head->prev = newheadnode;
    head = newheadnode;
}
//insert at postion
//1 2
//1 3 2 
void insertAtPos(int val, int pos)
{
    int t = count();
    if (pos == 1)
    {
        insertAtHead(val);
        return;
    }
    if (pos > t)
    {
        insertAtEnd(val);
        return;
    }
    int c = 0;
    pos--;
    struct node *newnode = (struct node *)(malloc(sizeof(struct node)));
    newnode->data = val;
    struct node *ptr1 = head, *ptr2 = head;
    while (1)
    {
        c++;
        ptr1 = ptr1->link;
        if (c == pos)
            break;
        ptr2 = ptr2->link;
    }
    ptr2->link = newnode;
    ptr1->prev = newnode;
    newnode->link = ptr1;
    newnode->prev = ptr2;
}
//print the list
void print()
{
    //zero nodes
    if (head == NULL)
    {
        printf("Empty Linked List\n");
        return;
    }
    struct node *ptr = head;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    } while (ptr != head);
    printf("\n");
}
//delete head node of list
void deleteAtHead()
{
    if (head == NULL) //when zero nodes are present
    {
        printf("No nodes left to be deleted\n");
        return;
    }
    if (head->prev == head) //when one node is present
    {
        printf("%d data deleted\n", head->data);
        head = NULL;
        return;
    }
    struct node *second = head->link;
    second->prev = head->prev;
    struct node *tobedeleted = head->prev->link; //last node's link points to head node which is to be deleted
    head->prev->link = second;
    head = second;
    printf("%d data deleted\n", tobedeleted->data);
    free(tobedeleted);
}
//delete end node of list
void deleteAtEnd()
{
    if (head == NULL) //when zero nodes are present
    {
        printf("No nodes left to be deleted\n");
        return;
    }
    if (head->prev == head) //when one node is present
    {
        printf("%d data deleted\n", head->data);
        head = NULL;
        return;
    }
    //head->prev is last node
    //head->prev->prev is 2nd last node
    struct node *last = head->prev;
    head->prev->prev->link = head; //making 2nd last node's link point to head node
    head->prev = head->prev->prev;
    printf("%d data deleted\n", last->data);
    free(last);
}
void deleteFromAnyPosition(int pos)
{
    int t = count();
    if (t == 0)
    {
        printf("No node found\n");
        return;
    }
    if (pos == 1)
    {
        deleteAtHead();
        return;
    }
    if (pos > t)
    {
        printf("Not enough nodes to be deleted\n");
        return;
    }
    if (pos == t)
    {
        deleteAtEnd();
        return;
    }
    struct node *ptr1 = head, *ptr2 = head;
    pos--;
    int c = 0;
    while (1)
    {
        c++;
        ptr1 = ptr1->link;
        if (c == pos)
            break;
        ptr2 = ptr2->link;
    }
    ptr2->link = ptr1->link;
    ptr1->link->prev = ptr2;
    printf("%d data deleted\n", ptr1->data);
    free(ptr1);
}
int main()
{
    while (1)
    {
        printf("Enter 0 to create Doubly Circular Linked List\n");
        printf("Enter 1 to add a node at the end of the list\n ");
        printf("Enter 2 to add a new node at the beginning of the list\n");
        printf("Enter 3 to add a new node after the specified no. of nodes\n");
        printf("Enter 4 to display the contents of the list\n");
        printf("Enter 5 to delete head of Linked List\n");
        printf("Enter 6 to delete last node of Linked List\n");
        printf("Enter 7 to delete from a particular position of Linked List\n");
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
            deleteAtHead();
            break;
        case 6:
            // deletefromposition(count());
            deleteAtEnd();
            break;
        case 7:
            printf("Enter a postion\n");
            int t1;
            scanf("%d", &t1);
            deleteFromAnyPosition(t1);
            break;
        default:
            printf("Exiting program\n");
            return 0;
        }
    }
}
    //100 9 8 7
    // 99
    // 99 988