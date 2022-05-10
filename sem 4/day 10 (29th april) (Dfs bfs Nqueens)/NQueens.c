#include <stdio.h>
#include <stdbool.h>
//input
// Enter number of queens 4
//output
// Solution set is
// 2 4 1 3
// Solution set is
// 3 1 4 2
// Number of solution sets are 2
int c;
bool canPlace(int rowToBePlaced, int columnToBePlaced, int x[])
{
    // return true if we can place queen at rowTobePlaced,ColumnToBePlaced
    int prevrows;
    for (prevrows = 1; prevrows <= rowToBePlaced - 1; prevrows++)
    {
        // x[prevrows] is column in which prev row queens have been placed in
        if (x[prevrows] == columnToBePlaced)
            return false;
        int diff_col = x[prevrows] - columnToBePlaced;
        int diff_row = prevrows - rowToBePlaced;
        if (diff_col < 0)
            diff_col = -diff_col;//making diff_col positive
        if (diff_row < 0)
            diff_row = -diff_row;//making diff_row positive
        if (diff_row == diff_col)
            return false;
    }
    return true;
}
void NQueens(int kthrow, int n, int x[])
{
    int columnToBePlaced;
    // places kth row queen in a column i with help of loop
    for (columnToBePlaced = 1; columnToBePlaced <= n; columnToBePlaced++)
    {
        if (canPlace(kthrow, columnToBePlaced, x))
        {
            x[kthrow] = columnToBePlaced;
            if (kthrow == n)
            {
                int k = 1;
                printf("Solution set is\n");
                for (k = 1; k <= n; k++)
                {
                    printf("%d ", x[k]);
                }
                printf("\n");
                c++;
                return;
            }
            else
                NQueens(kthrow + 1, n, x);
        }
    }
}
int main()
{
    int n;
    printf("Enter number of queens ");
    scanf("%d", &n);
    int x[n + 1]; // 1-based indexing
    // x[i] denotes ith row queen is place in x[i] column
    int k = 1; // we start by placing queen in 1st row(hence k=1)
    NQueens(k, n, x);
    printf("Number of solution sets are %d\n",c);
}
