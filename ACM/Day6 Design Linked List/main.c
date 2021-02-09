#include"list.h"

int main()
{
    List* myList=creatList();
    addAtHead(myList,1);
    addAtTail(myList,2);
    addAtIndex(myList,0,0);
    addAtIndex(myList,2,0);
    deleteAtHead(myList);
    deleteAtIndex(myList,2);
    deleteAtHead(myList);
    printList(myList);
    freeList(myList);

    return 0;
}