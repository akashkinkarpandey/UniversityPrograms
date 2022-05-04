#include<stdio.h>
#include<math.h>
double Discriminant(int a,int b,int c)
{
    return (b*b*1.0)-(4.0*a*c);
}
void calc(int a,int b,int c)
{
    double d=Discriminant(a,b,c);
    if(d<0)
    {
        printf("Roots are imaginary.\n");
        return;
    }
    if(d==0)
    {
        double x=(-1.0)*(b)/(2*a);
        printf("Both Roots are equal which are:\n%lf\n",(x));
        return;
    }
    if(d>0)
    {
        double x1=(1.0*((-b)+sqrt(d)))/(2*a);
        double x2=(1.0*((-b)-sqrt(d)))/(2*a);
        printf("Roots are %0.2lf , %0.2lf\n",(x1),x2);
        return;
    }

}
int main()
{
    printf("Input the coefficients of quadratic eqn\n");
    int a,b,c;
    printf("Enter a\n");
    scanf("%d",&a);
    printf("Enter b\n");
    scanf("%d",&b);
    printf("Enter c\n");
    scanf("%d",&c);
    calc(a,b,c);
    return 0;
}