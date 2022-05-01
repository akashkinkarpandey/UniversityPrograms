#include <stdio.h>
void sort(int arrival[], int departure[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (departure[j] > departure[j + 1])
            {
                int t = departure[j];
                departure[j] = departure[j + 1];
                departure[j + 1] = t;
                int t1 = arrival[j];
                arrival[j] = arrival[j + 1];
                arrival[j + 1] = t1;
            }
        }
    }
}
int main()
{
    printf("Enter number of arrivals or departures\n");
    int n, i;
    scanf("%d", &n);
    int arrival[n], departure[n];
    printf("Enter the %d arrival timings\n",n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arrival[i]);
    }
    printf("Enter the %d departure timings\n",n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &departure[i]);
    }
    sort(arrival, departure, n);
    int c = 1;
    int last = departure[0];
    for (i = 1; i < n; i++)
    {
        if (arrival[i] >= last)
        {
            c++;
            last = departure[i];
        }
    }
    printf("Number of activities is %d\n", c);

}