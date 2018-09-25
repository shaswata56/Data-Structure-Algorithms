#include <stdio.h>

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
    bubblesort(arr, 0 ,n-1);
    printf("Sorted Array: ");
    printArray(arr,n);
    return 0;
}
