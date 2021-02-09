#include <iostream>
using namespace std;

class Number
{
    public:
        Number(int x);
        Number& add(int a);
        Number& sub(int b);
        void print();
    private:
        int n;
};

Number::Number(int x)
{
    n = x;
}

Number& Number::add(int a)
{
    n = n + a;
    return (*this);
}

Number& Number::sub(int b)
{
    n = n - b;
    return (*this);
}

void Number::print()
{
    cout << n << endl;
}

int main(){

	Number n(1);
	n.add(2).sub(3).add(4);
	n.print();

	
	Number n1(-1);
	n1.sub(12).sub(3).sub(4);
	n1.print();

	
	Number n2(0);
	n2.add(-13).add(0).add(0);
	n2.add(13);
	n2.print();

	return 0;
}