#include <stdio.h>
// Enter number of arrivals or departures
// 5
// Enter the 5 arrival timings
// 1 3 5 8 9
// Enter the 5 departure timings
// 4 5 9 9 10
// Number of activities done are 3
// The activity numbers that were done are
// 1 3 5

// Enter number of arrivals or departures
// 5
// Enter the 5 arrival timings
// 1 3 5 7 9
// Enter the 5 departure timings
// 3 5 7 9 10
// Number of activities done are 5
// The activity numbers that were done are
// 1 2 3 4 5
void sort(int arrival[], int departure[],int id[], int n)
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
                int t2=id[j];
                id[j]=id[j+1];
                id[j+1]=t2;
            }
        }
    }
}
int main()
{
    printf("Enter number of arrivals or departures\n");
    int n, i;
    scanf("%d", &n);
    int arrival[n], departure[n],id[n];
    printf("Enter the %d arrival timings\n",n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arrival[i]);
        id[i]=i+1;
    }
    printf("Enter the %d departure timings\n",n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &departure[i]);
    }
    sort(arrival, departure,id, n);
    int c = 1;
    int last = departure[0];
    int activities_done[n];
    activities_done[0]=id[0];
    for (i = 1; i < n; i++)
    {
        if (arrival[i] >= last)
        {
            activities_done[c]=id[i];
            c++;
            last = departure[i];
        }
    }
    printf("Number of activities done are %d\n", c);
    printf("The activity numbers that were done are\n");
    for(int i=0;i<c;i++)
    printf("%d ",activities_done[i]);
}
