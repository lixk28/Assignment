#include <iostream>
using namespace std;

template <typename T> class Queue
{
    public:
        Queue();
        ~Queue();
        Queue(const Queue &rhs);
        const Queue & operator = (const Queue &rhs);
        bool empty() const;
        bool full() const;
        int size() const;
        bool push(const T &x); 
        bool pop();
        const T & front() const;
        void display() const;

    private:
        T a[100];
        int head;
        int rear;
        int _size;
};

template <typename T>
Queue<T>::Queue()
{
    head = 0;
    rear = 0;
    _size = 0;
}

template <typename T>
Queue<T>::~Queue() {}

template <typename T>
Queue<T>::Queue(const Queue &rhs)
{
    for(int i = 0; i < 100; i++)
        a[i] = (rhs.a)[i];
    _size = rhs._size;
}

template <typename T>
int Queue<T>::size() const
{
    return _size;
}

template <typename T>
const Queue<T> & Queue<T>::operator = (const Queue &rhs)
{
    for(int i = 0; i < 100; i++)
        (this->a)[i] = (rhs.a)[i];
    this->_size = rhs._size;

    return (*this);
}

template <typename T>
bool Queue<T>::empty() const
{
    return _size == 0;
}

template <typename T>
bool Queue<T>::full() const
{
    return _size == 100;
}

template <typename T>
bool Queue<T>::push(const T &x)
{
    if(full())
        return false;
    
    rear = (rear + 1) % 100;
    a[rear] = x;
    _size++;
    return true;
}

template <typename T>
bool Queue<T>::pop()
{
    if(empty())
        return false;
    
    head = (head + 1) % 100;
    _size--;
    return true;
}

template <typename T>
const T & Queue<T>::front() const
{
    return a[(head + 1) % 100];
}



int main()
{
    Queue<int> q;
    for(int i = 1; i <= 10; i++)
        q.push(i);
    cout << q.size() << endl;
    if(q.full())
        cout << "full" << endl;
    q.display();

    q.pop();
    q.pop();
    cout << q.size() << endl;
    q.display();

    Queue<int> p = q;
    p.display();

    p.pop();

    Queue<int> x(p);
    x.display();

    return 0;
}