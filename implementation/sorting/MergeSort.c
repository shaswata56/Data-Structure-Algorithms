#include <stdio.h>

void merge(int a[], int i1, int j1, int i2, int j2)
{
    int tmp[50];
    int i,j,k;
    i=i1, j=i2, k=0;
    while(i <= j1 && j <= j2)
    {
        if(a[i] < a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }
    while(i <= j1)
        tmp[k++] = a[i++];
    while(j <= j2)
        tmp[k++] = a[j++];
    for(i=i1, j=0; i <= j2; i++, j++)
    {
        a[i] = tmp[j];
    }
}

void mergesort(int a[], int i, int j)
{
    int mid;
    if(i<j)
    {
        mid=(i+j)/2;
        mergesort(a, i, mid);
        mergesort(a, mid+1, j);
        merge(a, i, mid, mid+1, j);
    }
}

int main()
{
    int a[100], n, i;
    printf("Enter element number:");
    scanf("%d", &n);
    printf("Enter array elements:");
    for(i=0; i < n; i++)
        scanf("%d", &a[i]);
    mergesort(a, 0, n-1);
    for(i=0; i < n; i++)
        printf("%d ", a[i]);
        return 0;
}

