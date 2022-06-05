//dequeue(double ended queue):-we can insert and delet from both ends of the queue.
//both qualities of stack and queue
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *prev;
	struct node *next;
};
struct node *head=NULL;

int count(){
int c=0;
	if(head==NULL){
		// printf("\n\tempty list");
		return 0;
	}
struct node *ptr=head;
while(ptr!=NULL)
{
	c++;
	ptr=ptr->next;
	}	
return c;
}
//insert at the end
void insert_rear(int val){
struct node *newnode=(struct node *)(malloc(sizeof(struct node)));
struct node *ptr=head;
newnode->data=val;
newnode->next=NULL;
if(head==NULL){
	newnode->prev=NULL;
	head=newnode;
	return;
}
while(ptr->next!=NULL){
ptr=ptr->next;	
}
ptr->next=newnode;
newnode->prev=ptr;
//newnode->next=NULL;//major mistake	
}
//del front
void del_front(){
	if(head==NULL){
		printf("\n\tempty list");
		return;
	}
	else if(head->next==NULL){
	 printf("data %d from head node deleted\n", head->data);
		head=NULL;
		return;
	}
	struct node *ptr1=head;
	struct node *ptr2=head->next;
	 printf("data %d from head node deleted\n", head->data);
	head=ptr2;
	ptr2->prev=NULL;
	free(ptr1);
}
//del at end
void del_end(){
	if(head==NULL){
		printf("\n\tempty list");
		return;
	}
	else if(head->next==NULL){
		printf("data %d from head node deleted\n", head->data);
		head=NULL;
		return;
	}
	struct node *ptr=head;
	
	while(ptr->next->next!=NULL){
		ptr=ptr->next;
	}
	struct node* last=ptr->next;
	printf("data %d from head node deleted\n", last->data);
	ptr->next=NULL;
	free(last);
	}
void print(){
struct node *ptr=head;
while(ptr!=NULL){
	printf("\t%d->",ptr->data);
	ptr=ptr->next;
}
   printf("\n");
}
int main(){
	while(1){
		printf("\n\tenter 1 for insert at the raer:\t");
		printf("\n\tenter 2 to count:\t");
		printf("\n\tenter 3 to print:\t");
		printf("\n\tenter 4 to del the front:\t");
		printf("\n\tenter 5 to del the end:\t");
	printf("\nenter your choice:\t");
	int n;
	scanf("%d",&n);	
	switch(n){
		case 1:
			printf("\n\tenter the value you want to insert:\t");
			int t;
			scanf("%d",&t);
			insert_rear(t);
			break;
		case 2:
			printf("\n\ttotal number of nodes are:\t");
			int c=count();
			printf("%d\n",c);
			break;
		case 3:
				if(head==NULL){
		        printf("\n\tempty list");
				// return ;
				}
			print();
			break;
		case 4:
			del_front();
			break;
		case 5:
			del_end();
			break;
	default:
		printf("\n\texit\n");
        return 0;
	}
	}
}