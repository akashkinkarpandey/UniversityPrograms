#include <stdio.h>
void merge(int a[], int l, int h)
{
    int t[h - l + 1];
    int k = 0;
    int mid = l + (h - l) / 2;
    int i = l, j = mid + 1;
    while (i <= mid && j <= h)
    {
        if (a[i] < a[j])
            t[k++] = a[i++];
        else
            t[k++] = a[j++];
    }
    while (i <= mid)
        t[k++] = a[i++];
    while (j <= h)
        t[k++] = a[j++];
    for (int m = l; m <= h; m++)
        a[m] = t[m - l];
}
void mergesort(int a[], int l, int h)
{
    if (l >=h)
        return;
    if (l < h)
    {
        int mid = l + (h - l) / 2;
        mergesort(a, l, mid);
        mergesort(a, mid + 1, h);
        merge(a, l, h);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    mergesort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}