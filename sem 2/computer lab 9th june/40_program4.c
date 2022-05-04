#include<stdio.h>
int len(char k[])
{
	int c=0;
	while(k[c++]!='\0');
		
	return c-1;
}
int main()
{
printf("Enter a sentence\n");
char s[100];
gets(s);
int length=len(s);
int space=0;
for(int i=0;i<length;i++)
if(s[i]==' ')
space++;
printf("Number of words are %d\n",space+1);
}