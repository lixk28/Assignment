#include <iostream>
#define JUST_CHECK
using namespace std;

typedef string T;

struct Node
{
    //data members
    T data;
    Node *next;
    //constructors
    Node() { next = NULL;};
    Node(T item, Node *add_on = NULL)
    {
        data = item;
        next = add_on;
    };
};

Node *foo()
{
    Node *temp1 = new Node("Programming", NULL);
    Node *temp2 = new Node("is", NULL);
    Node *temp3 = new Node("fun", NULL);
    temp1->next = temp2;
    temp2->next = temp3;

    return temp1;
}

void Destroy(Node *head)
{
    while(head != NULL)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    Node *list = foo();
    #ifdef JUST_CHECK
        Node *temp = list;
        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    #endif

    Destroy(list);

    return 0;
}