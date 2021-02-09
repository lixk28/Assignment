#include<iostream>

using namespace std;

typedef int Stack_entry;

class Stack
{
    private:
        Stack_entry s[100];
        int length;
    public:
        Stack();
        Stack(const Stack &original);
        ~Stack();

        bool empty() const;
        int size() const;
        const Stack_entry &top() const;

        void push(const Stack_entry &item);
        void pop();

        void operator=(const Stack &original);
};

Stack::Stack()
{
    for(int i = 0; i < 100; i++)
        s[i] = 0;
    length = 0;
}

Stack::Stack(const Stack &original)
{
    length = original.length;
    for(int i = 0 ; i < length; i++)
        s[i] = (original.s)[i];
}

Stack::~Stack()
{
    length = 0;
}

bool Stack::empty() const
{
    if(length == 0 )
        return true;
    else
        return false;
}

int Stack::size() const
{
    return length;
}

const Stack_entry& Stack::top() const
{
    return s[length - 1];
}

void Stack::push(const Stack_entry &item)
{
    s[length++] = item;
}

void Stack::pop()
{
    s[length - 1] = 0;
    length--;
}

void Stack::operator=(const Stack &original)
{
    length = original.length;
    int i;
    for(i = 0; i < length; i++)
        s[i] = (original.s)[i];

    for(int j = i; j < 100; j++)
        s[j] = 0;
}

void print(Stack s){
  if (!s.empty()){
     cout <<"top:"<<s.top() << endl;
  }
  cout <<"size:"<<s.size()<<endl;
  cout <<"-------"<<endl;
}


int main(){

  Stack s;
  int N = 100;
  for (int i=1; i<=N; i++){
     s.push(3*i);
  }
  print(s);

  // more testing

  return 0;
}






