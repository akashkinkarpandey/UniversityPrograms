#include <stdio.h>
#include <limits.h>
// input
//  Enter number of matrices
//  4
//  Enter the matrix dimensions
//  3 2 4 2 5
// output
//  Minimum operations required are 58
//  Matrix 1 for operations-
//  0 24 28 58
//  I 0 16 36
//  I I 0 40
//  I I I 0
//  Matrix 2 for parentheses-
//  I 1 1 3
//  I I 2 3
//  I I I 3
//  I I I I
int main()
{
    int i, n, k, j;
    printf("Enter number of matrices\n");
    scanf("%d", &n);
    int a[n + 1];
    printf("Enter the matrix dimensions\n");
    for (i = 0; i <= n; i++)
        scanf("%d", &a[i]);
    int mat[n + 1][n + 1];
    int parenthesis[n + 1][n + 1];
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == j)
                mat[i][j] = 0;
            else
            {
                mat[i][j] = INT_MAX;
            }
            parenthesis[i][j] = INT_MAX; // just for sake of it
        }
    }
    j = 2;
    int t = j;
    int count = 1;
    while (count <= n - 1)
    {
        i = 1;
        for (; j <= n; i++, j++)
        {
            for (k = i; k < j; k++)
            {

                if ((mat[i][k] + mat[k + 1][j] + (a[i - 1] * a[k] * a[j])) < mat[i][j])
                {
                    mat[i][j] = mat[i][k] + mat[k + 1][j] + (a[i - 1] * a[k] * a[j]);
                    parenthesis[i][j] = k;
                }
            }
        }
        j = ++t;
        count++;
    }
    printf("Minimum operations required are %d\n", mat[1][n]);
    printf("Matrix 1 for operations-\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (mat[i][j] == INT_MAX)
                printf("I ");
            else
                printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("Matrix 2 for parentheses-\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (parenthesis[i][j] == INT_MAX)
                printf("I ");
            else
                printf("%d ", parenthesis[i][j]);
        }
        printf("\n");
    }
}