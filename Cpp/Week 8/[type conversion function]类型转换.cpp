#include<iostream>
using namespace std;

class Fraction
{
    public:
        Fraction(int num, int den = 1) : m_numerator(num), m_denominator(den) {}
        // your code
        operator double() const { return (double)m_numerator / (double)m_denominator; }
    private:
        int m_numerator;        // 分子
        int m_denominator;      // 分母
};

int main(void)
{
    Fraction f(3, 5); 
    double d = 3.2 + f;
    cout << d << endl;

    return 0;
}