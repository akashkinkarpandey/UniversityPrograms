#include <stdio.h>
char a[100];
int i = -1;
char b[100];
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
    // printf("%d deleted\n",a[i]);
    i--; //reducing index
}
int top1()
{
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
int prec(char s)
{
    if (s == '^')
        return 3;
    else if (s == '*' || s == '/')
        return 2;
    else if (s == '+' || s == '-')
        return 1;
}
void InfixtoPostfix()
{
    printf("Enter a correct Infix Expression\n");
    gets(a);
    int c = 0, f = 0;
    while (a[c++] != '\0');
    int len = c - 1;
    for (int i = 0; i < len; i++)
    {
        char t = a[i];
        if(t==' ')
        continue;
        if ((t >= 'a' && t <= 'z') || (t >= 'A' && t <= 'Z'))
            b[f++] = t;
        else if (t == '(')
        {   
            push1(t);
            b[f++] = t;
        }
        else if (t == ')')
        {
            while (isEmpty1() == 0 && top1() != '(')
            {
                b[f++] = top1();
                pop1();
            }
            if (isEmpty1() == 0)
            {   
                // b[f++]=top1();
                pop1();
            }
            b[f++]=t;
        }
        else
        {
            while (isEmpty1() == 0 && prec(top1()) >= prec(t) && top1()!='(')
            {
                b[f++] = top1();
                pop1();
            }
            push1(t);
        }
    }
    while (isEmpty1() == 0)
    {
        b[f++] = top1();
        pop1();
    }
    puts(b);
}
int main()
{
    InfixtoPostfix();
}