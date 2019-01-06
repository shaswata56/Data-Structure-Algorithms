#include <stdio.h>

struct hash_pair{
        long long value;
        long long key;
};

void display_table(struct hash_pair dt[], long long size)
{
        long long i;
        printf("Value\tKey\n");
        for (i=0; i<size; i++)
        {
                printf("%lld\t%lld\n", dt[i].value, dt[i].key);
        }
}

void main(void)
{
        long long size, i, temp;
        printf("Enter the size of the table: ");
        scanf("%lld", &size);
        struct hash_pair hash_table[size];
        printf("Enter the elements: ");
        for (i=0; i<size; i++)
        {
                scanf("%lld", &temp);
                hash_table[temp % size].value = temp;
                hash_table[temp % size].key = temp % size;
        }
        printf("\n");
        display_table(hash_table, size);
}
