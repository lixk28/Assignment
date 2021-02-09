#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void swap(int& x, int& y)
{
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}

void addsub(int x, int y, int& sum, int& diff)
{
    sum = x + y;
    diff = x - y;
}

int main() {
    int x, y, sum, diff;
    cin >> x >> y;
    addsub(x, y, sum, diff);
    cout << sum << '\t' << diff << endl;
    swap(x, y);
    cout << x << '\t' << y << endl;
    swap(sum, diff);
    cout << sum << '\t' << diff << endl;
    return 0;
}