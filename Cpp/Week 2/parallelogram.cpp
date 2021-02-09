#include <iostream>
using namespace std;

int main()
{
    char c;
    cin >> c;
    for(int i = 1; i <= 4; i++)
    {
        int count = 0;
        for(int j = 1; ;j++)
        {
            if(j <= 4 - i)
                cout << ' ';
            else
            {
                cout << c;
                count++;
            }
            if(count == 4)
            {
                cout << '\n';
                break;
            }
        }
    }

    return 0;
}