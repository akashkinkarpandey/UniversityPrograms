#include <stdio.h>
int main()
{
    int r, c;
    printf("Enter rows\n");
    scanf("%d", &r);
    printf("Enter columns\n");
    scanf("%d", &c);
    int a[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Enter element\n");
            scanf("%d", &a[i][j]);
        }
    }
    // bubble sort
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r - 1; j++)
        {
            for (int k = 0; k < r - j - 1; k++)
            {
                if (a[k][i] > a[k + 1][i])
                {
                    int t = a[k][i];
                    a[k][i] = a[k + 1][i];
                    a[k + 1][i] = t;
                }
            }
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}