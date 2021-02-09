#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class baseA
{
    public:
        baseA();
        ~baseA();
};

class baseB
{
    public:
        baseB();
        ~baseB();
};

class derivedA: public baseA
{
    public:
        derivedA();
        ~derivedA();
};

class derivedB: public baseA, public baseB
{
    public:
        derivedB();
        ~derivedB();
};

class C: public derivedA, public derivedB
{
    public:
        C();
        ~C();
};

 baseA::baseA() {
    cout << "base A" << endl;
}
 baseA::~baseA() {
    cout << "~ base A" << endl;
}
 baseB::baseB() {
    cout << "base B" << endl;
}
 baseB::~baseB() {
    cout << "~ base B" << endl;
}
 derivedA::derivedA() {
    cout << "derived A" << endl;
}
 derivedA::~derivedA() {
    cout << "~ derived A" << endl;
}
 derivedB::derivedB() {
    cout << "derived B" << endl;
}
 derivedB::~derivedB() {
    cout << "~ derived B" << endl;
}
 C::C() {
    cout << "C" << endl;
}
 C::~C() {
    cout << "~ C" << endl;
}
 
int main() {
    int token;
    cin >> token;
    cout << "test token: " << token << endl;
    cout << "\ncreat base A" << endl;
    baseA ba;
    cout << "\ncreat base B" << endl;
    baseB bb;
    cout << "\ncreat derived A" << endl;
    derivedA da;
    cout << "\ncreat derived B" << endl;
    derivedB db;
    cout << "\ncreat C" << endl;
    C c;
    cout << "\ndestructor" << endl;
    return 0;
}