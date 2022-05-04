#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void printlist(struct node *head)
{
    if(head==NULL)
    {
        printf("Empty\n");
        return;
    }
    struct node *ptr=head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    return;
}
int main()
{
    int c = 1;
    struct node *newnode;
    struct node *head=NULL;
    while (c)
    {
        printf("\nenter the value-\t");
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            struct node *temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next = newnode;
        }

        printf("\ndo you want to continue?");
        printf("\npress 1 if u want to create another node");
        printf("\npress 0 if u want to print all nodes\n");
        scanf("\n%d", &c);

    }
    // printf("\ndata of node is\n");
    // temp = head;
    /*temp=head;
while(temp->next!=NULL){
	printf("\n\t%d\n",temp->data);
	temp=temp->next;
}*/
    printlist(head);
}