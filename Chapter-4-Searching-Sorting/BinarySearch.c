#include <stdio.h>

void printArray(int arr[], int size)
{
    int i;
    for(i=0; i <size ; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int binarysearch(int* arr, int l, int r, int x)
{
    if (r >= l)
    {
        int m = l + (r - l)/2;
        if (arr[m] == x)
            return m;
        if (arr[m] > x)
            return binarysearch(arr, l, m-1, x);
        return binarysearch(arr, m+1, r, x);
    }
    return -1;
}

int main()
{
    int arr[]= {1, 2, 6, 20, 21, 23, 29, 46, 73, 81, 87, 93, 98, 232, 254 ,365 ,654 ,808},x,pos;
    printf("Array elements: ");
    int n= sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    printf("Element to search:");
    scanf("%d", &x);
    pos = binarysearch(arr, 0, n-1, x);
    printf("Element index: %d\n", pos);
    return 0;
}
