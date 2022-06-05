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
    push(5);//5
    push(6);//5 6 
    push(7);//5 6 7
    printf("Size is %d\n",c);//size is 3
    pop();//5 6 (7 being topmost popped out,message printed)
    topp();//6 printed
    printf("%d\n",isEmpty());//0(false) printed as stack is not empty
    printf("Size is %d\n",c);//elements are 5,6 so size is 2
    print();//6 5 printed(from top to bottom of stack)
    pop();//5(6 bing topmost ,popped out,message printed)
    pop();//last element popped out
    push(8);
    print();//5 printed
}