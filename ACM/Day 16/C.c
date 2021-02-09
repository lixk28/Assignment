#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool Is_Palindromic_String(char str[], int begin, int end)
{   
    while(begin <= end)
    {
        if(str[begin] == str[end])
        {
            begin++;
            end--;
        }
        else 
            return false;
    }
    return true;
}

int main()
{
    char str[1000]={'\0'};
    char tmp[1000]={'\0'};
    scanf("%s", str);
    int length = strlen(str)-1;
    
    for(int i = 0, j = i + length; ; )
    {
        if(Is_Palindromic_String(str+i, 0, length))
        {
            for(int k = i; k <= j; k++)
                printf("%c", str[k]);
            break;
        }

        if(j == strlen(str)-1)
        {
            length--;
            i = 0;
            j = i + length;
        }
        else
        {
            i++;
            j++;
        }
    }

    return 0;
}