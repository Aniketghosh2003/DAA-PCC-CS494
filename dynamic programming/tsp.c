#include <stdio.h>  
#include <limits.h>  
#include<string.h>

int n = 4;
int dp[20][20];

int cost[4][4] = {
   {0, 22, 26, 30},
   {30, 0, 45, 35},
   {25, 45, 0, 60},
   {30, 35, 40, 0}};

int tspmem(int mask ,int pos){
    if(mask == (1 << n) - 1){
        return cost[pos][0];
    }

    if(dp[mask][pos] != -1) return dp[mask][pos];

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if((mask & (1 << i)) == 0){
            int currans = cost[pos][i] + tspmem(mask|(1 << i) , i);
            if(currans < ans) ans = currans;
        }
    }
    return dp[mask][pos] = ans;
}
  
int main()
{
    memset(dp, -1, sizeof(dp));  
  
    int minCost = tspmem(1, 0); 
  
    printf("Minimum cost of the TSP: %d\n", minCost);  
  
    
    return 0;
}
