#include<stdio.h>
struct Data{
int acc;
char name[50];
int balance;
int opendate;
};
int main()
{
int n;
printf("Enter number of customers\n");
scanf("%d",&n);
struct Data a[n];
for(int i=0;i<n;i++)
{
printf("Enter %d customers details\n",(i+1));
printf("Enter account number\n");
scanf("%d",&(a[i].acc));
printf("Enter name\n");
scanf(" %[^\n]",a[i].name);
printf("Enter balance\n");
scanf("%d",&(a[i].balance));
printf("Enter account opening date\n");
scanf("%d",&(a[i].opendate));
}
printf("Details of customers with accounts more than 5 years old are printed\n");
for(int i=0;i<n;i++)
{
if(2021-(a[i].opendate)>=5)
{
printf("Account number is ");
printf("%d\n",(a[i].acc));
printf("name is ");
puts(a[i].name);
printf("balance is ");
printf("%d\n",(a[i].balance));
printf("account opening date is ");
printf("%d\n",(a[i].opendate));
}
}
}