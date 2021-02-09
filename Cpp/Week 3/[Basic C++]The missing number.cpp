#include <iostream>
using namespace std;

int main()
{
    int a[5] = {0};
    for(int i = 1; i <= 4; i++)
    { 
        int tmp;
        cin >> tmp;
        a[tmp - 1] = 1;
    }
    for(int i = 0; i < 5; i++)
    {
        if(a[i] == 1)
            continue;
        else if(a[i] == 0)
        {
            cout << i + 1;
            break;
        }
    }

    return 0;   
}