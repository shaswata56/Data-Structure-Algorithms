#include <stdio.h>

void swap(int* a, int* b)
{
    int t=*a;
    *a= *b;
    *b= t;
}

int partition( int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for(int j = low; j <= high-1 ; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void quicksort(int arr[], int low, int high)
{
    if(low<high)
    {
        int partitionIndex = partition(arr, low, high);
        quicksort(arr, low, partitionIndex-1);
        quicksort(arr, partitionIndex, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for(i=0; i <size ; i++)
        printf("%d", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {10,7,8,9,1,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr, 0 ,n-1);
    printf("Sorted Array: ");
    printArray(arr,n);
    return 0;
}
