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
printf("enter string\n");
gets(s);
int space=0;
for(int i=0;i<len(s);i++)
{
    if(s[i]==' ')
    space++;
}
printf("%c",s[0]);
int d=0;
for(int i=0;i<len(s);i++)
{
    if(s[i]==' ')
    d++;
    if(d==space)
    {
        for(int j=i+1;j<len(s);j++)
    printf("%c",s[j]);
    break;
}
    if(s[i]==' ' &&d<space)
    printf("%c",s[i+1]);
}
printf("\n");
}