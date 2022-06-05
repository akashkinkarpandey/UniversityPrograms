#include <stdio.h>
//input
// 9 8 7 
// 4 5 6
// 3 2 1

// output
// 7 8 9
// 6 5 4
// 1 2 3
void bubble(int a[], int n, int flag)
{
    // sort in ascending order
    
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {

            if (a[j] > a[j + 1] && flag==0)
            {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
            else if (a[j] < a[j + 1] && flag==1)
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
    int a[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Enter element\n");
            scanf("%d", &a[i][j]);
        }
        if (i % 2 == 0)
            bubble(a[i], c, 0);
        else
            bubble(a[i], c, 1);
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