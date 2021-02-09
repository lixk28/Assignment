#include <iostream>
using namespace std;

namespace user1{
    int x = 0;
};

namespace user2{
    int x = 10;
};

using user2::x;
int main()
{
    using user1::x;

    cout << x;

    return 0;
}