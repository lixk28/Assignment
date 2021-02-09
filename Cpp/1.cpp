#include <iostream>
using namespace std;
class B
{
    public:
        B() {}
        int k;
};

int main()
{
    B b;
    cout << b.k << endl;
    return 0;
}