#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *h;
void end()
{

    struct node *new_node, *temp;
    temp = h;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("\nenter the data u want to insert at the end:\t");
    int t;
    scanf("%d", &t);
    new_node->data = t;
    new_node->next = NULL;
    if(h==NULL)
    {
        h=new_node;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}
int count()
{
    int c = 0;
    if (h == 0)
    {
        printf("linked list is empty\n");
        return 0;
    }
    struct node *temp = NULL;
    temp = h;
    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }
    return c;
}
void front()
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("\nenter the data u want to insert at the end:\t");
    int t;
    scanf("%d", &t);
    new_node->data = t;
    new_node->next = h;
    h = new_node;
}
void position()
{
    int p;
    printf("\nenter the position you want to insert:\t");
    scanf("%d", &p);
    if (p == 1)
    {
        front();
        return;
    }
    int t = count();
    if (p > t)
    {
        end();
        return;
    }
    p--;
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("\nenter the data u want to insert at the end:\t");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    struct node *fi = h, *se = h;
    int c = 0;
    while (1)
    {
        c++;
        fi = fi->next;
        if (p == c)
            break;
        se = se->next;
    }
    new_node->next = fi;
    se->next = new_node;
}
void printlist()
{

    if (h == NULL)
    {
        printf("\nlinked list is empty\n");
        return;
    }
    else
    {

        while (h != NULL)
        {
            printf("%d ", h->data);
            h = h->next;
        }
    }
    printf("\n");
}

int main()
{

    while (1)
    {

        printf("Enter 1 to add a node at the end of the list\n ");
        printf("Enter 2 to count number of nodes\n ");
        printf("Enter 3 to add a new node at the front of the list\n");
        printf("Enter 4 to add a new node after the specified no. of nodes\n");
        printf("Enter 5 to display the contents of the list\n");
        printf("Enter anything else to exit\n");
        int n;
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            end();
            break;
        case 2:
            printf("Number of nodes is %d\n", count());
            break;
        case 3:
            front();
            break;
        case 4:
            position();
            break;
        case 5:
            if (count() == 0)
            {
                printf("Empty\n");
                break;
            }
            printf("Contents of Linked List are\n");
            printlist();
            break;
        default:
            printf("Exiting\n");
            return 0;
        }
    }
}