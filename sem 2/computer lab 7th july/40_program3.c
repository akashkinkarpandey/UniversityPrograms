#include<stdio.h>
struct Student
{
    char name[50];
    int roll;
    char dept[50];
    char course[50];
    int YearJoining;
};
int main()
{
int n;
printf("Enter number of students\n");
scanf("%d",&n);
struct Student a[n];//array of structures
//taking of input
for(int i=0;i<n;i++)
{
printf("Enter %d student's details\n",(i+1));
printf("Enter name\n");
scanf(" %[^\n]",a[i].name);
printf("Enter roll\n");
scanf("%d",&(a[i].roll));
printf("Enter department\n");
scanf(" %[^\n]",a[i].dept);
printf("Enter course\n");
scanf(" %[^\n]",a[i].course);
printf("Enter year of joining\n");
scanf("%d",&(a[i].YearJoining));
}
//printing
for(int i=0;i<n;i++)
{
printf("%d student's details are\n",(i+1));
printf("Name is ");
puts(a[i].name);
printf("Roll is %d\n",(a[i].roll));
printf("Department is ");
puts(a[i].dept);
printf("Course is ");
puts(a[i].course);
printf("Year of joining is %d\n",(a[i].YearJoining));
}

}