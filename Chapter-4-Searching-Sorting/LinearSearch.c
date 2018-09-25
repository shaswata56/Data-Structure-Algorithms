#include <stdio.h>

void printArray(int arr[], int size)
{
    int i;
    for(i=0; i <size ; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
         return i;
    return -1;
}

int main()
{
    int arr[]={1,6,23,87,46,29,20,73,93,365,81,254,21,98,654,232,808,2},x,pos;
    printf("Array elements: ");
    int n= sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    printf("Element to search:");
    scanf("%d", &x);
    pos = search(arr, n, x);
    printf("Element index: %d\n", pos);
    return 0;
}
