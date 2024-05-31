#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void countsort(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    
    int freq[max + 1];

    for (int i = 0; i <= max; ++i)
    {
        freq[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    for (int i = 1; i < max + 1; i++)
    {
        freq[i] += freq[i - 1];
    }

    int ans[n];
    for (int i = n - 1; i >= 0; i--)
    {
        ans[--freq[arr[i]]] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = ans[i];
    }
}

int main()
{
    int n;
    printf("\n Enter the number of elements :-  ");
    scanf("%d", &n);

    int arr[n];
    printf("\n Enter the elements for the array :-");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\n Before the sorting elements are :- ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }

    countsort(arr, n);

    printf("\n After the sorting elements are :- ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }

    return 0;
}