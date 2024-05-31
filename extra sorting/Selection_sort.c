#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void selectionsort(int *arr,int size){
    for (int i = 0; i < size - 1; i++)
    {
       int min = arr[i];
       for (int j = i+1; j < size; j++)
       {
        if (min > arr[j])
        {
            min = arr[j];
        }
       }
       if(min != arr[i]){
        int c = arr[i];
        arr[i] = min;
        min = c;
       }
    } 
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

    selectionsort(arr,n);

    printf("\n After the sorting elements are :- ");
    for(int i = 0;i < n;i++){
        printf(" %d ",arr[i]);
    }

    return 0;
}