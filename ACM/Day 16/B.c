#include <stdio.h>
#include <string.h>

int main()
{
    char str[10000]={'\0'};
    char c;
    int n[26]={0};
    scanf("%s", str);
    for(int i = 0; i < strlen(str); i++)
    {
        switch(str[i])
        {
            case 'a':n[0]++;break;
            case 'b':n[1]++;break;
            case 'c':n[2]++;break;
            case 'd':n[3]++;break;
            case 'e':n[4]++;break;
            case 'f':n[5]++;break;
            case 'g':n[6]++;break;
            case 'h':n[7]++;break;
            case 'i':n[8]++;break;
            case 'j':n[9]++;break;
            case 'k':n[10]++;break;
            case 'l':n[11]++;break;
            case 'm':n[12]++;break;
            case 'n':n[13]++;break;
            case 'o':n[14]++;break;
            case 'p':n[15]++;break;
            case 'q':n[16]++;break;
            case 'r':n[17]++;break;
            case 's':n[18]++;break;
            case 't':n[19]++;break;
            case 'u':n[20]++;break;
            case 'v':n[21]++;break;
            case 'w':n[22]++;break;
            case 'x':n[23]++;break;
            case 'y':n[24]++;break;
            case 'z':n[25]++;break;
        }
    }

    int flag = 0;
    for(int i = 0; i < 26; i++)
    {
        if(n[flag] < n[i])
            flag = i;
    }
    printf("%c", flag+97);

    return 0;
}