#include <string>
#include <iostream>
using namespace std;

class MyInteger
{
  private:
    int value;
  public:
    MyInteger(int);
    int getValue() const;
    bool isEven() const;
    bool isOdd() const;
    bool isPrime() const;
    static bool isEven(int);
    static bool isOdd(int);
    static bool isPrime(int);
    static bool isEven(const MyInteger&);
    static bool isOdd(const MyInteger&);
    static bool isPrime(const MyInteger&);
    bool equals(int);
    bool equals(const MyInteger&);
    static int parseInt(const std::string&);
};

MyInteger::MyInteger(int n)
{
    value = n;
}

int MyInteger::getValue() const
{
    return value;
}

bool MyInteger::isEven() const
{
    if(value % 2 == 0)
        return true;
    else
        return false;
}

bool MyInteger::isOdd() const
{
    if(value % 2 != 0)
        return true;
    else
        return false;
}

bool MyInteger::isEven(int n)
{
    if(n % 2 == 0)
        return true;
    else
        return false;
}
bool MyInteger::isOdd(int n)
{
    if(n % 2 != 0)
        return true;
    else
        return false;
}

bool MyInteger::isPrime(int n)
{
    if(n == 1)
        return false;
    int i, flag = 1;
    for(i = 2; i <= n / 2; i++)
        if(n % i == 0)
            flag = 0;
    if(flag == 1)
        return true;
    else
        return false;
}

bool MyInteger::equals(int n)
{
    if(value == n)
        return true;
    else
        return false;
}

bool MyInteger::equals(const MyInteger& a)
{
    if(value == a.value)
        return true;
    else
        return false;
}

bool MyInteger::isEven(const MyInteger& a)
{
    if(a.value % 2 == 0)
        return true;
    else
        return false;
}

bool MyInteger::isOdd(const MyInteger& a)
{
    if(a.value % 2 != 0)
        return true;
    else
        return false;
}

bool MyInteger::isPrime(const MyInteger& a)
{
    if(a.value == 1)
        return false;
    int i, flag = 1;
    for(i = 2; i <= a.value / 2; i++)
        if(a.value % i == 0)
            flag = 0;
    if(flag == 1)
        return true;
    else
        return false;
}

bool MyInteger::isPrime() const
{
    if(value == 1)
        return false;
    int i, flag = 1;
    for(i = 2; i <= value / 2; i++)
        if(value % i == 0)
            flag = 0;
    if(flag == 1)
        return true;
    else
        return false;
}

int MyInteger::parseInt(const std::string& s)
{
    int sum = 0;
    if(s[0] == '-')
    {
        int weight = 1;
        for(int i = s.size()-1; i >= 1; i--)
        {
            sum = sum + (s[i] - '0') * weight;
            weight = weight * 10;
        }
        return -sum;
    }
    else
    {
        int weight = 1;
        for(int i = s.size()-1; i >= 0; i--)
        {
            sum = sum + (s[i] - '0') * weight;
            weight = weight * 10;
        }
        return sum;
    }
}

int main() {
    const string words[3][2] = {"not even", "even",
                                "not odd", "odd",
                                "not prime", "prime"};
    int a, b, c, d, e;
    string num;
    cin >> a >> b >> c;
    cin >> d >> e;
    cin >> num;

    MyInteger myInt(a);
    cout << "Integer "  << myInt.getValue() << " is: ";
    cout << words[0][myInt.isEven()] << ", ";
    cout << words[1][myInt.isOdd()] << ", ";
    cout << words[2][myInt.isPrime()] << ".\n";

    cout << "Integer "  << b << " is: ";
    cout << words[0][MyInteger::isEven(b)] << ", ";
    cout << words[1][MyInteger::isOdd(b)] << ", ";
    cout << words[2][MyInteger::isPrime(b)] << ".\n";

    MyInteger myInt2(c);
    cout << "Integer "  << myInt2.getValue() << " is: ";
    cout << words[0][MyInteger::isEven(myInt2)] << ", ";
    cout << words[1][MyInteger::isOdd(myInt2)] << ", ";
    cout << words[2][MyInteger::isPrime(myInt2)] << ".\n";

    MyInteger myInt3(d);
    MyInteger myInt4(e);
    if (myInt3.equals(e) && myInt3.equals(myInt4))
        cout << d << " and " << e << " are equal.\n";
    else
        cout << d << " and " << e << " are not equal.\n";

    cout << "String '" << num << "' convert to "
         << MyInteger::parseInt(num) << endl;

    return 0;
}