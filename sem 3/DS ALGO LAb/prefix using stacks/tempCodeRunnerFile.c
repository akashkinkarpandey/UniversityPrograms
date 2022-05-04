    // for (i = 0; i<len; i++)
    // {   
    //     printf("%d %d %c\n",i,a[i],a[i]);
    //     if (a[i]==' ')
    //         continue;
    //     if (isNumeric(a[i]))
    //         push1(a[i] - '0');
    //     else if (isOperator(a[i]))
    //     {
    //         int f1=top1();
    //         pop1();
    //         // if (f1 == -99)
    //         // {
    //         //     printf("Wrong expression 0 exiting\n");
    //         //     return ;
    //         // }
    //         int f2=top1();
    //         pop1();
    //         // if (f2 == -99)
    //         // {
    //         //     printf("Wrong expression 1 exiting\n");
    //         //     return ;
    //         // }
    //         if (a[i] == '+')
    //             res = f1 + f2;
    //         else if (a[i] == '-')
    //             res = f1 - f2;
    //         else if (a[i] == '*')
    //             res = f1 * f2;
    //         else if (a[i] == '/')
    //             res = f2 / f1;
    //         else
    //         {
    //             printf("Wrong expression 2 exiting\n");
    //             return ;
    //         }
    //         push1(res);
    //     }
    //     else
    //     {
    //         printf("Wrong expression 3 exiting\n");
    //         return ;
    //     }
    // }
    // printf("%d\n",res);