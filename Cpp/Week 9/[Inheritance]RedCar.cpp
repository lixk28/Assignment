#include <iostream>
using namespace std;

class Car
{
    public:
        Car()
        {
            cout << "Construct a car" << endl;
        }
};

class Wheel
{
    public:
        Wheel()
        {
            cout << "Construct a wheel" << endl;
        }
};

class RedCar: public Car
{
    public:
        RedCar()
        {
            cout << "Construct a red car" << endl;
        }
    private:
        Wheel w1, w2, w3, w4;
};


int main() {
  cout << "--- build car ---" << endl;
  Car car;
  cout << endl;

  cout << "--- build wheel ---" << endl;
  Wheel wheel;
  cout << endl;

  cout << "--- build red car ---" << endl;
  RedCar redcar;

  return 0;
}