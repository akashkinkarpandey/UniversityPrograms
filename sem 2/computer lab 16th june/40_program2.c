#include<stdio.h>
int len(char k[])
{
	int c=0;
	while(k[c++]!='\0');
		
	return c-1;
}
int main()
{
printf("enter pattern that needs to be searched in the string\n");
char s[50];
gets(s);
printf("enter string in which we will search that pattern\n");
char a[50];
gets(a);
for(int i=0;i<=len(a)-len(s);i++)
{
    int fl=0,c=i;
    for(int j=0;j<len(s);j++)
    {
     if(s[j]!=a[c])
     {
     fl=1;break;
     }
     c++;
    }
    if(fl==0)
    {
        printf("PATTERN found\n");
        return 0;
    }
}
printf("PATTERN not found\n"); return 0;
}