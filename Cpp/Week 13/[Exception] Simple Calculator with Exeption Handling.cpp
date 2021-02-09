#include <sstream>
#include <string>

class Utils {
 public:
  static std::string int2String(int num) {
    std::stringstream ss;
    ss << num;
    return ss.str();
  }
};

class Exception {
 public:
  virtual const std::string what() const throw() { return "Exception occors"; };
};

class ExpressionException : public Exception {
 public:
  virtual const std::string what() const throw() {
    return "ExpressionException";
  }
};

class IllegalSymbolException : public ExpressionException {
 private:
  int position;

 public:
  IllegalSymbolException(int position) : position(position) {}
  virtual const std::string what() const throw() {
    return "IllegalSymbolException at position:" + Utils::int2String(position);
  }
};

class MissingOperatorException : public ExpressionException {
 private:
  int position;

 public:
  MissingOperatorException(int position) : position(position) {}
  virtual const std::string what() const throw() {
    return "Expected operator at position:" + Utils::int2String(position);
  }
};

class MissingOperandException : public ExpressionException {
 private:
  int position;

 public:
  MissingOperandException(int position) : position(position) {}
  virtual const std::string what() const throw() {
    return "Expected operand at position:" + Utils::int2String(position);
  }
};

class EmptyExpressionException : public ExpressionException {
 public:
  EmptyExpressionException() {}
  virtual const std::string what() const throw() {
    return "The expression is empty";
  }
};

class calculator
{
    public:
        calculator() {}
        int calculate(std::string exp);
};

int calculator::calculate(std::string exp)
{
    int size = exp.size();
    int result = exp[0] - 48;
    if(size == 0)
    {
        EmptyExpressionException e;
        throw e;
    }

    for(int i = 0; i < size; i++)
    {
        if(exp[i] >= '0' && exp[i] <= '9')
        {
            if(i < size - 1 && exp[i + 1] >= '0' && exp[i + 1] <= '9')
            {
                MissingOperatorException e(i + 1);
                throw e;
            }
            else
                continue;    
        }
        else if(exp[i] == '+' || exp[i] == '-')
        {
            if(i == 0)
            {
                MissingOperandException e(i);
                throw e;
            }
            else if(i == size - 1)
            {
                MissingOperandException e(i + 1);
                throw e;
            }
            else if(exp[i + 1] == '+' || exp[i + 1] == '-')
            {   
                MissingOperandException e(i + 1);
                throw e; 
            }

            if(exp[i] == '+')
                result += (exp[i + 1] - 48);
            if(exp[i] == '-')
                result -= (exp[i + 1] - 48);
        }
        else
        {
            IllegalSymbolException e(i);
            throw e;
        }
    }

    return result;
}


#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
  calculator c;
  std::string str;
  bool flag;

  while (cin >> str) {
    flag = false;
    try {
      cout << c.calculate(str) << endl;
    } catch(EmptyExpressionException e) {
      cout << e.what() << endl;
      flag = true;
    } catch(MissingOperatorException e) {
      cout << e.what() << endl;
      flag = true;
    } catch(MissingOperandException e) {
      cout << e.what() << endl;
      flag = true;
    } catch(IllegalSymbolException e) {
      cout << e.what() << endl;
      flag = true;
    } catch(ExpressionException e) {
      cout << e.what() << endl;
      flag = true;
    } catch(Exception e) {
      // unhandled exception
      throw e;
    }
    if (!flag) {
      std::cout << "No exception happened!" << std::endl;
    }
  }

  return 0;
}

