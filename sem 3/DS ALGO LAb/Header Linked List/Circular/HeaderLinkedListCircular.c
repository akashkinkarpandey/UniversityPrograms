#include <stdio.h>
#include <stdlib.h>
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
    if(start==NULL)
    {
        printf("No nodes to be deleted\n");
        return;
    }
    if(pos==1)
    {
        deleteHead();
        return;
    }
    int t=count();
    if(pos==t)
    {
        deleteEnd();
        return;
    }
    if(pos>t)
    {
        printf("Not enough nodes to be deleted\n");
        return;
    }
    struct node *ptr1=start->link,*ptr2=start->link;
    int c=0;
    pos--;
    while(1)
    {
        c++;
        ptr1=ptr1->link;
        if(pos==c)
        break;
        ptr2=ptr2->link;
    }
    ptr2->link=ptr1->link;
    free(ptr1);
}
int count()
{
    if(start==NULL)
    return 0;
    int c=0;
    struct node *ptr = start->link;
    while (ptr != start)
    {
        c++;
        ptr = ptr->link;
    }
    return c;
}
void insertAtPos(int val,int pos)
{
    if(start==NULL || pos==1)
    {
        insertAtHead(val);
        return;
    }
    int t=count();
    if(pos>t)
    {
        insertAtEnd(val);
        return;
    }
    struct node *ptr1=start->link,*ptr2=start->link;
    int c=0;
    pos--;
    while(1)
    {
        c++;
        ptr1=ptr1->link;
        if(pos==c)
        break;
        ptr2=ptr2->link;
    }
    struct node *newnode = (struct node *)(malloc(sizeof(struct node *)));
    newnode->data = val;
    ptr2->link=newnode;
    newnode->link=ptr1;
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
        start = NULL;
        return;
    }
    struct node *afterstart=start->link;
    start->link=start->link->link;
    free(afterstart);
}
int main()
{
    insertAtHead(4);
    deleteHead();
    insertAtHead(3);
    insertAtHead(5);
    // insertAtPos(10,1);
    insertAtEnd(7);

    insertAtEnd(8);

    // deleteEnd();

    insertAtEnd(9);
// deletefromanypos(6);

    printf("%d\n",count());
    print();
}