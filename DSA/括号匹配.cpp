#include <iostream>
using namespace std;

struct Node
{
    char c;
    Node *next;
    Node(char c = '\0', Node *next = NULL): c(c), next(next) {}
};

class Stack
{
    private:
        Node *top;
        Node *bottom;
        int size;
    public:
        Stack();
        ~Stack();

        Node *getTop() const;

        void push(char c);
        void pop();

        bool Is_Empty() const;
};

Stack::Stack()
{
    bottom = new Node; 
    top = bottom;
    size = 0;
}

Stack::~Stack()
{
    Node *move = bottom;
    while(move != NULL)
    {
        Node *temp = move;
        move = move->next;
        delete temp;
    }
}

Node *Stack::getTop() const
{
    return top;
}

void Stack::push(char c)
{
    Node *newTop = new Node(c, NULL);
    top->next = newTop;
    top = newTop;
    size++;
}

void Stack::pop()
{
    Node *temp = bottom;
    while(temp->next != top)
        temp = temp->next;
    top = temp;
    delete temp->next;
    top->next = NULL;
    size--;
}

bool Stack::Is_Empty() const
{
    if(size == 0)
        return true;
    else
        return false;
}

int matches(string e)
{
    Stack s;

    for(int i = 0; i < e.size(); i++)
    {
        if(e[i] == '(' || e[i] == '[' || e[i] == '{')
            s.push(e[i]);
        else if(e[i] == ')' || e[i] == ']' || e[i] == '}')
        {
            if(s.Is_Empty() == true)
                return 3;

            Node *top = s.getTop();
            if((top->c == '(' && e[i] == ')') || (top->c == '[' && e[i] == ']') || (top->c == '{' && e[i] == '}'))
            {
                s.pop();
                continue;
            }
            else
                return 1;
        }
        else
            continue;
    }

    if(s.Is_Empty() == true)
        return 0;
    else if(s.Is_Empty() == false)
        return 2;
}

int main()
{
    string e;
    while(1)
    {
        cin >> e;
        cout << matches(e) << endl;
    }

    return 0;
}