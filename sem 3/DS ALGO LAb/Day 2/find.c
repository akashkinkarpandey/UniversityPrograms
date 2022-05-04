#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node* link;
};
struct node* head;
//1 insert at end of list
void insertAtEnd(int val)
{
struct node* newnode=(struct node*)(malloc(sizeof(struct node)));
newnode->data=val;
newnode->link=NULL;
if(head==NULL)
{
head=newnode;return;
}
struct node *ptr=head;
while(ptr->link!=NULL)
{
    ptr=ptr->link;
}
ptr->link=newnode;
}

//2 count number of nodes present in the list
int count()
{
int c=0;
struct node *ptr=head;
while(ptr!=NULL)
{
    c++;
    ptr=ptr->link;
}
return c;
}

//3 add node at begin of list
void insertathead(int val)
{
struct node* newnode=(struct node*)(malloc(sizeof(struct node)));
newnode->data=val;
newnode->link=head;
head=newnode;
}

//4 add new node after specified number of nodes
void insertatpos(int val,int pos)
{
if(pos==1)
{
    insertathead(val);
    return;
}
int t=count();
if(pos>t)
{
    insertAtEnd(val);
    return;
}
pos--;
struct node* newnode=(struct node*)(malloc(sizeof(struct node)));
newnode->data=val;
newnode->link=NULL;
struct node *ptr=head,*ptr1=head;
int c=0;
while(1)
{
    c++;
    ptr=ptr->link;
    if(pos==c)
    break;
    ptr1=ptr1->link;
}
newnode->link=ptr;
ptr1->link=newnode;
}

//5 print the contents of list
void print()
{
struct node* ptr=head;
while(ptr!=NULL)
{
    printf("%d ",ptr->data);
    ptr=ptr->link;
}
printf("\n");
}

//find position
int find(int val)
{
    int c=0;
    struct node *curr=head;
    while(curr!=NULL)
    {
    if(curr->data<val)
    c++;
    if(curr->data>val)
    break;
    curr=curr->link;
    }
    return c;
}

int main()
{
    int yy;
    while(1)
    {
    printf("Enter 1 to add a node at the end of the list\n ");
    printf("Enter 2 to count number of nodes present in the list\n ");
    printf("Enter 3 to add a new node at the beginning of the list\n");
    printf("Enter 4 to add a new node after the specified no. of nodes\n");
    printf("Enter 5 to display the contents of the list\n");
    printf("Enter 6 to find a value lesser than input value\n");
    printf("Enter any another number to exit\n");
    int n;
    scanf(" %d",&n);
    switch(n)
    {
        case 1:
        printf("Enter a value\n");
        int v2;
        scanf("%d",&v2);
        insertAtEnd(v2);
        break;
        case 2:
        printf("Number of nodes is %d\n",count());
        break;
        case 3:
        printf("Enter value to be inserted at beginning\n");
        int v;
        scanf("%d",&v);
        insertathead(v);
        break;
        case 4:
        printf("Enter position\n");
        int pos;
        scanf("%d",&pos);
        printf("Enter value to be inserted\n");
        int v1;scanf("%d",&v1);
        insertatpos(v1,pos);
        break;
        case 5:
        if(count()==0)
        {
            printf("Empty\n");break;
        }
        printf("Contents of Linked List are\n");
        print();
        break;
        case 6:
        printf("Enter a value \n");
        scanf("%d",&yy);
        printf("Position found at %d \n",find(yy));
        break;
        default:printf("Exiting program\n");return 0;
    }
    }

}