#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

int dp[100][100];

int knapsack(int weight[], int profit[], int i, int cap)
{
	if (i == 0)
	{
		if (weight[0] <= cap)
			return profit[0];
		else
		{
			return 0;
		}
	}
	int include = 0;
	if (weight[i] <= cap)
	{
		include = profit[i] + knapsack(weight, profit, i - 1, cap - weight[i]);
	}

	int exclude = knapsack(weight, profit, i - 1, cap);

	if (include > exclude)
		return include;
	else
		return exclude;
}

int knapsackmem(int weight[], int profit[], int i, int cap)
{
	if (i == 0)
	{
		if (weight[0] <= cap)
			return profit[0];
		else
		{
			return 0;
		}
	}
	if (dp[i][cap] != -1)
		return dp[i][cap];

	int include = 0;
	if (weight[i] <= cap)
	{
		include = profit[i] + knapsack(weight, profit, i - 1, cap - weight[i]);
	}

	int exclude = knapsack(weight, profit, i - 1, cap);

	if (include > exclude)
		return dp[i][cap] = include;
	else
		return dp[i][cap] = exclude;
}

int main()
{
	int profit[] = {1, 2, 3};
	int weight[] = {4, 5, 1};
	int capacity = 4;

	memset(dp, -1, sizeof(dp));
	int n = sizeof(profit) / sizeof(profit[0]);
	printf("The maximum profit is :- %d", knapsackmem(weight, profit, n - 1, capacity));
	return 0;
}