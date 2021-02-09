#include <iostream>
#include <cstdlib>
using namespace std;

class Exchange
{
    public:
	void operator()(int&, int&);
};

void Exchange::operator()(int &a, int &b)
{
    int t;
    t = a;
    a = b;
    b = t;
}

int main()
{

    Exchange swap;
   int i = 20;
   int j = 30;

   cout << i << " " << j << endl;
   
   swap(i, j);
   
   cout << i << " " << j << endl;
   
    return 0;
}