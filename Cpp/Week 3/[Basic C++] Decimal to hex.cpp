#include <iostream>
using namespace std;
#define JUST_CHECK

char *convertDecimalToHex(int value)
{
    char hex[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    char *p = new char[10];
    int i = 0;
    while(value != 0)
    {
        p[i++] = hex[value % 16];
        value = value / 16;
    }
    p[i] = '\0';
    for(int k = 0, j = i - 1; k < i / 2; k++, j--)
    {
        char tmp;
        tmp = p[k];
        p[k] = p[j];
        p[j] = tmp;
    }
    return p;
}

void convertDecimalToHex(int value, char *s)
{
    char hex[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    int i = 0;
    while(value != 0)
    {
        s[i++] = hex[value % 16];
        value = value / 16;
    }
    s[i] = '\0';
    for(int k = 0, j = i - 1; k < i / 2; k++, j--)
    {
        char tmp;
        tmp = s[k];
        s[k] = s[j];
        s[j] = tmp;
    }
}

int main()
{
    int a = 650;
    char *s = convertDecimalToHex(a);
    cout << s;

    return 0;
}