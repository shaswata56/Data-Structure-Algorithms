#include <stdio.h>

void swap(int* a, int* b)
{
    int t=*a;
    *a= *b;
    *b= t;
}

void bubblesort(int arr[], int n)
{
    if (n == 1)
        return;
    for (int i=0; i<n-1; i++)
        if (arr[i] > arr[i+1])
            swap(&arr[i], &arr[i+1]);
    bubblesort(arr, n-1);
}

void printArray(int arr[], int size)
{
    int i;
    for(i=0; i <size ; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {10,7,8,9,1,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Ordinary Array: ");
    printArray(arr,n);
    bubblesort(arr, n);
    printf("Sorted Array: ");
    printArray(arr,n);
    return 0;
}
