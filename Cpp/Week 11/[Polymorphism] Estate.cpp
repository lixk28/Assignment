#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Land
{
    public:
        Land(double r, double p)
        {
            price = p;
            radius = r;
        }
        double getPrice() { return price; }
        double getRadius() { return radius; }
        virtual double getArea() { return 0; }

    private:
        double price;
        double radius;
};

class Circle: public Land
{
    public:
        Circle(double r, double p): Land(r, p) {}
        virtual double getArea() { return acos(-1) * pow(getRadius(), 2); }
};

class Square: public Land
{
    public:
        Square(double r, double p): Land(r, p) {}
        virtual double getArea() { return getRadius() * getRadius(); }
};

class Accountant
{
    public:
        Accountant();
        void DevelopEstate(Land* l);
        double CheckMoney();

    private:
        double income;
};

Accountant::Accountant() 
{ 
    income = 0; 
}

void Accountant::DevelopEstate(Land* l)
{
    income = income + l->getPrice() * l->getArea();
}

double Accountant::CheckMoney()
{
    return income;
}



int main(int argc, const char *argv[]) {
  Accountant py;
  Circle *a = new Circle(100, 10000);
  Square *b = new Square(100, 50000);
  py.DevelopEstate(a);
  cout << setprecision(10) << py.CheckMoney() << endl;
  py.DevelopEstate(b);
  cout << setprecision(10) << py.CheckMoney() << endl;

  return 0;
}
