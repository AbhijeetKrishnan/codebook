#include <stdio.h>
#include <stdlib.h>
void merge_self(int A[], int low, int mid, int high, int C[])
{
    int i, j, k;
    i = low, j = mid + 1, k = low;
    while ((i <= mid) && (j <= high))
    {
        if (A[i] < A[j])
        {
            C[k++] = A[i++];
        }
        else
        {
            C[k++] = A[j++];
        }
    }
    if (i <= mid)
    {
        while (i <= mid)
        {
            C[k++] = A[i++];
        }
    }
    else
    {
        while (j <= high)
        {
            C[k++] = A[j++];
        }
    }
    for (i = low; i <= high; i++)
    {
        A[i] = C[i];
    }
}
void merge_sort(int A[], int lo, int hi, int tmp[])
{
    int mid;
    if (lo < hi)
    {
        mid = (lo + hi) / 2;
        merge_sort(A, lo, mid, tmp);
        merge_sort(A, mid + 1, hi, tmp);
        merge_self(A, lo, mid, hi, tmp);
    }
}
int main()
{
    int t;
    int *A, *tmp;
    int i;
    scanf("%d", &t);
    A = (int*)malloc(t * sizeof(int));
    tmp = (int*)malloc(t * sizeof(int));
    for (i = 0; i < t; i++)
    {
        scanf("%d", &A[i]);
    }
    merge_sort(A, 0, t - 1, tmp);
    for (i = 0; i < t; i++)
    {
        printf("%d\n", A[i]);
    }
    return 0;
}