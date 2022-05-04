#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root;
void insert(int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    if (root == NULL)
    {
        printf("%d inserted\n", val);
        root = temp;
        return;
    }
    struct node *ptr = root;
    while(1)
    {
        if (ptr->data < val)
        {
            if (ptr->right != NULL)
                ptr = ptr->right;
            else
            {
                ptr->right = temp;
                break;
            }
        }
        else
        {
            if (ptr->left != NULL)
                ptr = ptr->left;
            else
            {
                ptr->left = temp;
                break;
            }
        }
    }
    printf("%d inserted\n", val);
}
void inorder(struct node *ptr)
{
    if (ptr == NULL)
        return;
    inorder(ptr->left);
    printf("%d ", ptr->data);
    inorder(ptr->right);
}
void preorder(struct node *ptr)
{
    if (ptr == NULL)
        return;
    printf("%d ", ptr->data);
    preorder(ptr->left);
    preorder(ptr->right);
}
void postorder(struct node *ptr)
{
    if (ptr == NULL)
        return;
    postorder(ptr->left);
    postorder(ptr->right);
    printf("%d ", ptr->data);
}
int main()
{
    while (1)
    {
        printf("Enter 1 to insert in binary search tree\n");
        printf("Enter 2 for pre order traversal\n");
        printf("Enter 3 for in order traversal\n");
        printf("Enter 4 for post order traversal\n");
        printf("Enter any other number to exit\n");
        int choice;
        scanf("%d", &choice);
        int val;
        switch (choice)
        {
        case 1:
            printf("enter a value ");
            scanf("%d", &val);
            insert(val);
            break;
        case 2:
            if (root == NULL)
            {
                printf("Nothing to print");
            }
            else
            {   
                preorder(root);
            }
            printf("\n");
            break;

        case 3:
            if (root == NULL)
            {
                printf("Nothing to print");
            }
            else
            {   
                inorder(root);
            }
            printf("\n");
            break;
        case 4:
            if (root == NULL)
            {
                printf("Nothing to print");
            }
            else
            {   
                postorder(root);
            }
            printf("\n");
            break;
        default:
            printf("Exiting\n");
            return 0;
        }

    }
}
