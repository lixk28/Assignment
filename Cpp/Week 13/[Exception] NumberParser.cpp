#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
using namespace std;

class NumberParseException
{
    public:
        NumberParseException() {}
};

int parseNumber(const char *str)
{
    if(str == NULL || strlen(str) == 0)
    {
        NumberParseException e;
        throw e;
    }

    int num = 0;
    int base = 1;
    for(int i = strlen(str) - 1; i >= 0; i--)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            num = num + (str[i] - 48) * base;
            base = base * 10;
        }
        else
        {
            NumberParseException e;
            throw e;
        }
    }

    return num;
}

void BasicTest() {
    string str1 = "", str2 = "1";
    try {
        int num1 = parseNumber(str1.c_str());
        int num2 = parseNumber(str2.c_str());
        printf("sum is %d\n", num1+num2);
    } catch (NumberParseException) {
        printf("Not a number.\n");
    }
    str1 = "1";
    try {
        int num1 = parseNumber(str1.c_str());
        int num2 = parseNumber(NULL);
        printf("sum is %d\n", num1+num2);
    } catch (NumberParseException) {
        printf("Not a number.\n");
    }
    cin >> str1 >> str2;
    try {
        int num1 = parseNumber(str1.c_str());
        int num2 = parseNumber(str2.c_str());
        printf("sum is %d\n", num1+num2);
    } catch (NumberParseException) {
        printf("Not a number.\n");
    }
}

void HardTest() {
    int Ttime;
    cin >> Ttime;
    while (Ttime--) {
        string str1, str2;
        cin >> str1 >> str2;
        try {
            int num1 = parseNumber(str1.c_str());
            int num2 = parseNumber(str2.c_str());
            printf("sum is %d\n", num1+num2);
        } catch (NumberParseException) {
            printf("Not a number.\n");
        }
    }
}

int main() {
    int hard;
    cin >> hard;
    if (hard)
        HardTest();
    else
        BasicTest();
}