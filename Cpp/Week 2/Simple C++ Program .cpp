#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b;
    double x, y;
    char arr[10][11];
    
    cin >> a >> b;
    cin >> x >> y;
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            cin >> arr[i][j];

    cout << pow(a,b) << endl;
    cout << x * y << endl;
    for(int i = 9; i >= 0; i--)
        for(int j = 0; j < 10; j++)
        {
            cout << arr[i][j];
            if(j == 9)
                cout << '\n';
        }

    return 0;
}