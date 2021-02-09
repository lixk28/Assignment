/*
 * @Author: Xuekun Li
 * @Date: 2020-11-10 22:11:21
 * @LastEditor: Xuekun Li
 * @LastEditTime: 2020-11-10 22:12:59
 * @Description: Try to code your bug.
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1 = "123";
    string s2 = "234";
    if (s1 < s2)
        cout << "s1 < s2";
    else if (s1 == s2)
        cout << "s1 == s2";
    else if (s1 > s2)
        cout << "s1 > s2";

    return 0;
}