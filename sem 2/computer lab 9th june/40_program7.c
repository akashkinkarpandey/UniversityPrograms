#include<stdio.h>
int len(char k[])
{
	int c=0;
	while(k[c++]!='\0');
		
	return c-1;
}
int main()
{
char s[50];
printf("Enter string\n");
gets(s);
int i=0,j=len(s)-1;
while(i<=j)
{
    if(s[i]!=s[j])
    {
        printf("String is not palindrome\n");
        return 0;
    }
    i++;j--;
}
printf("String is  palindrome\n");
return 0;
}