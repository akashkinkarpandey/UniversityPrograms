#include <stdio.h>
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
void sort2(float ratio[], float profit[], float weight[], int initial[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (weight[j] > weight[j + 1])
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
    printf("Profit\n");
    for (int i = 0; i < n; i++)
        printf("%f ", profit[i]);
    printf("\n");
    printf("Weight\n");
    for (int i = 0; i < n; i++)
        printf("%f ", weight[i]);
    printf("\n");
}
void sort1(float ratio[], float profit[], float weight[], int initial[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (profit[j] < profit[j + 1])
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
    printf("Profit\n");
    for (int i = 0; i < n; i++)
        printf("%f ", profit[i]);
    printf("\n");
    printf("Weight\n");
    for (int i = 0; i < n; i++)
        printf("%f ", weight[i]);
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d ", initial[i]);
    printf("\n");
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
    printf("Enter 1 for strategy 1\n");
    printf("Enter 2 for strategy 2\n");
    printf("Enter 3 for strategy 3\n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        sort1(ratio, profit, weight, initial, n);
        knapsack(profit, weight, initial, n, capacity);
        break;
    case 2:
        sort2(ratio, profit, weight, initial, n);
        knapsack(profit, weight, initial, n, capacity);
        break;
    case 3:
        sort3(ratio, profit, weight, initial, n);
        knapsack(profit, weight, initial, n, capacity);
        break;
    default:
        printf("Wrong choice\n");
        break;
    }
}