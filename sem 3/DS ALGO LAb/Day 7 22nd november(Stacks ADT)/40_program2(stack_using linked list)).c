#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node* link;
};
struct node* top;
int c=0;
int isEmpty()
{
    return top==NULL;
    //if empty returns true
}
void push(int val)
{
c++;
//inserting at head of stack
struct node* newnode=(struct node*)(malloc(sizeof(struct node)));
newnode->data=val;
newnode->link=top;
top=newnode;
}
void pop()
{
    if(isEmpty())//zero elements in stack
    {
        printf("Nothing to be deleted\n");
        return;
    }
    c--;
    //deleting top/head of stack
    struct node *ptr=top;
    printf("data %d from head node deleted\n",ptr->data);
    top=top->link;
    free(ptr);
}
void print()
{
if(isEmpty())
{
    printf("Nothing to be printed\n");
    return;
}
struct node* ptr=top;
while(ptr!=NULL)
{
    printf("%d ",ptr->data);
    ptr=ptr->link;
}
printf("\n");
}
void topp()
{
    if(isEmpty())//zero elements in stack
    {
        printf("No top element found\n");
        return;
    }
    printf("%d\n",top->data);
}
int main()
{
    int val;
    while(1)
    {
        printf("Enter 1 for push\n");
        printf("Enter 2 for pop\n");
        printf("Enter 3 for display\n");
        printf("Enter any other value to exit\n");
        int n;
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            printf("Enter a value\n");
            scanf("%d",&val);
            push(val);
            break;
            case 2:
            pop();
            break;
            case 3:
            print();
            break;
            default:
            printf("EXITING\n");
            break;
        }
    }
}