#include<iostream>
#include<string>
using namespace std;

class Int
{
  int i;
public:
  int getI() { return i; }
  //add any member function needed here
  Int(int n = 0) { i = n; }
  operator int() { return i; }
  
  void operator=(const Int& a);

  void operator+=(double a);
  void operator-=(double a);
  void operator*=(double a);
  void operator/=(double a);

  Int operator++();
  Int operator++(int);
  Int operator--();
  Int operator--(int);

  friend std::istream& operator>>(std::istream& is, Int &a);
  friend std::ostream& operator<<(std::ostream& is, Int &a);

};

void Int::operator=(const Int& a) { i = a.i; }

void Int::operator+=(double a) { this->i = this->i + a; }
void Int::operator-=(double a) { this->i = this->i - a; }
void Int::operator*=(double a) { this->i = this->i * a; }
void Int::operator/=(double a) { this->i = this->i / a; }

Int Int::operator++()    { Int t; t.i = ++i; return t; }
Int Int::operator++(int) { Int t; t.i = i++; return t; }
Int Int::operator--()    { Int t; t.i = --i; return t; }
Int Int::operator--(int) { Int t; t.i = i--; return t; }

std::istream& operator>>(std::istream& is, Int &a) { is >> a.i; return is; }
std::ostream& operator<<(std::ostream& os, Int &a) { os << a.i; return os; }

void g()
{
  Int a=0;
  Int b(1);
  Int c(2.5);
  Int d = 99.5;

  cout <<  a << endl;
  cout <<  b << endl;
  cout << b.getI() << endl;  
  cout <<  c << endl;
  cout <<  d << endl;
  
  d += 1;
  d += 1.5;
  cout <<  c+d << endl;
  cout <<  1+c << endl;
  cout <<  c+1 << endl;
  cout <<  1.5+c << endl;
  cout <<  c+1.5 << endl;

  cout <<  a + b + c + d << endl;

  d -= 1;
  d -= 1.5;
  cout <<  c-d << endl;
  cout <<  1-c << endl;
  cout <<  c-1 << endl;
  cout <<  1.5-c << endl;
  cout <<  c-1.5 << endl;

  d *= 1;
  d *= 1.5;
  cout <<  c*d << endl;
  cout <<  9*c << endl;
  cout <<  c*9 << endl;
  cout <<  19.4*c << endl;
  cout <<  c*19.4 << endl;
  d /= 2;
  d /= 2.5;
  cout <<  d/c << endl;
  cout <<  2/c << endl;
  cout <<  c/2 << endl;
  cout <<  2.5/c << endl;
  cout <<  c/2.5 << endl;

  cout <<  b%c << endl;
  cout <<  5%c << endl;
  cout <<  c%2 << endl;

  cout <<  c++ << endl;
  cout <<  ++c << endl;
  cout <<  c-- << endl;
  cout <<  --c << endl;    
  cout <<  -c << endl;
  
  int c1 = c;
  cout << c1 << endl;
  c1 = c;  
  cout << c1 << endl;  

  cin >> d;
  cout <<  d << endl;
}

int main()
{
  g();
  return 0;
}
