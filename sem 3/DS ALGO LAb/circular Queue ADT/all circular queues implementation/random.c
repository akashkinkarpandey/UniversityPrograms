//queue using array
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
struct node *h;
void push(int x){
	struct node *newnode=(struct node *)(malloc(sizeof(struct node)));
	struct node *temp=h;
	newnode->data=x;
	newnode->next=NULL;
	if(h==NULL)
	{
		h=newnode;
		return;
	}
	while(temp->next!=NULL){
		temp=temp->next;
	}
	//struct node *last=temp;
	temp->next=newnode;
	//newnode->next=NULL;
}
void pop(){
	if(h==NULL){
		printf("\n\tLINKED LIST IS EMPTY\t\n");
		return;
	}
	h=h->next;
}
void print(){
	if(h==NULL){
		printf("\n\tLINKED LIST IS EMPTY\n");
		return;
	}
		struct node *temp=h;
		while(temp!=NULL){
			//temp=temp->next;
		printf("%d\t",temp->data);
		temp=temp->next;
	}
}
int main(){
	while(1){
		printf("\n\tENTER 1 TO PUSH IN THE QUEUE\n");
		printf("\n\tENTER 2 TO POP IN THE QUEUE\n");
		printf("\n\tENTER 3 TO PRINT\n");
		int n;
		printf("\n\tENTER YOUR CHOICE:\t");
		scanf("%d",&n);
		switch(n){
			case 1:
				printf("\n\t ENTER THE VALUE YOU WANT TO INSERT:\t");
				int t;
				scanf("%d",&t);
				push(t);
				break;
			case 2:
				pop();
				break;
			case 3:
				print();
				break;
			default:
				printf("\n\tEXIT\n");
				return 0;
		}
	}
	
}