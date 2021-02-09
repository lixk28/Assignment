#include <cstdio>
#include <iostream>

std::string s;
std::string change1(const char* cstr)
{
    s = cstr;
    return s;
}

void change2(std::string str, char* cstr)
{
    for(int i = 0; i < str.size(); i++)
        cstr[i] = str[i];
}

std::string str;
char cstr[100];
int main() {
    std::cin >> str;
    change2(str, cstr);
    puts(cstr);
    scanf("%s", cstr);
    std::cout << change1(cstr) << std::endl;
    return 0;
}