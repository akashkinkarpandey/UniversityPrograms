#include<stdio.h>
#include<math.h>
double eq(double x)
{
    return (x*x*x) - (x) - 2;
}
void bi(double a, double b)
{
     if (eq(a) * eq(b) >= 0)
    {
        printf("Wrong a and b value\n");
        return ;
    } 
    double mid=0.0;int d=0;
    while (fabs(b-a) >= 0.00001)
    {
       d++;
       mid = (a+b)/2;
       if (eq(mid) == 0.0)
        break;
        else if (eq(mid)*eq(a) < 0)
            b = mid; 
        else
            a = mid;
    }
    printf("The value of root is :%lf \n" ,mid);
    printf("Loop Runs for %d times\n",d);
    printf("The value at root is: %lf \n" ,fabs(eq(mid)));
}
int main()
{
    double a, b;
    printf("Enter a and b\n");
    scanf("%lf %lf",&a,&b);
    
    bi(a, b);
    return 0;
}