#include <stdio.h>
int match[100],k;

unsigned int strlen(char *p)
{
    unsigned int count = 0;
    while(*p!='\0')
    {
        count++;
        p++;
    }
    return count;
}

void search(char* str, char* pattern)
{
    k=0;
    int slen = strlen(str);
    int plen = strlen(pattern);
    for (int i = 0; i <= slen - plen; i++)
    {
        int j;
        for (j = 0; j < plen; j++)
        {
            if (str[i + j] != pattern[j])
            break;
        }
        if (j == plen)
        {
            match[k++] = i;
        }
    }
}

int main()
{
    char str[100], pattern[100];
    int i=1;
    printf("\nInput a String:");
    scanf("%[^\n]%*c", str);
    printf("\nEnter Pattern to search:");
    scanf("%[^\n]%*c", pattern);
    printf("\n\t\tSearching..\n");
    search(str, pattern);
    printf("\tPattern found on ");
    for(i=0; i<k; i++)
        printf("%d ", match[i]);
    printf("indexes.");
    return 0;
}
