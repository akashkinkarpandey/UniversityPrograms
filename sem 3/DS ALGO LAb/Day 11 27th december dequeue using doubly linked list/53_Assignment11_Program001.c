#include<stdio.h>
#include<conio.h>
#define pf printf
#define sf scanf
struct node
{
 int info;
 struct node *next;
}*front,*temp,*rear,*ptr;
void insertr1()
{
 temp=(struct node*)malloc(sizeof(struct node));
 pf("\nEnter element: ");
 sf("%d",&temp->info);
 temp->next=NULL;
 if(front==NULL && rear==NULL)
 {
  front=rear=temp;
  return;
 }
 rear->next=temp;
 rear=rear->next;
}
void delf()
{
 if(front==NULL)
 {
  pf("\nEmpty Deque\n");
  return;
 }
 if(front==rear && front!=NULL)
 {
  ptr=front;
  front=rear=NULL;
  free(ptr);
 }
 else
 {
  ptr=front;
  front=front->next;
  free(ptr);
 }
}
void insertf1()
{
 temp=(struct node*)malloc(sizeof(struct node));
 pf("\nEnter element: ");
 sf("%d",&temp->info);
 if(front==NULL && rear==NULL)
 {
  front=rear=temp;
  temp->next=NULL;
  return;
 }
 temp->next=front;
 front=temp;
}
void delr()
{
 if(rear==front && rear==NULL)
 {
  pf("Empty DEQUE");
  getch();
  return;
 }
 else if(rear==front)
 {
  rear=front=NULL;
  free(rear);
  free(front);
 }
 else
 {
  ptr=front;
  while(ptr->next!=NULL)
  {
   temp=ptr;
   ptr=ptr->next;
  }
  temp->next=NULL;
  free(ptr);
  rear=temp;
 }
}
void show()
{
 if(front==NULL && rear==NULL)
 {
  pf("\nEmpty Deque\n");
  return;
 }
 ptr=front;
 while(ptr!=NULL)
 {
  pf("%d\t",ptr->info);
  ptr=ptr->next;
 }
}
void insertf()
{
 int ch;
 
 while(1)
 {
  
  pf("\n1. Insert at front");
  pf("\n2. Delete from front");
  pf("\n3. Delete from rear");
  pf("\n4. Show");
  pf("\n5. Exit");
  pf("\nEnter ur choice: ");
  sf("%d",&ch);
  switch (ch)
  {
   case 1: insertf1(); break;
   case 2: delf(); break;
   case 3: delr(); break;
   case 4: show(); break;
   case 5: break;
   default: pf("Invalid option");
  }
  if(ch==5)
    break;
 }
 return;
}
void insertr()
{
 int ch;
 
 while(1)
 {
  
  pf("\n1. Insert at rear");
  pf("\n2. Delete from front");
  pf("\n3. Delete from rear");
  pf("\n4. Show");
  pf("\n5. Exit");
  pf("\nEnter ur choice: ");
  sf("%d",&ch);
  switch (ch)
  {
   case 1: insertr1(); break;
   case 2: delf(); break;
   case 3: delr(); break;
   case 4: show(); break;
   case 5:  break;
   default: pf("Invalid option");
  }if(ch==5)
     break;
 }return;
}void main()
{
 int ch;
 
 while(1)
 {
  
  pf("\n1. Insert at rear");
  pf("\n2. Insert at Front");
  pf("\n3. Quit");
  pf("\nEnter ur choice: ");
  sf("%d",&ch);
  switch (ch)
  {
   case 1: insertr(); break;
   case 2: insertf(); break;
   case 3: exit(0); break;
   default: pf("Invalid option");
  }
 }
}
