#include <iostream>
#include <iomanip>
#define PI 3.14159265358979
using namespace std;

double area(double R)
{
    return PI * R * R;
}

int main()
{  
    double R;
    cin >> R;
    cout << setiosflags(ios::fixed) << setprecision(8) << area(R) << endl;

    return 0;
}