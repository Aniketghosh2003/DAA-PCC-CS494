#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[20];
    float price;
} Product;

void swap(Product *a, Product *b) {
    Product temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Product arr[],int s ,int e){
    
    int pivot = arr[s].price;
    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i].price < pivot)
        {
            cnt++;
        }
    }

    int pivotindex = s + cnt;
    swap(&arr[s],&arr[pivotindex]);

    int i = s;
    int j = e;

    while (i < pivotindex && j > pivotindex)
    {
        while (arr[i].price < pivot)
        {
            i++;
        }
        while (arr[j].price >= pivot)
        {
            j--;
        }
        if (i < pivotindex && j > pivotindex)
        {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }

    return pivotindex;
}


// Quick sort function
void quickSort(Product arr[], int low, int high)
{
    if (low < high)
    {
        
        int pi = partition(arr, low, high);

        
        quickSort(arr, low, pi);
        quickSort(arr, pi+1, high);
    }
}

int main()
{
    Product products[6] = {
        {"Laptops", 0},
        {"Phones", 0},
        {"TVs", 0},
        {"Cameras", 0},
        {"Tablets", 0},
        {"Headphones", 0},
        };

    
    printf("Enter the prices for the following products:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%s: rs", products[i].name);
        scanf("%f", &products[i].price);
    }

    
    quickSort(products, 0, 5);

    
    printf("\nProducts sorted by price (low to high):\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%s: rs%.2f\n", products[i].name, products[i].price);
    }

    return 0;
}
