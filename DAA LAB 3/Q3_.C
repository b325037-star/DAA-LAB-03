
#include <stdio.h>
int minimum, maximum;
void maxmin(int arr[], int low, int high)
{
    int min1, max1;
    int mid;
    if (low == high)
    {
        minimum = arr[low];
        maximum = arr[low];
        return;
    }
    if (high == low + 1)
    {
        if (arr[low] < arr[high])
        {
            minimum = arr[low];
            maximum = arr[high];
        }
        else
        {
            minimum = arr[high];
            maximum = arr[low];
        }
        return;
    }
    mid = (low + high) / 2;
    maxmin(arr, low, mid);

    min1 = minimum;
    max1 = maximum;
    maxmin(arr, mid + 1, high);

    if (min1 < minimum)
        minimum = min1;

    if (max1 > maximum)
        maximum = max1;
}
int main()
{
    int n, i;
    int arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100)
    {
        printf("Invalid number of elements\n");
        return 0;
    }
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    maxmin(arr, 0, n - 1);

    printf("Minimum element is: %d\n", minimum);
    printf("Maximum element is: %d\n", maximum);
    return 0;
}