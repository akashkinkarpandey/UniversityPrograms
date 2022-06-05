#include <stdio.h>
// input
//  9 8 7
//  4 5 6
//  3 2 1

// output
// 1 2 3
// 6 5 4
// 7 8 9
void bubble(int a[], int n)
{
    // sort in ascending order

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {

            if (a[j] > a[j + 1])
            {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}
int main()
{
    int r, c;
    printf("Enter rows\n");
    scanf("%d", &r);
    printf("Enter columns\n");
    scanf("%d", &c);
    int a[r][c], b[r * c];
    int k = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Enter element\n");
            scanf("%d", &a[i][j]);
            b[k++] = a[i][j];
        }
    }
    bubble(b, r * c);
    k=0;
    for (int i = 0; i < r; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < c; j++)
            {
                a[i][j]=b[k++];
                printf("%d ", a[i][j]);
            }
        }
        else
        {
            for (int j = c-1; j >=0; j--)
            {
                a[i][j]=b[k++];
            }
            for (int j = 0; j < c; j++)
            {
                printf("%d ", a[i][j]);
            }
        }
        printf("\n");
    }
}