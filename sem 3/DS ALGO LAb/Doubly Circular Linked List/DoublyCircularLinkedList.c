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
    if(head==NULL)
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
void insertAtPos(int val,int pos)
{
    int t=count();
    if(pos==1)
    {
        insertAtHead(val);
        return;
    }
    if(pos>t)
    {
        insertAtEnd(val);return;
    }
    int c=0;
    pos--;
    struct node *newnode = (struct node *)(malloc(sizeof(struct node)));
    newnode->data = val;
    struct node *ptr1=head,*ptr2=head;
    while(1)
    {
        c++;
        ptr1=ptr1->link;
        if(c==pos)
        break;
        ptr2=ptr2->link;
    }
    ptr2->link=newnode;
    ptr1->prev=newnode;
    newnode->link=ptr1;
    newnode->prev=ptr2;

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
        head = NULL;
        return;
    }
    struct node *second = head->link;
    second->prev = head->prev;
    struct node *tobedeleted = head->prev->link; //last node's link points to head node which is to be deleted
    head->prev->link = second;
    head = second;
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
        head = NULL;
        return;
    }
    //head->prev is last node
    //head->prev->prev is 2nd last node
    struct node *last = head->prev;
    head->prev->prev->link = head; //making 2nd last node's link point to head node
    head->prev = head->prev->prev;
    free(last);
}
void deleteFromAnyPosition(int pos)
{
    int t=count();
    if(t==0)
    {
        printf("No node found\n");
        return;
    }
    if(pos==1)
    {
        deleteAtHead();
        return;
    }
    if(pos>t)
    {
        printf("Not enough nodes to be deleted\n");
        return;
    }
    if(pos==t)
    {
        deleteAtEnd();
        return;
    }
    struct node *ptr1=head,*ptr2=head;
    pos--;
    int c=0;
    while(1)
    {   
        c++;
        ptr1=ptr1->link;
        if(c==pos)
        break;
        ptr2=ptr2->link;
    }
    ptr2->link=ptr1->link;
    ptr1->link->prev=ptr2;
    free(ptr1);
}
int main()
{
    insertAtPos(99,10);//value,pos
    insertAtHead(7);   // 7
    insertAtHead(8);   // 8 7
    insertAtHead(9);   // 9 8 7
    deleteFromAnyPosition(100);
    insertAtHead(100); // 1000 9 8 7
    printf("%d\n",count());
    print();

    deleteAtHead(); // 9 8 7
    deleteAtHead(); // 8 7
    deleteAtHead(); // 8
    deleteAtHead(); //Empty Linked List printed

    insertAtEnd(100); // 100
    insertAtHead(99); // 99 100

    deleteAtEnd(); // 99(100 deleted)

    print();          //99
    insertAtEnd(988); //99 988
    print();          //99 988
    printf("%d\n",count());
}
//100 9 8 7
// 99
// 99 988