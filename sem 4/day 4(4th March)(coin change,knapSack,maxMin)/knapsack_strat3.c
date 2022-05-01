#include <stdio.h>
// strategy 3
// sort according to decreasing (profit/weight) ratio

// Input

// Enter size
// 7
// Enter capacity
// 15
// Enter profit and weight
// 10 2
// Enter profit and weight
// 5 3
// Enter profit and weight
// 15 5
// Enter profit and weight
// 7 7
// Enter profit and weight
// 6 1
// Enter profit and weight
// 18 4
// Enter profit and weight
// 3 1

//Output

// Total profit is 55.333332
// Profit 6.000000 Weight 1.000000 Quantity 1.000000
// Profit 10.000000 Weight 2.000000 Quantity 1.000000
// Profit 18.000000 Weight 4.000000 Quantity 1.000000
// Profit 15.000000 Weight 5.000000 Quantity 1.000000
// Profit 3.000000 Weight 1.000000 Quantity 1.000000
// Profit 5.000000 Weight 3.000000 Quantity 0.666667
// Profit 7.000000 Weight 7.000000 Quantity 0.000000

// x[i] accoding to original array is
// 1.000000 0.666667 1.000000 0.000000 1.000000 1.000000 1.000000
void knapsack(float profit[], float weight[], int initial[], int n, int capacity)
{
    float curWeight = 0.0;
    float curProfit = 0.0;
    double x[n];
    double x1[n];
    for (int i = 0; i < n; i++)
    {
        x[i] = 0.0;
        x1[i] = 0.0;
    }
    for (int i = 0; i < n; i++)
    {
        if (curWeight + weight[i] <= capacity)
        {
            curWeight += weight[i];
            curProfit += profit[i];
            x[i] = 1;
        }
        else
        {
            float remaining = capacity - curWeight;
            x[i] = remaining / weight[i];
            curProfit += ((profit[i] / weight[i]) * (remaining));
            break;
        }
    }
    printf("\n");
    printf("Total profit is %f\n", curProfit);
    for (int i = 0; i < n; i++)
    {
        printf("Profit %f Weight %f Quantity %f\n", profit[i], weight[i], x[i]);
    }
    for (int i = 0; i < n; i++)
    {
        x1[initial[i] - 1] = x[i];
    }
    printf("\n");
    printf("x[i] accoding to original array is\n");
    for (int i = 0; i < n; i++)
        printf("%f ", x1[i]);
    printf("\n");
}
void sort3(float ratio[], float profit[], float weight[],int initial[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (ratio[j] < ratio[j + 1])
            {
                float temp = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = temp;
                float temp1 = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp1;
                float temp2 = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp2;
                int t = initial[j];
                initial[j] = initial[j + 1];
                initial[j + 1] = t;
            }
        }
    }
}
int main()
{
    int n;
    printf("Enter size of array\n");
    scanf("%d", &n);
    int capacity;
    printf("Enter capacity\n");
    scanf("%d", &capacity);
    float profit[n], weight[n], ratio[n];
    int initial[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter profit and weight\n");
        scanf("%f %f", &profit[i], &weight[i]);
        ratio[i] = profit[i] / weight[i];
        initial[i] = i + 1;
    }
    sort3(ratio, profit, weight, initial, n);
    knapsack(profit, weight, initial, n, capacity);
}