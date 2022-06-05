#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node* link;
};
struct node* head;
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
void print()
{
struct node* ptr=head;
while(ptr!=NULL)
{
    printf("%d",ptr->data);
    ptr=ptr->link;
}
printf("\n");
}
void insertathead(int val)
{
struct node* newnode=(struct node*)(malloc(sizeof(struct node)));
newnode->data=val;
newnode->link=head;
head=newnode;
}
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
void insertatpos(int val,int pos)
{
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

int main()
{
    // struct node* head;
    // head=(struct node*)(malloc(sizeof(struct node)));
    // // insertAtEnd(head,4);
    // // head->data=5;
    // head->data=6;
    // head->link=NULL;
    // head->link->link=NULL;

    printf("%d\n",count());
    insertAtEnd(5);
    printf("%d\n",count());
    insertAtEnd(7);
    printf("%d\n",count());
    print();
     printf("%d\n",count());
    insertAtEnd(5);
    printf("%d\n",count());
    insertAtEnd(7);
    insertathead(2);
    printf("%d\n",count());
    insertatpos(6,3);
    print();
    insertathead(2);
    print();


}