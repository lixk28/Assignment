#include <iostream>
using namespace std;

class Point
{
    private:
        int x,y;
    public:
        Point(int a,int b);
        void Move(int a,int b);
        int Getx() const;
        int Gety() const;
};

Point::Point(int a, int b)
{
    x = a;
    y = b;
}

void Point::Move(int a, int b)
{
    x = x + a;
    y = y + b;
}

int Point::Getx() const {return x;}
int Point::Gety() const {return y;}

class Rectangle: public Point
{
    public:
        Rectangle(int a, int b, int l, int w);
        int Getlength();
        int Getwidth();
        int Getarea();
    private:
        int length;
        int width;
};

Rectangle::Rectangle(int a, int b, int l, int w): Point(a, b)
{
    length = l;
    width = w;
}

int Rectangle::Getlength() {return length;}
int Rectangle::Getwidth() {return width;}
int Rectangle::Getarea() {return length * width;}


int main()
{ 
	int n;
	double x,y,length,width,xmove,ymove;
	cin>>n;
	for (int i = 0;i<n;i++)
	{   
		cin>>x>>y;
		cin>>length>>width;
		Rectangle R(x,y,length,width);
		cin>>xmove>>ymove;
		R.Move(xmove,ymove);
		cout <<R.Getx()<<" "<<R.Gety()<<" "
			 <<R.Getlength()<<" "<<R.Getwidth()
		 	 <<" "<<R.Getarea()<<endl;
	}
	return 0;
}