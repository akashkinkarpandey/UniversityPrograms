#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *start = NULL;
//this function returns us the last node
struct Node* lastNode(struct Node *help,int check)
{
    if(start==NULL)
    return NULL;
    if (help == start && check!=1)//base case
        return help;
    struct node *r=lastNode(help->link,check+1);
    // lastNode(help->link,check+1);
}
//7 count recursively
int county(struct node *help,int check)
{   //check variable ensures that first node is counted
    if (help == NULL)
    {
        printf("Empty List with zero nodes\n");
        return 0;
    }
    if (help == start && check!=1)//base case
        return 0;//when we reach end node
    return (1 + county(help->link,check+1));
    //check increased so that it is no more equal to one afteer counting 1st node
}
//1 insert at beginning
void insertAtHead(int val)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = val;
    new->link = NULL;
    if (start == NULL)
    {
        start = new;
        start->link = start;
        return;
    }
    struct node *help = start;
    while (help->link != start)
    {
        help = help->link;
    }
    help->link = new;
    new->link = start;
    start = new;
}
//1 insert at head recursively
void insertAtHeady(struct node *new,int val)
{
    
    if (start == NULL)//base case
    {
        start = new;
        start->link = start;
        return;
    }
    struct node *help = start;
    while (help->link != start)
    {
        help = help->link;
    }
    help->link = new;
    new->link = start;
    start = new;
}
//2 insert at end
void insertAtEnd(int val)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = val;
    new->link = NULL;
    if (start == NULL)
    {
        start = new;
        start->link = start;
        return;
    }
    struct node *help = start;
    while (help->link != start)
    {
        help = help->link;
    }
    help->link = new;
    new->link = start;
}

//3 delete from the front
void deleteHead()
{
    int t = count();
    if (t == 0)
    {
        printf("No nodes to be deleted\n");
        return;
    }
    if (t == 1)
    {
        struct node *ptr = start;
        start = NULL;
        // free(ptr);
        printf("The only node was deleted\n");
        return;
    }
    struct node *ptr = start;
    struct node *help = start;
    while (help->link != start)
    {
        help = help->link;
    }
    help->link = ptr->link;
    start = start->link;
    free(ptr);
}

//4 delete from end
void deleteEnd()
{
    int t = count();
    if (t == 0)
    {
        printf("No nodes to be deleted\n");
        return;
    }
    if (t == 1)
    {
        struct node *ptr = start;
        start = NULL;
        // free(ptr);
        printf("The only node was deleted\n");
        return;
    }
    struct node *help = start, *help2 = start;
    while (1)
    {
        help = help->link;
        if (help->link == start)
            break;
        help2 = help2->link;
    }
    help2->link = start;
    free(help);
}

//5 delete circular list
void deleteTotal()
{
    int t = count();
    for (int i = 1; i <= t; i++)
        deleteEnd();
    return;
}

//6 display list
//recursively
void printy(struct node *help)
{
    if (start == NULL) //base case 1
    {
        printf("Empty Linked List\n");
        return;
    }
    printf("%d\n", help->data);
    if (help->link == start) //base case 2
        return;
    printy(help->link); //calling next node
}
int main()
{
    while (1)
    {
        printf("Enter 0 to create Circular Linked List\n");
        printf("Enter 1 to insert at head\n");
        printf("Enter 2 to insert at end\n");
        printf("Enter 3 to delete at front\n");
        printf("Enter 4 to delete at end\n");
        printf("Enter 5 to delete circular list\n");
        printf("Enter 6 to print entire list\n");
        printf("Enter 7 to count number of nodes\n");
        int n;
        scanf("%d", &n);
        switch (n)
        {
        case 0:
            printf("Enter -1 to exit\n");
            while (1)
            {
                printf("Enter value for Linked List\n");
                int vale;
                scanf("%d", &vale);
                if (vale == -1)
                    break;
                insertAtEnd(vale);
            }
            break;
        case 1:
            printf("Enter a value\n");
            int value;
            scanf("%d", &value);
            struct node *new = (struct node *)malloc(sizeof(struct node));
            new->data = value;
            new->link = NULL;
            // insertAtHead(value);
             insertAtHeady(new,value);
            break;
        case 2:
            printf("Enter a value\n");
            int v;
            scanf("%d", &v);
            insertAtEnd(v);
            break;
        case 3:
            deleteHead();
            break;
        case 4:
            deleteEnd();
            break;
        case 5:
            deleteTotal();
            break;
        case 6:
            // print();for iterative
            printf("If found,Nodes will be printed\n");
            printy(start); //recursive function
            break;
        case 7:
            count();                                        //iterative
            printf("Total nodes were %d\n", county(start,1)); //recursion
            break;
        default:
            printf("Exiting\n");
            return 0;
        }
    }
}