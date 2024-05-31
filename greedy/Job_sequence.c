#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Job
{
	char id;
	int deadline;
	int profit;
} Job;

int cmp(const void *a, const void *b)
{
	Job *temp1 = (Job *)a;
	Job *temp2 = (Job *)b;

	return (temp2->profit - temp1->profit);
}

void jobsequence(Job arr[], int n)
{

	qsort(arr, n, sizeof(Job), cmp);

	int maxi = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i].deadline > maxi)
		{
			maxi = arr[i].deadline;
		}
	}

	int result[maxi + 1];
	int maxprofit = 0;

	for (int i = 1; i <= maxi; i++)
	{
		result[i] = -1;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = arr[i].deadline; j > 0; j--)
		{
			if (result[j] == -1)
			{
				result[j] = i;
				maxprofit += arr[i].profit;
				break;
			}
		}
	}

	printf("Jobs that are selected for max profit :-");
	for (int i = 1; i <= maxi; i++)
	{
		if (result[i] != -1)
		{
			printf("%c ", arr[result[i]].id);
		}
	}

	printf("\n Maximum profit is :- %d", maxprofit);
}

int main()
{
	Job arr[] = {{'a', 2, 100},
				 {'b', 1, 19},
				 {'c', 2, 27},
				 {'d', 1, 25},
				 {'e', 3, 15}};
	int n = sizeof(arr) / sizeof(arr[0]);
	printf(
		"Following is maximum profit sequence of jobs \n");

	jobsequence(arr, n);
	return 0;
}