#include<stdio.h>
int len(char k[])
{
	int c=0;
	while(k[c++]!='\0');		
	return c-1;
}
int main()
{
char f[50];char s[50];char m[100];
printf("Enter first string\n");
gets(f);
printf("Enter second string\n");
gets(s);
int c=0;
for(int i=0;i<len(f);i++)
m[c++]=f[i];
for(int i=0;i<len(s);i++)
m[c++]=s[i];
printf("After concatenation string is\n");
for(int i=0;i<len(m);i++)
printf("%c",m[i]);
printf("\n");
}
