#include<stdio.h>
int len(char k[])
{
	int c=0;
	while(k[c++]!='\0');
		
	return c-1;
}
int main()
{
char f[50];char s[50];
printf("Copying second string into first string and then printing first string\n");
printf("So first Enter first string\n");
gets(f);
printf("Enter second string\n");
gets(s);
for(int i=0;i<len(s);i++)
f[i]=s[i];
for(int i=len(s);i<len(f);i++)
f[i]=' ';
printf("After copying second string into first string, first string is:-\n");
puts(f);
}