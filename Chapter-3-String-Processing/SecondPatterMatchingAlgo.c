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

void chklps(char* pattern, int plen, int* lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < plen)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void search(char* str, char* pattern)
{
    k=0;
    int slen = strlen(str);
    int plen = strlen(pattern);
    int lps[plen];
    chklps(pattern, plen, lps);
    int i = 0, j = 0;
    while (i < slen)
    {
        if (pattern[j] == str[i])
        {
            j++;
            i++;
        }
        if (j == plen)
        {
            match[k++] = i - j;
            j = lps[j - 1];
        }
        else if (i < slen && pattern[j] != str[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i = i + 1;
            }
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
    printf("\tPattern found at ");
    for(i=0; i<k; i++)
        printf("%d ", match[i]);
    printf("indexes.");
    return 0;
}
