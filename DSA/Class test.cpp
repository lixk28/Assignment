#include <iostream>
#include <string>
#define JUST_CHECK
using namespace std;

Struct Node
{
    string s
}
Node *foo()
{
    Node *head = new Node;
    Node *temp = head->next;

    temp = new Node("Programming", NULL);
    temp = temp->next;

    temp = new Node("is", NULL);
    temp = temp->next;

    temp = new Node("fun", NULL);
    temp = temp->next;

    return head;
}

int Count(Node *head)
{
    int counter = 0;
    Node *temp = head;
    while(temp->next != NULL)
    {
        counter++;
        temp = temp->next;
    }
    return counter;
}

void Push_Back(Node *head, int data)
{
    Node *tail = head;
    while(tail->next != NULL)
        tail = tail->next;
    Node *newtail = new Node(data, NULL);
    tail->next = newtail;
}


int main()
{
    #ifdef JUST_CHECK

    #endif

    return 0;
}