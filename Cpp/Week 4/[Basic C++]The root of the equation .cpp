#include <iostream>
#include <iomanip>
#include <cmath>
#define DELTA (b * b - 4 * a * c)
using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;

    double x1 = (-b - pow(DELTA, 0.5)) / (2 * a);
    double x2 = (-b + pow(DELTA, 0.5)) / (2 * a);

    cout << setiosflags(ios::fixed) << setprecision(3) << x1 << " " << x2 << endl;

    return 0;   
}