#include <iostream>
using namespace std;

class Complex
{
    public:
        Complex(): real(0), imag(0) {}
        Complex(int a, int b): real(a), imag(b) {}
        int getReal() const { return real; }
        int getImag() const { return imag; }

        Complex operator+(Complex &c);
        Complex operator-(Complex &c);
        void operator+=(Complex &c);
        void operator-=(Complex &c);
        
    private:
        int real;
        int imag;
};


Complex Complex::operator+(Complex &c)
{
    Complex t;
    t.real = real + c.real;
    t.imag = imag + c.imag;
    return t;
}

Complex Complex::operator-(Complex &c)
{
    Complex t;
    t.real = real - c.real;
    t.imag = imag - c.imag;
    return t;
}

void Complex::operator+=(Complex &c)
{
    this->real = this->real + c.real;
    this->imag = this->imag + c.imag;
}

void Complex::operator-=(Complex &c)
{
    this->real = this->real - c.real;
    this->imag = this->imag - c.imag;
}

int main()
{
 //freopen("test01.in", "r", stdin);
 //freopen("test01.out", "w", stdout);
 Complex a(1,2);
 Complex b(2,3);
 cout << "a(" << a.getReal() << ", " << a.getImag() << ")" << endl;
 cout << "b(" << b.getReal() << ", " << b.getImag() << ")" << endl;

 Complex c, d;
 c = a + b;
 cout << "c(" << c.getReal() << ", " << c.getImag() << ")" << endl;
 d = a - b;
 cout << "d(" << d.getReal() << ", " << d.getImag() << ")" << endl;
 c += d;
 cout << "c(" << c.getReal() << ", " << c.getImag() << ")" << endl;
 c -= a;
 cout << "c(" << c.getReal() << ", " << c.getImag() << ")" << endl;

 return 0;
}
