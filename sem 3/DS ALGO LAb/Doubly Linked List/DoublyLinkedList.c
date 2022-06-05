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
        newnode->prev=NULL;
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
//print the list
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
	int c=0;
	struct node* ptr=head;
	while(ptr!=NULL){
		c++;
		ptr=ptr->link;
	}
	return c;
	//printf("total number of nodes:-%d",c);
}
//delete head of list
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
//delete end node of list
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
int main()
{
    insertAtHead(7);
    insertAtHead(8);
    insertAtHead(10);//10 8 7
    printf("%d\n",count());// 3
    insertAfterGivenPos(2,9);//10 9 8 7
    insertAtHead(6);//6 10 9 8 7
    /////->6 100 9 8 7
    insertAtEnd(10); //->6 8 7 10
    print();
    /////
    deletehead(); //-> 8 7 10
    deletehead(); //-> 7 10
    deletehead(); //-> 10
                  /////
    deleteEnd();  //-> Empty
                  /////
    insertAtHead(9);
    ////
    print();
}
