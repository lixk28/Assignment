#include <iostream>
#include <string>
using namespace std;

class Object
{
    public:
        Object(int a = 0) { n = a; }
        virtual int getn() { return n; }
    protected:
        int n;
};

class Animal: public Object
{
    public:
        Animal(int a = 1): Object(a) {}
        virtual int getn() { return n; }
};

class Dog: public Animal
{
    public:
        Dog(int a = 2): Animal(a) {}
        virtual int getn() { return n; }
};

class Cat:public Animal
{
    public:
        Cat(int a = 3): Animal(a) {}
        virtual int getn() { return n; }
};

class Vehicle: public Object
{
    public:
        Vehicle(int a = 4): Object(a) {}
        virtual int getn() { return n; }
};

class Car: public Vehicle
{
    public:
        Car(int a = 5): Vehicle(a) {}
        virtual int getn() { return n; }
};

class Bus: public Vehicle
{
    public:
        Bus(int a = 6): Vehicle(a) {}
        virtual int getn() { return n; }
};

class Person: public Animal
{
    public:
        Person(int a = 7): Animal(a) {}
        virtual int getn() { return n; }
};

class Student: public Person
{
    public:
        Student(int a = 8): Person(a) {}
        virtual int getn() { return n; }
};

class Teacher: public Person
{
    public:
        Teacher(int a = 9): Person(a) {}
        virtual int getn() { return n; }
};

string instanceof(Object x)
{
    int n = x.getn();
    switch (n)
    {
        case 0: return "Object"; break;
        case 1: return "Animal"; break;
        case 2: return "Dog"; break;
        case 3: return "Cat"; break;
        case 4: return "Vehicle"; break;
        case 5: return "Car"; break;
        case 6: return "Bus"; break;
        case 7: return "Person"; break;
        case 8: return "Student"; break;
        case 9: return "Teacher"; break;
    }
}

int main()
{
 Object *obj = new Dog();
 cout << instanceof(*obj) << endl;

 obj = new Animal();
 cout << instanceof(*obj) << endl;
 obj = new Car();
 cout << instanceof(*obj) << endl;

 obj = new Bus();
 cout << instanceof(*obj) << endl;
 obj = new Cat();
 cout << instanceof(*obj) << endl;

 obj = new Vehicle();
 cout << instanceof(*obj) << endl;
 obj = new Teacher();
 cout << instanceof(*obj) << endl;
 obj = new Person();
 cout << instanceof(*obj) << endl;
 obj = new Student();
 cout << instanceof(*obj) << endl;
 obj = new Object();
 cout << instanceof(*obj) << endl;

 //system("pause");
 return 0;
}
