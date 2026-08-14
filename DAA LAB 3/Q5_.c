
#include <stdio.h>

#define MAX 64

void add(int A[MAX][MAX], int B[MAX][MAX],
         int C[MAX][MAX], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void sub(int A[MAX][MAX], int B[MAX][MAX],
         int C[MAX][MAX], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void multiply(int A[MAX][MAX], int B[MAX][MAX],
              int C[MAX][MAX], int n)
{
    int i, j;
    int k = n / 2;

    int A1[MAX][MAX], A2[MAX][MAX];
    int B1[MAX][MAX], B2[MAX][MAX];

    int X[MAX][MAX], Y[MAX][MAX];
    int P[MAX][MAX], Q[MAX][MAX];

    
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
        {
            A1[i][j] = A[i][j];
            A2[i][j] = A[i][j + k];

            B1[i][j] = B[i][j];
            B2[i][j] = B[i][j + k];
        }
    }

    /* X = A1 + A2 */
    add(A1, A2, X, k);

    /* Y = B1 + B2 */
    add(B1, B2, Y, k);

    /* P = (A1 + A2)(B1 + B2) */
    multiply(X, Y, P, k);

    /* X = A1 - A2 */
    sub(A1, A2, X, k);

    /* Y = B1 - B2 */
    sub(B1, B2, Y, k);

    /* Q = (A1 - A2)(B1 - B2) */
    multiply(X, Y, Q, k);

    /* Construct result */
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
        {
            C[i][j] = (P[i][j] + Q[i][j]) / 2;

            C[i][j + k] = (P[i][j] - Q[i][j]) / 2;

            C[i + k][j] = C[i][j + k];

            C[i + k][j + k] = C[i][j];
        }
    }
}

int main()
{
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int n, i, j;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter first matrix:\n");

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter second matrix:\n");

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    multiply(A, B, C, n);

    printf("Resultant matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", C[i][j]);

        printf("\n");
    }

    return 0;
}