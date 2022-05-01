#include <stdio.h>
#include <limits.h>
void sort(int id[], int profit[], int deadline[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; ++i)
    {
        for (j = 0; j < n - i - 1; ++j)
        {
            if (profit[j] < profit[j + 1])
            {
                profit[j] = profit[j] ^ profit[j + 1];
                profit[j + 1] = profit[j] ^ profit[j + 1];
                profit[j] = profit[j] ^ profit[j + 1];
                id[j] = id[j] ^ id[j + 1];
                id[j + 1] = id[j] ^ id[j + 1];
                id[j] = id[j] ^ id[j + 1];
                deadline[j] = deadline[j] ^ deadline[j + 1];
                deadline[j + 1] = deadline[j] ^ deadline[j + 1];
                deadline[j] = deadline[j] ^ deadline[j + 1];
            }
        }
    }
}
int main()
{
    int n;
    printf("Enter number of jobs\n");
    scanf("%d",&n);
    int id[n], profit[n], deadline[n];
    int i;
    int maxi = INT_MIN;
    for (i = 0; i < n; ++i)
    {
        printf("Enter id, profit, deadline\n");
        scanf("%d %d %d", &id[i], &profit[i], &deadline[i]);
        // maxi = max(maxi, id[i]);
        if(deadline[i]>maxi)
            maxi=deadline[i];
    }
    sort(id, profit, deadline, n);
    int max_dead[maxi + 1];
    for (i = 0; i <= maxi; i++)
        max_dead[i] = -1;
    int count = 0;
    int totalProfit = 0;
    for (i = 0; i < n; i++)
    {
        int j = deadline[i];
        while (j > 0)
        {
            if (max_dead[j] == -1)
            {
                count++;
                totalProfit += profit[i];
                max_dead[j] = id[i]; // inserting job id at that postition at which the job is being done
                break;
            }
            else
            {
                j--;
            }
        }
    }
    printf("Profit is %d\n", totalProfit);
    printf("Number of jobs done is %d\n", count);

}