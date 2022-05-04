#include<stdio.h>
int count=0;
void move(int n,char a,char b,char c)
{
//a source
//b is supporting
//c is destination
if(n>0)
{
count++;
move(n-1,a,c,b);
printf("\nmove top disk from %c to %c\n",a,c);
count++;
move(n-1,b,a,c);
}

}
int main()
{
int n;
printf("enter no of disk- ");
scanf("%d",&n);
if(n<=0)
{
    printf("Wrong Input\n");
    return 0;
}
move(n,'a','b','c');
printf("Number of moves is %d ",count/2);
}

