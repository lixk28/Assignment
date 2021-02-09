#include <iostream>
using namespace std;

const int MAX_LEN = 5;
template<class T>
class Stack
{
    public:
        explicit Stack();
        bool empty() const;
        int size() const;
        const T& top() const;
        void push(const T& x);
        void pop();
    private:
        T data[MAX_LEN];
        int stack_size;
};

template<class T>
Stack<T>::Stack()
{
    for(int i = 0; i < MAX_LEN; i++)
        data[i] = 0;
    stack_size = 0;
}

template<class T>
bool Stack<T>::empty() const
{
    if(stack_size == 0)
        return true;
    else
        return false;
}

template<class T>
int Stack<T>::size() const
{
    return stack_size;
}

template<class T>
const T& Stack<T>::top() const
{
    if(stack_size != 0)
    {
        int i = 0;
        while(i < MAX_LEN - stack_size)
            i++;
        return data[i];
    }
    else
        throw 1;
}

template<class T>
void Stack<T>::push(const T& x)
{
    if(stack_size < 5)
    {
        int i = 0;
        while(i < MAX_LEN - stack_size - 1)
            i++;
        data[i] = x;
        stack_size++;
    }
    else if(stack_size == 5)
    {
        if(x > data[0])
            data[0] = x;
    }
} 

template<class T>
void Stack<T>::pop()
{
    if(stack_size == 0)
        throw 1.0;
    else if(stack_size != 0)
    {
        int i = 0;
        while(i < MAX_LEN - stack_size)
            i++;
        data[i] = 0;
        stack_size--;
    }
}

int main() {
    Stack<int> s;
    cout << s.size() << endl;
    for (int i = 10; i < 15; i++) {
        s.push(i);
        cout << s.size() << endl;
    }
    cout << s.size() << endl;
    s.push(12);
    cout << s.top() << endl;
    cout << s.size() << endl;
    s.push(16);
    cout << s.top() << endl;
    cout << s.size() << endl;

    for (int i = 5; i >= 0; i--) {
        try {
            cout << s.top() << endl;
        }
        catch(int int_e) {
            cout << "get top failed" << endl;
        }

        try {
            s.pop();
        }
        catch(double dou_e) {
            cout << "pop failed" << endl;
        }

        cout << s.size() << endl;
    }

    for (int i = 10; i < 15; i++) {
        s.push(i);
        cout << s.size() << endl;
        cout << s.top() << endl;
    }
    return 0;
}

