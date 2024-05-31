#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int[] maxmin(int arr[],int i,int j){
    int max,min;

    if(i == j){
        max = arr[i];
        min = arr[j];
    }

    else if(i == j-1){
        if(arr[i] > arr[j]){
            max = arr[i];
            min = arr[j];
        }
        else{
            max = arr[j];
            min = arr[i];
        }
    }
    else{
        int mid = (i+j)/2;
        int left[2] = maxmin(arr,i,mid);
        int right[2] = maxmin(arr,mid+1,j);
        if(left[0] > right[0]){
            max = left[0];
        }
        else{
            max = right[0];
        }
        if(left[1] < right[1]){
            min = left[1];
        }
        else{
            min = right[1];
        }
        int ans = {max,min};
        return ans;
    }
}

int main()
{
    int arr[] = {22,13,-5,-8,15,60,17,31,47};
    
    return 0;
}