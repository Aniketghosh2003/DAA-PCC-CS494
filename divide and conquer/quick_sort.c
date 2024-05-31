#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int partition(int *arr, int s, int e)
{

    int pivot = arr[s];
    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] < pivot)
        {
            cnt++;
        }
    }

    int pivotindex = s + cnt;
    int c = arr[pivotindex];
    arr[pivotindex] = arr[s];
    arr[s] = c;

    int i = s;
    int j = e;

    while (i < pivotindex && j > pivotindex)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] >= pivot)
        {
            j--;
        }
        if (i < pivotindex && j > pivotindex)
        {
            int c = arr[i];
            arr[i] = arr[j];
            arr[j] = c;
            i++;
            j--;
        }
    }

    return pivotindex;
}

void quicksort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int p = partition(arr, s, e);

    quicksort(arr, s, p);
    quicksort(arr, p + 1, e);
}

int main()
{
    int n;
    printf("\n Enter the number of elements :-  ");
    scanf("%d",&n);

    int arr[n];
    printf("\n Enter the elements for the array :-");
    for(int i = 0;i < n;i++){
         scanf("%d",&arr[i]);
    }

    printf("\n Before the sorting elements are :- ");
    for(int i = 0;i < n;i++){
        printf(" %d ",arr[i]);
    }

    quicksort(arr,0,n-1);

    printf("\n After the sorting elements are :- ");
    for(int i = 0;i < n;i++){
        printf(" %d ",arr[i]);
    }

    return 0;
}