#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void bubblesort(int arr[],int size){
        int temp;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (arr[j+1] < arr[j])
                {
                   temp = arr[j];
                   arr[j] = arr[j+1];
                   arr[j+1] = temp;
                }
                
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

    bubblesort(arr,n);

    printf("\n After the sorting elements are :- ");
    for(int i = 0;i < n;i++){
        printf(" %d ",arr[i]);
    }

    return 0;
}