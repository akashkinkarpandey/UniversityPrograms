#include<stdio.h>
int len(char k[])
{
	int c=0;
	while(k[c++]!='\0');
		
	return c-1;
}
int main()
{
printf("Enter a string\n");
char s[100];
gets(s);
int length=len(s);
int vowel=0,consonant=0;
for(int i=0;i<length;i++)
{
    if((s[i]>=65 &&s[i]<=90) ||(s[i]>=97 &&s[i]<=122))
    { 
     char ch=s[i];
     switch(ch)
    {
        case 'a':
        case 'A':
        case 'E':
        case 'e':
        case  'I':
        case  'i':
        case  'o':
        case  'O':
        case 'U':
        case  'u':vowel++;break;
        default:consonant++;break;
    }
    }

}
printf("Number of vowels are %d\n",vowel);
printf("Number of consonants are %d\n",consonant);

}