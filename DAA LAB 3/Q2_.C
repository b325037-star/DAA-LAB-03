
#include <stdio.h>

int findDefective(int weight[], int left, int right)
{
    int n, third;
    int l1, r1, l2, r2;
    int w1 = 0, w2 = 0;
    int i;

    n = right - left + 1;


    if (n == 1)
    {
        if (weight[left] < weight[0])
            return left;

        return -1;
    }

    
    third = n / 3;

    l1 = left;
    r1 = left + third - 1;

    l2 = left + third;
    r2 = left + 2 * third - 1;

    for (i = l1; i <= r1; i++)
        w1 = w1 + weight[i];

    for (i = l2; i <= r2; i++)
        w2 = w2 + weight[i];

    /* First group is lighter */
    if (w1 < w2)
        return findDefective(weight, l1, r1);

    /* Second group is lighter */
    if (w2 < w1)
        return findDefective(weight, l2, r2);

    /* Both groups are equal */
    if (n == 3 * third)
        return findDefective(weight, l2 + third, right);

    /* Remaining coins need checking */
    return -1;
}

int main()
{
    int weight[100];
    int n, i;
    int result;

    printf("Enter number of coins: ");
    scanf("%d", &n);

    printf("Enter weights of coins:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &weight[i]);

    result = findDefective(weight, 0, n - 1);

    if (result == -1)
        printf("No defective coin found.\n");
    else
        printf("Defective coin = %d\n", result + 1);

    return 0;
}