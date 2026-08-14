
#include <stdio.h>

int bcount = 0;
int tcount = 0;

int binarySearch(int A[], int n, int x)
{
    int low = 0, high = n - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        bcount++;

        if (A[mid] == x)
            return mid;

        if (x < A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int ternarySearch(int A[], int n, int x)
{
    int low = 0, high = n - 1;
    int mid1, mid2;

    while (low <= high)
    {
        mid1 = low + (high - low) / 3;
        mid2 = high - (high - low) / 3;

        tcount++;

        if (A[mid1] == x)
            return mid1;

        tcount++;

        if (A[mid2] == x)
            return mid2;

        if (x < A[mid1])
            high = mid1 - 1;

        else if (x > A[mid2])
            low = mid2 + 1;

        else
        {
            low = mid1 + 1;
            high = mid2 - 1;
        }
    }

    return -1;
}

int main()
{
    int A[100], n, x;
    int i;
    int bpos, tpos;

    printf("Enter size of sorted array: ");
    scanf("%d", &n);

    printf("Enter sorted elements:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    printf("Enter element to search: ");
    scanf("%d", &x);

    bpos = binarySearch(A, n, x);
    tpos = ternarySearch(A, n, x);

    if (bpos != -1)
        printf("\nBinary Search: Element found at position %d", bpos + 1);
    else
        printf("\nBinary Search: Element not found");

    printf("\nBinary Search comparisons = %d", bcount);

    if (tpos != -1)
        printf("\nTernary Search: Element found at position %d", tpos + 1);
    else
        printf("\nTernary Search: Element not found");

    printf("\nTernary Search comparisons = %d", tcount);

    if (bcount < tcount)
        printf("\n\nBinary Search is better.");
    else if (tcount < bcount)
        printf("\n\nTernary Search is better.");
    else
        printf("\n\nBoth are equal.");

    return 0;
}