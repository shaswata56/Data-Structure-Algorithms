#include <stdio.h>

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

int strcmp(char* x, char* y)
{
    while(*x)
    {
        if (*x != *y)
            break;
        x++;
        y++;
    }
    return *(const unsigned char*)x - *(const unsigned char*)x;
}

void replace(char* str,char* sub,char* rep)
{
    int str_len,sub_len,rep_len;
    int i=0,j,k;
    int flag=0,start,end;
    str_len=strlen(str);
    sub_len=strlen(sub);
    rep_len=strlen(rep);

    for(i=0; i<str_len; i++)
    {
        flag=0;
        start=i;
        for(j=0; str[i]==sub[j]; j++,i++)
        {
            if(j==sub_len-1)
                flag=1;
        }
        end=i;
        if(flag==0)
        {
            i-=j;
        }
        else
        {
            for(j=start; j<end; j++)
            {
                for(k=start; k<str_len; k++)
                {
                    str[k]=str[k+1];
                }
                str_len-- ;
                i--;
            }
            for(j=start; j<start+rep_len; j++)
            {
                for(k=str_len; k>=j; k--)
                {
                    str[k+1]=str[k];
                }
                str[j] = rep[j-start];
                str_len++;
                i++;
            }
        }
    }
}

int main()
{
    char str[100],substr[100],rep[100];
    printf("\nType the sentence  :");
    scanf("%[^\n]%*c", str);
    printf("\nsub str :");
    scanf("%[^\n]%*c", substr);
    printf("\nReplacing  :");
    scanf("%[^\n]%*c", rep);
    replace(str, substr, rep);
    printf("\n%s", str);
    return 0;
}

