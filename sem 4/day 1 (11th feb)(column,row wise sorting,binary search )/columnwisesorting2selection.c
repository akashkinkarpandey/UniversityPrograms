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
    // selection sort
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r - 1; j++)
        {
            int mini = a[j][i], min_ind = j;
            for (int k = j + 1; k < r; k++)
            {
                if (a[k][i] < mini)
                {
                    mini = a[k][i];
                    min_ind = k;
                }
            }
            int t = a[j][i];
            a[j][i] = a[min_ind][i];
            a[min_ind][i] = t;
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