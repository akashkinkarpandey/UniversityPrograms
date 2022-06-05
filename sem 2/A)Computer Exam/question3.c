#include<stdio.h>
int leap(int year)
{
if (((year % 4 == 0) && (year % 100!= 0)) || (year%400 == 0))
return 1;
return 0;
}
int main()
{
for(int i=1650;i<=1750;i++)
if(leap(i)==1)
printf("%d is Leap Year\n",i);
}//end of main
