#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
struct node* head;
//insert_at_the_front(circular linked_list)
void insert_at_the_front(int val){
	if(head==NULL){
		struct node* newnode=(struct node*)(malloc(sizeof(struct node)));
		newnode->data=val;
		head=newnode;
		head->next=head;
		return;
	}
	
	struct node* newnode=(struct node*)(malloc(sizeof(struct node)));
	newnode->data=val;
	//newnode->next=head;
	struct node* ptr=head;
	while(ptr->next!=head){
		ptr=ptr->next;
	}
	ptr->next=newnode;
		newnode->next=head;
	head=newnode;
	
}
//insert_at_the_end
void insert_at_the_end(int val){
		if(head==NULL){
		struct node* newnode=(struct node*)(malloc(sizeof(struct node)));
		newnode->data=val;
		head=newnode;
		head->next=head;
		return;
	}
	struct node* newnode=(struct node*)(malloc(sizeof(struct node)));
	newnode->data=val;
		struct node* ptr=head;
	while(ptr->next!=head){
		ptr=ptr->next;
	}
	ptr->next=newnode;
	newnode->next=head;	
}
//delet a node at the front
void delet_at_the_front(){
	if(head==NULL){
		printf("empty list");
		return;}
			struct node* ptr=head;
				struct node* ptr1=head;
	while(ptr->next!=head){
		ptr=ptr->next;
}
ptr->next=ptr1->next;
head=head->next;
free(ptr1);
	
}
//delet a node at the end
void delet_at_the_end(){
		if(head==NULL){
		printf("empty list");
		return;}
		struct node* ptr=head;
		struct node* ptr1=head;
while(1){
	ptr=ptr->next;
	if(ptr->next==head)
	break;
	ptr1=ptr1->next;
	}
ptr1->next=head;
free(ptr);
			
	
}
//delet entire list
void delet_list(){
		struct node* ptr=head;
				struct node* ptr1=head;
	while(ptr->next!=head){
		ptr=ptr->next;
		delet_at_the_front();
}
//if(ptr==NULL)
//printf("empty list");
}

//printlist
void printlist()
{
struct node* ptr=head;
do
{
    printf("%d ",ptr->data);
    ptr=ptr->next;
}while(ptr!=head);
printf("\n");
}
int main(){
	while(1){
	printf("\tenter 0 to creat a circular linked list\n ");
	printf("\tenetr 1 to add a node at the front of the list\n");
	printf("\tenetr 2 to add a node at the end of the list\n");
	printf("\tenetr 3 to  del node at the front of the list\n");
	printf("\tenetr 4 to  del node at the end of the list\n");
	printf("\tenetr 5 to del the list\n");
	printf("\tenetr 6 to print the list\n");
	int n;
	printf("enter your choice:\t");
	scanf("%d",&n);
	switch(n){
		case 0:
			printf("press -17 to exit\n");
			while(1){
				printf("enter a value:");
				int p;
				scanf("%d",&p);
				if(p==-17)
				break;
				insert_at_the_end( p);
				
			}
			break;
		case 1:
			printf("\nenter the value:\n");
			int v;
			scanf("%d",&v);
			insert_at_the_front( v);
			break;
		case 2:
			printf("\nenter the value:\n");
			int vl;
			scanf("%d",&vl);
			insert_at_the_end( vl);
			break;
		case 3:
			delet_at_the_front();	
			break;
		case 4:
			delet_at_the_end();
			break;
		case 5:
			delet_list();
			break;
		case 6:
			 printlist();
			 break;
			
		default:
		printf("\nexit\n");
		return 0;	
	}
}
}