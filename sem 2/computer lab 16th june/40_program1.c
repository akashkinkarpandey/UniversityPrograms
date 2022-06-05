#include<stdio.h>
int main()
{
printf("Enter a string\n");
char c[50];
gets(c);
int n=0;
while(c[n++]!='\0')
{
    if(c[n-1]>=65 &&c[n-1]<=90)
    c[n-1]=c[n-1]+32;
    else if(c[n-1]>=97 &&c[n-1]<=122)
    c[n-1]=c[n-1]-32;
}
puts(c);

}