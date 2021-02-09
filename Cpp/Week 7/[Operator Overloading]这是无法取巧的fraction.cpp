#include <iostream>
#define ABS(X) ((X) < 0 ? (-(X)):(X))
using namespace std;

class fraction {
    private:
        int _numerator, _denominator;
        int gcd(const int &, const int &) const;
            // If you don't need this method, just ignore it.
        void simp();
            // To get the lowest terms.
    public:
        fraction(const int & = 0, const int & = 1);
            // The numerator and the denominator
            // fraction(5) = 5/1 = 5 :)
        fraction(const fraction &);
            // copy constructor

        void operator=(const fraction &);

        // You must know the meaning of +-*/, don't you ?
        fraction operator+(const fraction &) const;
        fraction operator-(const fraction &) const;
        fraction operator*(const fraction &) const;
        fraction operator/(const fraction &) const;

        void operator+=(const fraction &);
        void operator-=(const fraction &);
        void operator*=(const fraction &);
        void operator/=(const fraction &);

        // Comparison operators
        bool operator==(const fraction &) const;
        bool operator!=(const fraction &) const;
        bool operator<(const fraction &) const;
        bool operator>(const fraction &) const;
        bool operator<=(const fraction &) const;
        bool operator>=(const fraction &) const;

        friend std::istream & operator>>(std::istream &, fraction &);
            // Input Format: two integers with a space in it
            // "a b" is correct. Not "a/b"
        friend std::ostream & operator<<(std::ostream &, const fraction &);
            // Normally you should output "a/b" without any space and LF
            // Sometims you may output a single integer (Why? Guess XD)
            // If it is not a number (den = 0), output "NaN"
};

int fraction::gcd(const int &a, const int &b) const
{
    return b == 0 ? a : gcd(b, a % b);
}

void fraction::simp()
{
    int max_divisor = gcd(_numerator, _denominator);
    _numerator /= max_divisor;
    _denominator /= max_divisor;
}

fraction::fraction(const int &a, const int &b)
{
    _numerator = a;
    _denominator = b;
}

fraction::fraction(const fraction &f)
{
    _numerator = f._numerator;
    _denominator = f._denominator;
}

void fraction::operator=(const fraction &f)
{
    this->_numerator = f._numerator;
    this->_denominator = f._denominator;
}

fraction fraction::operator+(const fraction &f) const
{
    if(_denominator == 0 || f._denominator == 0)
    {
        fraction zero(0, 0);
        return zero;
    }

    fraction t;
    t._numerator = _numerator * f._denominator + _denominator * f._numerator;
    t._denominator = _denominator * f._denominator;
    t.simp();
    return t;
}
fraction fraction::operator-(const fraction &f) const
{
    if(_denominator == 0 || f._denominator == 0)
    {
        fraction zero(0, 0);
        return zero;
    }
    
    fraction t;
    t._numerator = _numerator * f._denominator - _denominator * f._numerator;
    t._denominator = _denominator * f._denominator;
    t.simp();
    return t;
}

fraction fraction::operator*(const fraction &f) const
{
    if(_denominator == 0 || f._denominator == 0)
    {
        fraction zero(0, 0);
        return zero;
    }
    
    fraction t;
    t._numerator = _numerator * f._numerator;
    t._denominator = _denominator * f._denominator;
    t.simp();
    return t;
}

fraction fraction::operator/(const fraction &f) const
{
    if(_denominator == 0 || f._denominator == 0)
    {
        fraction zero(0, 0);
        return zero;
    }
    
    fraction t;
    t._numerator = _numerator * f._denominator;
    t._denominator = _denominator * f._numerator;
    t.simp();
    return t;
}

void fraction::operator+=(const fraction &f) { (*this) = (*this) + f; }
void fraction::operator-=(const fraction &f) { (*this) = (*this) - f; }
void fraction::operator*=(const fraction &f) { (*this) = (*this) * f; }
void fraction::operator/=(const fraction &f) { (*this) = (*this) / f; }

bool fraction::operator==(const fraction &f) const
{
    if(_denominator == 0 && f._denominator == 0)
        return true;
    else if(_numerator == f._numerator && _denominator == f._denominator)
        return true;
    else 
        return false;
}

bool fraction::operator!=(const fraction &f) const
{
    if((*this) == f)
        return false;
    else    
        return true;
}

bool fraction::operator<(const fraction &f) const
{
    if((*this) == f)
        return false;

    fraction t;
    t = (*this) - f;
    if(t._numerator * t._denominator < 0)
        return true;
    else
        return false;
}

bool fraction::operator>(const fraction &f) const
{
    if((*this) < f || (*this) == f)
        return false;
    else
        return true;
}

bool fraction::operator<=(const fraction &f) const
{
    if((*this) < f || (*this) == f)
        return true;
    else
        return false;
}

bool fraction::operator>=(const fraction &f) const
{
    if((*this) > f || (*this) == f)
        return true;
    else
        return false;
}

std::istream & operator>>(std::istream &is, fraction &f)
{
    is >> f._numerator >> f._denominator;
    return is;
}

std::ostream & operator<<(std::ostream &os, const fraction &f)
{
    if(f._denominator == 1 || f._numerator == 0)
        os << f._numerator;
    else if(f._denominator != 1 && f._denominator != 0)
    {
        if(f._numerator * f._denominator < 0)
            os << "-" << ABS(f._numerator) << "/" << ABS(f._denominator);
        else
            os << f._numerator << "/" << f._denominator;
    }
    else if(f._denominator == 0)
        os << "NaN";

    return os;
}

void print(const bool & f) {
    if (f)
        std::cout << "True" << std::endl;
    else
        std::cout << "False" << std::endl;
}

int main() {
    fraction f1, f2;
    std::cin >> f1 >> f2;
    std::cout << f1 + f2 << ' ' << f1 - f2 << ' '
              << f1 * f2 << ' ' << f1 / f2 << std::endl;
    f1 += f2;
    std::cout << f1 << std::endl;
    f1 -= f2;
    std::cout << f1 << std::endl;
    f1 *= f2;
    std::cout << f1 << std::endl;
    f1 /= f2;
    std::cout << f1 << std::endl;
    print(f1 == f2);
    print(f1 != f2);
    print(f1 < f2);
    print(f1 > f2);
    print(f1 <= f2);
    print(f1 >= f2);
    return 0;
}

