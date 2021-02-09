#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int d, Node* n): data(d), next(n) {}
};

Node* Create_List()
{
    Node *head = new Node(0, NULL);
    Node *temp = head->next;
    for(int i = 1; i <= 3; i++)
    {
        temp = new Node(i, NULL);
        temp->next = new Node(0, NULL);
        temp = temp->next;
    }
}

void Traverse_List(Node *head)
{
    Node *temp = head->next;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void Insert_List(Node *head, int num, int index)
{
    Node *prev = head;
    Node *temp = head->next;
    while(--index)
    {
        prev = prev->next;
        temp = temp->next;
    }

    Node *newNode = new Node(num, NULL);
    prev->next = newNode;
    newNode->next = temp;
}



int main()
{


    return 0;
}