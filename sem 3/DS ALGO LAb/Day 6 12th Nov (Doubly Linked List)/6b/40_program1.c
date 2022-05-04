//doubly linked list:-
//prev pointer of head node is null ,rest nodes have 2 pointers
//prev pointer points to prev node,next one points to next node
//next of last node also points to NULL
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
    struct node *ptr = head;
    while (ptr != NULL)
    {
        c++;
        ptr = ptr->link;
    }
    return c;
    //printf("total number of nodes:-%d",c);
}
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
//1 create a Doubly Linked List
void insertAtEnd(int val)
{
    struct node *ne node = (struct node *)(malloc(sizeof(struct node)));
    ne node->data = val;
    ne node->link = NULL;
    if (head == NULL) //if zero nodes are there
    {
        ne node->prev = NULL;
        head = ne node;
        return;
    }
    struct node *ptr = head;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    //ptr is last node
    //ptr->link is null which is linked to new node
    ptr->link = ne node;
    ne node->prev = ptr;
}
//delete 2 head of list
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
//delete 3 end node of list
void deleteEnd()
{
    if (head == NULL) //if no node found
    {
        printf("Linked List is Empty\n");
        return;
    }
    if (head->link == NULL) //if only one node found
    {
    printf("%d data deleted\n",head->data);
        head = NULL;
        return;
    }
    struct node *ptr = head;
    while (ptr->link->link != NULL)
        ptr = ptr->link;
    //ptr is 2nd last node
    //ptr->link is last node
    struct node *last = ptr->link;
    printf("%d data deleted\n",last->data);
    ptr->link = NULL;
    free(last);
}
//4,5 delete from any postion
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
    printf("%d data deleted\n",tobedeleted->data);
    free(tobedeleted);
}
//6 print list
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

int main()
{
    while (1)
    {
        printf("Enter 1 to create Doubly Linked List\n");
        printf("Enter 2 to delete a new node from the beginning of the list\n");
        printf("Enter 3 to delete a node from the end of the list\n ");
        printf("Enter 4 to delete a node after the given node\n");
        printf("Enter 5 to delete a node before the given node\n");
        printf("Enter 6 to display contents of Linked List\n");
        printf("Enter any another number to exit\n");
        int n;
        scanf("%d", &n);
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
            deletehead();
            break;
        case 3:
            deleteEnd();
            break;
        case 4:
            printf("Enter a data to be found in Linked List\n");
            int t2;
            scanf("%d", &t2);
            int f2 = find(t2);
            int cc = count();
            if (f2 == -1)
                printf("No such node found\n");
            else if (f2 == cc)
                printf("No node after %d node\n", t2);
            else
                deletefromposition(f2 + 1);
            break;
        case 5:
            printf("Enter a data to be found in Linked List\n");
            int t1;
            scanf("%d", &t1);
            int f1 = find(t1);
            if (f1 == -1)
                printf("No such node found\n");
            else if (f1 == 1)
                printf("No node found before %d node\n", t1);
            else
                deletefromposition(f1 - 1);
            break;
        case 6:
            print();
            break;
        default:
            printf("Exiting\n");
            break;
        }
    }
}