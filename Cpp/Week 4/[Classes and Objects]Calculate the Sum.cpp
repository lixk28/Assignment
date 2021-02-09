#include <iostream>
using namespace std;

class MyClass
{
    int data;
public:
    MyClass(int d)
    {
        data = d;
    }

    void printData()
    {
        cout << data << endl;
    }

    int sumIt()
    {
        int sum = 0;
        for(int i = 1; i <= data; i++)
            sum += i;
        return sum;
    }
};