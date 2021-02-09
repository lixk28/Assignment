#include <iostream>
#include <cstring>
#define MAX 51
using namespace std;

class Vector {
    public:
        Vector() 
        {
            name = "";
            dimension = 0;
            param = NULL;
        }
        Vector(string, int, int[]);
        Vector(const Vector &otherVec);
        ~Vector();
        void isEqual(const Vector &);
        void setName(string);
        void print();
    private:
        string name;
        int dimension, *param;
};

Vector::Vector(string s, int a, int* p)
{
    name = s;
    dimension = a;
    param = p;
    cout << "construct a vector called " << name << ".\n";
}

Vector::Vector(const Vector &otherVec)
{
    param = otherVec.param;
    name = otherVec.name;
    dimension = otherVec.dimension;
    cout << "copy a vector called " << name << ".\n" ;
}

Vector::~Vector()
{
    cout << "release memory from a vector called " << name << ".\n";
}

void Vector::isEqual(const Vector &otherVec)
{
    int value_flag;
    if(this->dimension != otherVec.dimension)
        value_flag = 0;
    else
    {
        int count = 0;
        for(int i = 0; i < this->dimension; i++)
            if((this->param)[i] == (otherVec.param)[i])
                count++;
        if(count == this->dimension)
            value_flag = 1;
    }

    if(this->name == otherVec.name)
    {
        if(value_flag == 1)
            cout << "same name, same value.\n";
        else
            cout << "same name, different value.\n";
    }
    else
    {
        if(value_flag == 1)
            cout << "different name, same value.\n";
        else
            cout << "different name, different value.\n";

    }
}

void Vector::setName(string s)
{
    name = s;
}

void Vector::print()
{
    cout << this->name << "(" << (this->param)[0];
    for(int i = 1; i < this->dimension; i++)
        cout << ", " << (this->param)[i];
    cout << ")\n";
}

int main() 
{
    string name = "";
    int dim, num[MAX];
    cin >> name >> dim;
    for (int i = 0; i < dim; i++) {
        cin >> num[i];
    }
    Vector vec1(name, dim, num);
    vec1.print();
    Vector vec2(vec1);
    vec2.print();
    vec1.isEqual(vec2);
    int vec3_num[] = {1, 2, 3};
    Vector vec3(name, 3, vec3_num);
    vec1.isEqual(vec3);
    vec2.setName("helloWorld!");
    vec1.isEqual(vec2);
     return 0;
}