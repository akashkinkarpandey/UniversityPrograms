#include <stdio.h>
void merge(int arr[], int start, int mid, int end)
{
    int temp[end - start + 1];
    int i = start, j = mid + 1, k = 0;
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= end)
    {
        temp[k++] = arr[j++];
    }
    for (i = start; i <= end; ++i)
    {
        arr[i] = temp[i - start];
    }
}
void mergeSort(int *arr, int start, int end)
{
    if(start>=end)
    return;
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}
int main()
{
    int n;
    printf("Enter size of array\n");
    scanf("%d", &n);
    int a[n];
    printf("Enter array elements\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter 1 for bubble sort\n");
    printf("Enter 2 for selection sort\n");
    printf("Enter 3 for insertion sort\n");
    printf("Enter 4 for merge sort\n");
    int n1;
    scanf("%d", &n1);
    switch (n1)
    {
    case 1:
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
        printf("Array after sorting is\n");
        for (int i = 0; i < n; i++)
            printf("%d\n", a[i]);

        break;
    case 2:
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[j] < a[i])
                {
                    int t = a[j];
                    a[j] = a[i];
                    a[i] = t;
                }
            }
        }
        printf("Array after sorting is\n");
        for (int i = 0; i < n; i++)
            printf("%d\n", a[i]);
        break;
    case 3:
        for (int i = 1; i < n; i++)
        {
            int current = a[i];
            int j = i - 1;
            while (a[j] > current && j >= 0)
            {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = current;
        }
        printf("Array after sorting is\n");
        for (int i = 0; i < n; i++)
            printf("%d\n", a[i]); //printing array elements

        break;
    case 4:
        mergeSort(a, 0, n - 1);
        printf("Array after sorting is\n");
        for (int i = 0; i < n; i++)
            printf("%d\n", a[i]); //printing array elements
        break;
    default:printf("Wrong Input\n");
    }
}
