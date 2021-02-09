#include <stdio.h>
#include <string.h>

int main()
{
    char str1[1000]={'\0'};
    char str2[1000]={'\0'};
    scanf("%s", str1);
    scanf("%s", str2);

    int count;
    for(count = 0; ; count++)
    {
        if(!strcmp(str1,str2))
            break;

        char c = str1[strlen(str1)-1];
        char temp1 = str1[0], temp2;
        for(int i = 0; i < strlen(str1)-1; i++)
        {
            temp2 = str1[i+1];
            str1[i+1] = temp1;
            temp1 = temp2;
        }
        str1[0] = temp1;
    }
    printf("%d", count);

    return 0;
}