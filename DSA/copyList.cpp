#include "NodeTemplate.h"

template <typename T>
Node<T> *copyList(const Node<T> *head)
{
    if(head == NULL)
        return NULL;

    Node<T> *newHead = new Node<T>(head->entry, NULL);

    Node<T> temp1 = head->next;
    Node<T> temp2 = newHead;

    while(temp1 != NULL)
    {
        Node<T> *newNode = new Node<T>(temp1->entry, NULL);
        temp2->next = newNode;
        temp2 = newNode;
        temp1 = temp1->next;
    }

    return newHead;
}