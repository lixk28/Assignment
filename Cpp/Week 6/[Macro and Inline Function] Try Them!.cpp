#include <iostream>
#include <cassert>

//my_macro.hpp
#define MACRO_MAX(X,Y) ((X) > (Y) ? (X): (Y))
#define MACRO_SWAP(X,Y) int t = X; X = Y; Y = t

//my_inline.hpp
inline int inline_MAX(int a, int b)
{
    return a > b ? a : b;
}

inline void inline_SWAP(int &a, int &b)
{
    int t;
    t = a;
    a = b;
    b = t;
}

using std::cout;
using std::cin;
using std::endl;

int main() {
  // Check if you really use a macro to do this
//   CHECK_MACRO;

  int a = 0, b = 0;
  cin >> a >> b;
  cout << a << " " << b << endl;

  int res = inline_MAX(a, b);
  cout << "inline_MAX: " << res << endl;
  inline_SWAP(a, b);
  cout << "inline_SWAP: " << a << " " << b << endl;

  res = MACRO_MAX(a, b);
  cout << "MACRO_MAX: " << res << endl;
  MACRO_SWAP(a, b);
  cout << "MACRO_SWAP: " << a << " " << b << endl;
  
  return 0;
}