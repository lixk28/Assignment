#include <iostream>
using namespace std;

class INTEGER
{
public:
      INTEGER(int i = 0); // 构造函数

      INTEGER(const INTEGER &other); // 拷贝构造函数

      // 友元重载加法运算符
      friend INTEGER operator+(INTEGER left, INTEGER right);
      
      void print();
private:
      int value; // 私有数据
};

INTEGER::INTEGER(int i)
{
    value = i;
}

INTEGER::INTEGER(const INTEGER &other)
{
    value = other.value;
}

void INTEGER::print()
{
    cout << value;
}

INTEGER operator+(INTEGER left, INTEGER right)
{
    INTEGER t(left.value + right.value);
    return t;
}

int main()
{
    INTEGER x(10); // 定义整数对象，用构造函数来初始化
    INTEGER y = x; // 定义整数对象，用拷贝构造函数来初始化
    INTEGER z;     // 定义整数对象，用构造函数的缺省参数初始化

    y = x + 2;  // 合法调用
    z = 30 + y; // 也是合法的调用
    z.print();
    return 0;
}

