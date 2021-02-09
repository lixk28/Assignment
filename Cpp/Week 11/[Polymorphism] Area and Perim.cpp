#include <iostream>
using namespace std;
const double PI = 3.14;

class Shape
{
    public:
        Shape() {}
        virtual double GetArea() = 0;
        virtual double GetPerim() = 0;
};

class Rectangle: public Shape
{
    public:
        Rectangle(double a, double b): Shape()
        {
            x = a;
            y = b;
        }
        virtual double GetArea() { return x * y; }
        virtual double GetPerim() { return 2 * (x + y); }

    private:
        double x;
        double y;
};


class Circle: public Shape
{
    public:
        Circle(double x): Shape() { r = x; }
        virtual double GetArea() { return PI * r * r; }
        virtual double GetPerim() { return 2 * PI * r; }

    private:
        double r;
};

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	double n,a,b,c;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		Shape *s;
		cin>>a>>b>>c;
		s = new Rectangle(a,b);
		cout<<s->GetArea()<<" "<<s->GetPerim()<<endl;
		delete s;
		s = new Circle(c);
		cout<<s->GetArea()<<" "<<s->GetPerim()<<endl;
		delete s;
	}
	return 0;
}