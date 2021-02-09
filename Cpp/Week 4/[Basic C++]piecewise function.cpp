#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double x;
    cin >> x;
    if(x <= -1)
        cout << setiosflags(ios::fixed) << setprecision(2) << x + 1 << endl;
    else if(x >= 1)
        cout << setiosflags(ios::fixed) << setprecision(2) << log10(x) << endl;
    else if(x > -1 && x < 1)
        cout << setiosflags(ios::fixed) << setprecision(2) << abs(x) << endl;

    return 0;
}