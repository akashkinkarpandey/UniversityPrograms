//prefix evaluation(prefix to infix)
#include <stdio.h>
char a[100];
int i = -1;
//LIFO or FILO principle for stacks
void push1(int x)
{
    if (i == 99) //max size reached
    {
        printf("Overflow\n");
        return;
    }
    a[++i] = x; //insert
}
int isEmpty1()
{
    return (i == -1); //if no element has been inserted yet
}
int size1()
{
    return (i + 1);
}
void pop1()
{
    if (isEmpty1()) //underflow checking
    {
        // printf("Nothing to be deleted\n");
        return;
    }
    // printf("%d deleted\n", a[i]);
    i--; //reducing index
}
int top1()
{
    if (isEmpty1())
        return -99;
    return a[i];
}

void print1()
{
    if (isEmpty1()) //underflow checking
    {
        printf("Nothing to be printed\n");
        return;
    }
    for (int j = i; j >= 0; j--) //topmost elements printed first
        printf("%d ", a[j]);
    printf("\n");
}

int isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    return 0;
}
int isNumeric(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}
//prefix to infix
void PreFixEvaluation()
{   
    gets(a);
    int res;
    int c = 0;
    while (a[c++] != '\0');
    int len = c - 1;
    int i=0,j=len-1;
    while(i<=j)
    {
        int t=a[i];
        a[i]=a[j];
        a[j]=t;
        i++;j--;
    }
    // puts(a);
    for (i = 0; i<len; i++)
    {   
        // printf("%d %d %c\n",i,a[i],a[i]);
        if (a[i]==' ')
            continue;
        if (isNumeric(a[i]))
            push1(a[i] - '0');
        else if (isOperator(a[i]))
        {
            int f1=top1();
            pop1();
            if (f1 == -99)
            {
                printf("Wrong expression 0 exiting\n");
                return ;
            }
            int f2=top1();
            pop1();
            if (f2 == -99)
            {
                printf("Wrong expression 1 exiting\n");
                return ;
            }
            if (a[i] == '+')
                res = f1 + f2;
            else if (a[i] == '-')
                res = f1 - f2;
            else if (a[i] == '*')
                res = f1 * f2;
            else if (a[i] == '/')
                res = f1 / f2;
            else
            {
                printf("Wrong expression 2 exiting\n");
                return ;
            }
            push1(res);
        }
        else
        {
            printf("Wrong expression 3 exiting\n");
            return ;
        }
    }
    printf("result is %d\n",res);
}
int main()
{
    PreFixEvaluation();
}