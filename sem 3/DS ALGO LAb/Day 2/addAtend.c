#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node* link;
};
//global head
struct node *head;
void print()
{
if(head==NULL)
{
    printf("Empty\n");
    return;
}
printf("Linked List elements are\n");
struct node* ptr=head;
while(ptr!=NULL)
{
    printf("%d ",ptr->data);
    ptr=ptr->link;
}
printf("\n");
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


int main()
{
    while(1)
    {
    printf("Enter 0 to print, 1 to add element, 2 to exit \n");
    int n;
    scanf("%d",&n);
    switch(n)
    {
        case 0:
        print();
        break;
        case 1:printf("Enter value to be inserted\n");
        int value;scanf("%d",&value);
        insertAtEnd(value);
        break;
        case 2:printf("Exiting\n");return 0;
        default:printf("Wrong Choice\n");return 0;
    }
    }

}