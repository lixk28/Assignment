#include <iostream>
using namespace std;

class Complex
{
public:
    Complex(): real(0), imag(0) {}
    Complex(int a, int b): real(a), imag(b) {}
    int getReal() const { return real; }
    int getImag() const { return imag; }

    Complex operator=(const Complex&);
    Complex operator+(const Complex&);
    Complex operator-(const Complex&);
    Complex operator+=(const Complex&);
    Complex operator-=(const Complex&);

private:
    int real;
    int imag;
};

Complex Complex::operator=(const Complex& c)
{
    real = c.real;
    imag = c.imag;
    return *this;
}

Complex Complex::operator+(const Complex& c)
{
    Complex temp;
    temp.real = real + c.real;
    temp.imag = imag + c.imag;
    return temp;
}

Complex Complex::operator-(const Complex& c)
{
    Complex temp;
    temp.real = real - c.real;
    temp.imag = imag - c.imag;
    return temp;
}

Complex Complex::operator+=(const Complex& c)
{
    real = real + c.real;
    imag = imag + c.imag;
    return *this;
}

Complex Complex::operator-=(const Complex& c)
{
    real = real - c.real;
    imag = imag - c.imag;
    return *this;
}

int main()
{
	//freopen("test01.in", "r", stdin);
	//freopen("test01.out", "w", stdout);
	Complex a(1,2);
	Complex b(2, 3);
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
