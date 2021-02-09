#include <iostream>
using namespace std;

enum Month { JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

int main()
{
    int month;
    for(month = JAN; month <= DEC; month++)
        cout << month;
    return 0;
}