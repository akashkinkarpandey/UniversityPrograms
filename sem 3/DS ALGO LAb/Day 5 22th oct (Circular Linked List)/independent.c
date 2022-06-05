//circular linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
struct node *start=NULL;
void insertAtEnd(int val)
{
    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->data=val;
    new->link=NULL;
    if(start==NULL)
    {
        start=new;
        start->link=start;
        return;
    }
    struct node *help=start;
    while(help->link!=start)
    {
        help=help->link;
    }
    help->link=new;
    new->link=start;
}
int count()
{
    if(start==NULL)
    {
        printf("Empty List zero nodes\n");
        return 0;
    }
    struct node *help=start;
    int c=0;
    do{
        help=help->link;
        c++;
    }while(help!=start);
    printf("Total nodes are %d\n",c);
    return c;
}
void print()
{
    if(start==NULL)
    {
        printf("Empty Linked List\n");
        return;
    }
    printf("Nodes are\n");
    struct node *help=start;
    do{
        printf("%d ",help->data);
        help=help->link;
    }while(help!=start);
    printf("\n");

}

void deleteHead()
{
    int t=count();
    if(t==0)
    {
        printf("No nodes to be deleted\n");
        return;
    }
    if(t==1)
    {
        struct node *ptr=start;
        free(ptr);
        printf("The only node was deleted\n");
        return;
    }
    struct node *ptr=start;
    struct node *help=start;
    while(help->link!=start)
    {
        help=help->link;
    }
    help->link=ptr->link;
    start=start->link;
    free(ptr);
}
void deleteEnd()
{
    int t=count();

    if(t==1)
    {
        struct node *ptr=start;
        free(ptr);
        printf("The only node was deleted\n");
        return;
    }
    struct node *help=start,*help2=start;
    while(1)
    {
        help=help->link;
        if(help->link==start)
        break;
        help2=help2->link;
    }
    help2->link=start;
    free(help);
}
void insertAtHead(int val)
{
    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->data=val;
    new->link=NULL;
    if(start==NULL)
    {
        start=new;
        start->link=start;
        return;
    }
    struct node *help=start;
    while(help->link!=start)
    {
        help=help->link;
    }
    help->link=new;
    new->link=start;
    start=new;
}
int main()
{
    count();
    insertAtEnd(5);
    // count();
    // // print();
    insertAtEnd(6);
    count();
    print();
    deleteEnd();
    count();
    print();
    // // print();
    // count();
    // print();
    // insertAtEnd(7);
    // insertAtEnd(8);
    // count();
    // print();

    // insertAtHead(5);
    // print();
    // count();
    // insertAtHead(6);
    // insertAtHead(7);
    // // insertAtHead(7);
    // insertAtHead(8);
    // count();
    // print();


}