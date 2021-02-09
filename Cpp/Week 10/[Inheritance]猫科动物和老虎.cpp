#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

class Cat
{
    public:
        Cat();
        Cat(int n);
        ~Cat();
    private:
        int data;
};

Cat::Cat() 
{ 
    data = 0;
    cout << "Default Constructor of Cat is Running" << endl ;
}

Cat::Cat(int n)
{
    data = n;
    cout << "Constructor of Cat is Running " << data << endl;
}

Cat::~Cat()
{
    cout << "Destructor of Cat is Running " << data << endl;
}


class Tiger: public Cat
{
    public:
        Tiger(int n);
        ~Tiger();
    private:
        int data;
};

Tiger::Tiger(int n): Cat(n)
{
    data = n;
    cout << "Constructor of Tiger is Running " << data << endl;
}

Tiger::~Tiger()
{
    cout << "Destructor of Tiger is Running " << data << endl;
}


int main()
{
 Tiger t1(9);
 Cat c1;
 Tiger t2(25);

 return 0;
}
