#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void insertionsort(int arr[],int size){
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && key < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
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

    insertionsort(arr,n);

    printf("\n After the sorting elements are :- ");
    for(int i = 0;i < n;i++){
        printf(" %d ",arr[i]);
    }

    return 0;
}