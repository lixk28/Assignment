#include <iostream>
#include <cmath>
using namespace std;

class complex
{
    private:
        int real;
        int imag;
    public:
        complex();
        complex(int a, int b);
        void display() const;
        double getModuli() const;
        complex operator+(complex &c);
        complex operator-(complex &c);
};

complex::complex()
{
    real = 0;
    imag = 0;
}

complex::complex(int a, int b)
{
    real = a;
    imag = b;
}

void complex::display() const
{
    if(real != 0 && imag < 0)
        cout << real << "-" << -imag << "i";
    else if(real != 0 && imag > 0)
        cout << real << "+" << imag << "i";
    else if(real != 0 && imag == 0)
        cout << real;
    else if(real == 0 && (imag > 0 || imag < 0))
        cout << imag << "i";
    else if(real == 0 && imag == 0)
        cout << 0;
}

double complex::getModuli() const
{
    return pow(real * real + imag * imag, 0.5);
}

complex complex::operator+(complex &c)
{
    complex tmp;
    tmp.real = real + c.real;
    tmp.imag = imag + c.imag;
    return tmp;
}

complex complex::operator-(complex &c)
{
    complex tmp;
    tmp.real = real - c.real;
    tmp.imag = imag - c.imag;
    return tmp;
}

int main() {
  int real, imag;
  cin >> real >> imag;
  complex a(real, imag);
  a.display();
  cout << endl;
  cin >> real >> imag;
  complex b(real, imag);
  b.display();
  cout << endl;
  complex c = a + b;
  complex d = a - b;
  cout << c.getModuli() << " " << d.getModuli() << endl;
  c.display();
  cout << endl;
  d.display();
}