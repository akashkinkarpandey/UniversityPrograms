//TREE->data structure in hierarchical manner
#include<stdio.h>
#include<stddef.h>//cause NULL is buli-in consatnt
#include<stdlib.h>
//creating a node
struct node{
	int data;
	struct node *left; //pointing to the left children
	struct node *right;//pointing to the left children
};
//struct node *root=NULL; //root of the tree
void Preorder(struct node *root)
{
	// base condition for recursion
	// if tree is empty, return and exit
	if(root==NULL) {
		//printf("\n\tNO NODE IS PRESENT\n");
	return;}
	printf("%d ",root->data); // Print data
	Preorder(root->left);     // Visit left subtree
	Preorder(root->right);    // Visit right subtree
}
// Function to Insert Node 
struct node* Insert(struct node *root) {
	int data;
	if(root == NULL) {
		root = (struct node*)(malloc(sizeof(struct node)));
		
		scanf("%d",&data);
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
		root->left = Insert(root->left);
	else 
		root->right = Insert(root->right);
	return root;
}
int main(){
	struct node* root = NULL;
	root = Insert(root); root = Insert(root);
	root = Insert(root); root = Insert(root); 
	root = Insert(root); root = Insert(root);
	//Print Nodes in Preorder. 
	printf("Preorder: ");
	Preorder(root);

}