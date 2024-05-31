#include <stdio.h>
#include <limits.h>
#include <string.h>
#define num_cities 5

int dp[1 << num_cities][num_cities];

int cost[num_cities][num_cities] = {
    {0, 10, 15, 20, 8},
    {10, 0, 35, 25, 12},
    {15, 35, 0, 18, 30},
    {20, 25, 18, 0, 22},
    {8, 12, 30, 22, 0}};

int tspmem(int mask, int pos)
{
    if (mask == (1 << num_cities) - 1)
    {
        return cost[pos][0];
    }

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;
    for (int i = 0; i < num_cities; i++)
    {
        if ((mask & (1 << i)) == 0)
        {
            int currans = cost[pos][i] + tspmem(mask | (1 << i), i);
            if (currans < ans)
                ans = currans;
        }
    }
    return dp[mask][pos] = ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));

    int minCost = tspmem(1, 0);

    printf("The shortest tour has length %d\n", minCost);

    return 0;
}
