#include <iostream>
#include <string>
#include <exception>
using namespace std;

int calc(int a, int b)
{
  if (a<0) throw "Out of range exeception";
  else if (b<0) throw "Out of range exeception";
  else if (a<b) throw "Minuend smaller than subtrahend";
  return a-b;
}

void test(int a, int b)
{
    try{
        int c = calc(a,b);
        cout << c << endl;
    } catch(const char* error) {
        cout << error << endl;
    }
}

int main()
{
  
  test(3,1);
  test(-3,1);
  test(1,-3);
  test(1,3);
  return 0;
}
