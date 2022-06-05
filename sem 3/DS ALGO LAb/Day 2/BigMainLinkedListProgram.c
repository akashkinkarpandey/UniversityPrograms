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
//6 delete head of linked list
void deletehead()
{
    if(head==NULL)
    {
        printf("Linked List is Empty\n");
        return;
    }
    struct node *ptr=head;
    printf("%d data from head node deleted\n",ptr->data);
    head=head->link;
    free(ptr);
}
//7 delete from any position of linked list
void deletefromposition(int pos)
{
    if(pos==1)
    {
    deletehead();
    return;
    }
    if(head==NULL)
    {
        printf("Linked List is Empty\n");
        return;
    }
    int c=0;
    int check=count();
    if(pos>check)
    {
        printf("Only %d nodes present\n",check);
        return;
    }
    int t=pos-2;
    struct node* ptr=head;
    while(t--)
    {
        ptr=ptr->link;
    }
    struct node *del=ptr->link;
    ptr->link=ptr->link->link;
    printf("%d data from node %d deleted\n",del->data,pos);
    free(del);
}

//8 find number of nodes smaller than given node
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

//9 insert in a sorted linked list

void insertinsortedlinkedlist(int val)
{
    int t=find(val);
    insertatpos(val,t+1);
    return;
}
//10 return position of a node
int find(int val)
{
    int c=0;
    struct node *curr=head;
    while(curr!=NULL)
    {
    c++;
    if(curr->data==val)
    return c;
    curr=curr->link;
    }
    return -1;
}
//11 delete by value
void deletebyvalue(int data)
{
    int t=find(data);
    if(t==-1)
    {
        printf("Number not found\n");
        return;
    }
    printf("%d is deleted",data);
    deletefromposition(t);
}
int main()
{
    while(1)
    {
    printf("Enter 1 to add a node at the end of the list\n ");
    printf("Enter 2 to count number of nodes present in the list\n ");
    printf("Enter 3 to add a new node at the beginning of the list\n");
    printf("Enter 4 to add a new node after the specified no. of nodes\n");
    printf("Enter 5 to display the contents of the list\n");
    printf("Enter 6 to delete head of Linked List\n");
    printf("Enter 7 to delete from any position of Linked List\n");
    printf("Enter 8 to find a value lesser than input value\n");
    printf("Enter 9 to insert value in sorted linked list\n");
    printf("Enter 10 to find a node with value equal to input value and delete the next node after it\n");
    printf("Enter 11 to delete a value\n");
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
        printf("Enter value to be inserted st beginning\n");
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
        deletehead();break;
        case 7:
        printf("Enter a position\n");
        int poss;
        scanf("%d",&poss);
        deletefromposition(poss);
        break;
        case 8:
        printf("Enter a value \n");
        int yy;
        scanf("%d",&yy);
        printf("Number of nodes smaller than %d is %d \n",yy,find(yy));
        break;
        case 9:
        printf("Enter a value to be inserted in sorted linked list\n");
        int yyy;
        scanf("%d",&yyy);
        insertinsortedlinkedlist(yyy);
        break;
        case 10:
        printf("Enter a value \n");
        int yy;
        scanf("%d",&yy);
        int found=find(yy);
        if(found==-1)
        printf("Not found in Linked List\n");
        else
        {
        printf("node having %d found at pos %d\n",yy,found);
        deletefromposition(found+1);
        printf("After deletion Linked List is\n");
        print();
        }
        break;
        case 11:
        printf("Enter a value to be deleted \n");
        int oo;
        scanf("%d",&oo);
        deletebyvalue(oo);
        break;
        default:
        printf("Exiting program\n");
        return 0;
    }
    }

}