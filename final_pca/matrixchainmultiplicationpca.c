#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#define n 4

int dp[10][10];
int matrixchainmultiplication(int arr[], int i, int j)
{
    if (i == j)
    {
        return 0;
    }

    int sum;
    int min = 9999999;
    for (int k = i; k < j; k++)
    {
        sum = matrixchainmultiplication(arr, i, k) + matrixchainmultiplication(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        if (sum < min)
        {
            min = sum;
        }
    }
    return min;
}

int matrixchainmultiplicationmem(int arr[], int i, int j)
{
    if (i == j)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int sum;
    int min = 99999;
    for (int k = i; k < j; k++)
    {
        sum = matrixchainmultiplicationmem(arr, i, k) + matrixchainmultiplicationmem(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        if (sum < min)
        {
            min = sum;
        }
    }

    return dp[i][j] = min;
}

int matrixchainmultiplicationtab(int arr[])
{
    int dp[n + 1][n + 1];

    for (int i = 1; i < n; i++)
    {
        dp[i][i] = 0;
    }

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum;
            int min = INT_MAX;
            for (int k = i; k < j; k++)
            {
                sum = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (sum < min)
                {
                    min = sum;
                }
            }
            dp[i][j] = min;
        }
    }
    return dp[1][n - 1];
}

int main()
{
    int arr[] = {10, 50, 20, 100};
    // int N = sizeof(arr) / sizeof(arr[0]);

    // memset(dp, -1, sizeof(dp));
    //  optimal
    printf("\nThe minimum number of multiplication is %d\n", matrixchainmultiplication(arr,1,n-1));

    // non-optimal
    int costAB = 10 * 50 * 20;
    int costABC = costAB + 10 * 20 * 100;
    printf("Number of multiplications for non-optimal order (A * B) * C is %d\n", costABC);

    return 0;
}