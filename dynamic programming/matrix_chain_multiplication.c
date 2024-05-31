#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int dp[100][100];

int solve(int p[],int i,int j){
    if(i == j) return 0;

    int sum;
    int min = 9999999;

    for (int k = i; k < j; k++)
    {
        sum = solve(p,i,k) + solve(p,k+1,j) + p[i-1] * p[k] * p[j];
        if(sum < min) min = sum;
    }
    
    return min;
}

int solvemem(int p[],int i,int j){
    if(i == j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    dp[i][j] = 9999999;
    for (int k = i; k < j; k++)
    {
        if(dp[i][j] < solve(p,i,k) + solve(p,k+1,j) + p[i-1] * p[k] * p[j]);
            dp[i][j] = solve(p,i,k) + solve(p,k+1,j) + p[i-1] * p[k] * p[j];
    }
    
    return dp[i][j];
}

int main()
{
    int arr[] = {10,50,20,100};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            dp[i][j] = -1;
        }
    }

    printf("\nThe minimum multiplication needed i :- %d ",solve(arr,1,n-1));
    return 0;
}