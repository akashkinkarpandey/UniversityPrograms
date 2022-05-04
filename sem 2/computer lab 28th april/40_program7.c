#include<stdio.h>
#include<math.h>
int main() 
{
   int a,b,c,d;
   float x1,x2;
   scanf("%d %d %d",&a,&b,&c);
   d=(b*b)-(4*a*c);
   if(d==0)
   {
     printf("Both roots are equal.\n");
     x1=-b/(2.0*a);
     x2=x1;
     printf("First  Root Root1= %f\n",x1);
     printf("Second Root Root2= %f\n",x2);
   }
   else if(d>0)
	{
	   printf("Both roots are real and diff-2\n");
	   x1=(-b+sqrt(d))/(2.0*a);
	   x2=(-b-sqrt(d))/(2.0*a);
	   printf("First  Root Root1= %f\n",x1);
	   printf("Second Root root2= %f\n",x2);
	}
	else
	    printf("Root are imaginary;\nNo Solution. \n");
	


	

}
