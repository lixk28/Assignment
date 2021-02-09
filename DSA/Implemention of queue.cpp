#include <iostream>
using namespace std;

typedef int ElemType;

struct Node
{
    ElemType data;
    Node *next;
};

class queue
{
    private:
        Node *begin;
        Node *end;
        int length;

    public:
        queue();
        ~queue();

        int getlength() const;
        ElemType getdata(int index) const;

        bool Is_Empty() const;
        bool Is_Full() const;

        void Enqueue(ElemType data);
        void Dequeue();
        void Display();
};

queue::queue()
{
    length = 0;
    begin = NULL;
    end = NULL;
}

queue::~queue()
{
    Node *move = begin;
    while(move != NULL)
    {
        Node *temp = move;
        move = move->next;
        delete temp;
    }
}

int queue::getlength() const
{
    return length;
}

ElemType queue::getdata(int index) const
{
    if(index <= 0 || index > length)
        return;
    
    Node *move = begin;
    for(int i = 1; i < index; i++)
        move = move->next;
    
    return move->data;
}



int main()
{


    return 0;
}