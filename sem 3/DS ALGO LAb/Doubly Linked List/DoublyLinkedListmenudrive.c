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
//1 insert at end of list
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
//insert at head
void insertAtHead(int val)
{
    struct node *newnode = (struct node *)(malloc(sizeof(struct node)));
    newnode->data = val;
    newnode->link = head;
    newnode->prev = NULL;
    head = newnode;
}
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
//4 print the list
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
//delete 5 head of list
void deletehead()
{
    if (head == NULL) //if no node found
    {
        printf("Linked List is Empty\n");
        return;
    }
    if (head->link == NULL) //if only one node found
    {
        printf("data %d from head node deleted\n", head->data);
        head = NULL;
        return;
    }
    struct node *ptr = head;
    printf("data %d from head node deleted\n", ptr->data);
    head = head->link; //2nd node becomes head node
    head->prev = NULL;
    free(ptr);
}
//delete 6 end node of list
void deleteEnd()
{
    if (head == NULL) //if no node found
    {
        printf("Linked List is Empty\n");
        return;
    }
    if (head->link == NULL) //if only one node found
    {
        head = NULL;
        return;
    }
    struct node *ptr = head;
    while (ptr->link->link != NULL)
        ptr = ptr->link;
    //ptr is 2nd last node
    //ptr->link is last node
    struct node *last = ptr->link;
    ptr->link = NULL;
    free(last);
}
//7 find number of nodes having data equal to given value
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
void deletefromposition(int pos)
{
    if(pos==1)
    {
        deletehead();return;
    }
    int t=count();
    if(pos==t)
    {
        deleteEnd();return;
    }
    if(pos>t)
    {
        printf("No node found at position %d\n",pos);
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
    struct node *tobedeleted=ptr1;
    ptr2->link=ptr1->link;
    ptr1->link->prev=ptr2;
    free(tobedeleted);
}
//8 delete by value
void deletebyvalue(int data)
{
    int t = find(data);
    if (t == -1)
    {
        printf("Number not found\n");
        return;
    }
    printf("%d is deleted\n", data);
    deletefromposition(t);
}

int main()
{
    while (1)
    {
        printf("Enter 0 to create Doubly Linked List\n");
        printf("Enter 1 to add a node at the end of the list\n ");
        printf("Enter 2 to add a new node at the beginning of the list\n");
        printf("Enter 3 to add a new node after the specified no. of nodes\n");
        printf("Enter 4 to display the contents of the list\n");
        printf("Enter 5 to delete head of Linked List\n");
        printf("Enter 6 to delete last node of Linked List\n");
        printf("Enter 7 to find a node with value equal to input value\n");
        printf("Enter 8 to delete a value\n");
        printf("Enter any another number to exit\n");
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
            insertAfterGivenPos(pos, v1);
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
            deletehead();
            break;
        case 6:
            // deletefromposition(count());
            deleteEnd();
            break;
        case 7:
            printf("Enter a value \n");
            int yy;
            scanf("%d", &yy);
            int found = find(yy);
            if (found == -1)
                printf("Not found in Linked List\n");
            else
            {
                printf("node having %d found at pos %d\n", yy, found);
            }
            break;
        case 8:
            printf("Enter a value to be deleted \n");
            int oo;
            scanf("%d", &oo);
            deletebyvalue(oo);
            break;
        default:
            printf("Exiting program\n");
            return 0;
        }
    }
}