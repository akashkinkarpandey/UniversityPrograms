#include <stdio.h>
int main() 
{
    int n, t1 = 0, t2 = 1;
    int next= t1 + t2;
    printf("Enter the number of terms: \n");
    scanf("%d", &n);
   if(n==1)
   	printf("%d\n",t1);
   if(n==2)
   	printf("%d\n %d\n",t1,t2);
   if(n>=3)
   {
    printf("Fibonacci Series\n %d\n %d\n ", t1, t2);

    for (int i = 3; i <= n; i++) 
    {
        printf("%d\n", next);
        t1 = t2;
        t2 = next;
        next = t1 + t2;
    }
   
   }

    return 0;
}