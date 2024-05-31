#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define num_events 4
#define max_time 8

int dp[10][10];

int knapsack(int duration[], int enjoyment[], int i, int cap)
{
    if (i == 0)
    {
        if (duration[0] <= cap)
        {
            return enjoyment[0];
        }
        else
        {
            return 0;
        }
    }
    int include = 0;
    if (duration[i] <= cap)
    {
        include = enjoyment[i] + knapsack(duration, enjoyment, i - 1, cap - duration[i]);
    }
    int exclude = knapsack(duration, enjoyment, i - 1, cap);

    if (include > exclude)
    {
        return include;
    }
    else
    {
        return exclude;
    }
}

int knapsackmem(int duration[], int enjoyment[], int events, int time, int dp[10][10])
{
    if (events == 0)
    {
        if (duration[0] <= time)
        {
            return enjoyment[0];
        }
        else
        {
            return 0;
        }
    }

    if (dp[events][time] != -1)
    {
        return dp[events][time];
    }

    int include = 0;
    if (duration[events] <= time)
    {
        include = enjoyment[events] + knapsack(duration, enjoyment, events - 1, time - duration[events]);
    }
    int exclude = knapsack(duration, enjoyment, events - 1, time);

    if (include > exclude)
    {
        return dp[events][time] = include;
    }
    else
    {
        return dp[events][time] = exclude;
    }
}

int knapsacktab(int duration[], int enjoyment[], int events, int time)
{
    memset(dp, 0, sizeof(dp));

    for (int i = duration[0]; i <= time; i++)
    {
        if (duration[0] <= time)
        {
            dp[0][i] = enjoyment[0];
        }
        else
        {
            dp[0][i] = 0;
        }
    }

    for (int i = 1; i <= events; i++)
    {
        for (int t = 0; t <= time; t++)
        {
            int include = 0;
            if (duration[i] <= t)
            {
                include = enjoyment[i] + dp[i - 1][t - duration[i]];
            }
            int exclude = dp[i - 1][t];

            if (include > exclude)
            {
                dp[i][t] = include;
            }
            else
            {
                dp[i][t] = exclude;
            }
        }
    }

    return dp[events][time];
}

int main()
{
    int duration[4] = {3, 2, 4, 3};
    int enjoyment[4] = {4, 2, 5, 3};

    // memset(dp,-1,sizeof(dp));
    // int res = knapsack(duration, enjoyment, num_events - 1, max_time);
    //  int res = knapsackmem(duration,enjoyment,num_events-1,max_time,dp);

    int res = knapsacktab(duration, enjoyment, num_events - 1, max_time);

    printf("\nThe Maximum enjoyment you can get :- %d", res);
    return 0;
}