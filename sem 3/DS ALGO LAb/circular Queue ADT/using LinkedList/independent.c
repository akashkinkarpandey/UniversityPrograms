#include <stdio.h>
#include <stdlib.h>
//FIFO
int size1;
int c1=0;
struct node
{
    int data;
    struct node *link;
};
struct node *front1;
struct node *rear1;
int isEmpty()
{
    return (front1 == NULL && rear1 == NULL);
    // returns 1 if empty
}
void insert(int val)
{
    
    if(c1==size1)
    {
        printf("Queue is full\n");
        return;
    }
    struct node *newnode = (struct node *)(malloc(sizeof(struct node)));
    newnode->data = val;
    newnode->link = NULL;
    c1++;
    if (isEmpty()) //when queue is empty
    {
        front1 = rear1 = newnode;
        return;
    }
    rear1->link = newnode; //insert at end
    rear1 = newnode;
}
void pop()
{
    if (front1 == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }
    c1--;
    if (front1->link == NULL) //if only one node was there
    {
        front1 = rear1 = NULL; //make the list empty
        return;
    }
    struct node *tobedeleted = front1;
    front1 = front1->link;
    free(tobedeleted);
}
void top()
{
    if (front1 == NULL)//underflow
    {
        printf("Empty queue\n");
        return;
    }
    printf("%d\n", front1->data);
}
void print()
{
    if(front1==NULL)
    {
        printf("Nothing to be printed\n");
        return;
    }
    struct node *ptr=front1;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    printf("\n");
}
int main()
{
    printf("Enter size of queue\n");
    scanf("%d",&size1);
    insert(7);
    insert(6);
    insert(8);
    print();
    pop();
    top();
    pop();
    top();
    pop();
    print();
    top();
    insert(7);
    insert(6);
    insert(8);
    print();
    pop();
    top();
    pop();
    top();
    pop();
    print();
    top();
    // pop();
    // top();
    // pop();
}
