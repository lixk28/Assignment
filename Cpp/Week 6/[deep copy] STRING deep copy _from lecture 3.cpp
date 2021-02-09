#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class STRING {
private:	
      int     length;
      char  *buffer;
public:	
      STRING();
      STRING(const char *str);
      ~STRING();
	  STRING& operator=(const STRING &another);
};

STRING::STRING()
{
    length = 0;
    buffer = NULL;
}

STRING::STRING(const char *str)
{
    length = strlen(str);
    buffer = new char[length];
    for(int i = 0; i < length; i++)
        buffer[i] = str[i];
}

STRING::~STRING()
{
    delete[] buffer;
}

STRING& STRING::operator=(const STRING &another)
{
    length = another.length;
    delete[] buffer;
    buffer = new char[length];
    for(int i = 0; i < length; i++)
        buffer[i] = another.buffer[i];
}

int main()
{
    STRING stra("This");
    STRING strb("That");
    stra = strb;
    cout<<"success";
    return 0;
}