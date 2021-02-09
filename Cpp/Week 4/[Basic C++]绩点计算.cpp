#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int grade;
    cin >> grade;

    if(grade < 0 || grade > 100)
        cout << "Invalid" << endl;
    else if(grade >= 0 && grade < 60)
        cout << "Failed" << endl;
    else if(grade >= 60 && grade <= 100)
        cout << setiosflags(ios::fixed) << setprecision(1) << (grade - 50) / 10.0 << endl;
    
    return 0;
}