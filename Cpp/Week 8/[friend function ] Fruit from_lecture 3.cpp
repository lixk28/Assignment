#include <iostream>
#include <cstdlib>
using namespace std;

class Fruit
{
public:
	Fruit();

	friend ostream& operator << (ostream& out, const Fruit& x);
	friend istream& operator >> (istream& in,  Fruit& x);

private:
	string name, color;
};

Fruit::Fruit()
{
    for(int i = 0; i < name.size(); i++)
        name[i] = '\0';
    for(int i = 0; i < color.size(); i++)
        color[i] = '\0';
}

ostream& operator << (ostream& out, const Fruit& x)
{
    out << x.name << " " << x.color << endl;
    return out;
}

istream& operator >> (istream& in,  Fruit& x)
{
    in >> x.name >> x.color;
    return in;
}


int main()
{
     Fruit fruit1;
     cin >> fruit1;
     cout << fruit1;
     cout << "Finished!" ;
    return 0;
}
