#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


#define MaxSize 30
#define NullPtr -1

typedef int ValueType;
typedef int Pointer;
typedef int Position;
typedef int Index;
typedef unsigned int SizeType;

typedef struct node{
    ValueType value;
    Pointer next;
}Node;

typedef struct manager{
    Pointer FreeMemory[MaxSize+1];
    Index Top;
}MemoryStack;

struct memoryManager{
    Node Memory[MaxSize];
    struct manager* Manager;
};

typedef struct staticLinkedList{
    Pointer head;
    SizeType size;
}StaticLinkedList;

void iniManager(struct memoryManager* S)
{
    S->Manager=(MemoryStack *)malloc(sizeof(MemoryStack));
    for(int i=0;i<=MaxSize;i++)
        S->Manager->FreeMemory[i]=i-1;
    S->Manager->Top=MaxSize;
}
void releaseManager(struct memoryManager* S)
{
    free(S->Manager);
}

void iniList(StaticLinkedList* List)
{
    List->head=NullPtr;
    List->size=0;
}

bool noMemoryLeft(struct memoryManager *S)
{
    return S->Manager->FreeMemory[S->Manager->Top] == NullPtr;
}

void freed(struct memoryManager *S,Pointer pointer)
{
    S->Manager->FreeMemory[++S->Manager->Top]=pointer;
}

bool allocated(struct memoryManager *S)
{
    if(noMemoryLeft(S))
        return false;
    --S->Manager->Top;
    return true;
}

Pointer top(struct memoryManager *S)
{
    return S->Manager->FreeMemory[S->Manager->Top];
}

Pointer newMemory(struct memoryManager *S,ValueType value)
{
    if(noMemoryLeft(S))
        return NullPtr;
    Pointer p=top(S);
    allocated(S);
    rearrange(S);
    S->Memory[p].value=value;
    S->Memory[p].next=NullPtr;
    return p;
}

void freeMemory(struct memoryManager *S,Pointer pointer)
{
    freed(S,pointer);
    rearrange(S);
}

bool insert(StaticLinkedList* List,struct memoryManager* stack,ValueType value,Position position)
{
    if(position<0 || position>List->size)
        return false;
    
    Pointer temp=newMemory(stack,value);
    if(temp == NullPtr)
        return false;

    if(position == 0)
    {
        stack->Memory[temp].next=List->head;
        List->head=temp;
    }
    else
    {
        Pointer p=List->head;
        for(int i=0;i<position-1;i++)
            p=(stack->Memory[p]).next;
        stack->Memory[temp].next=(stack->Memory[p]).next;
        (stack->Memory[p]).next=temp;
    }

    ++List->size;
    return true;
}
Pointer erase(StaticLinkedList* List,struct memoryManager* stack,Position position)
{
    if(position<0 || position>=List->size)
        return false;
    
    --List->size;
    Pointer p=List->head;

    if(position == 0)
    {
        List->head=stack->Memory[List->head].next;
        freeMemory(stack,p);
        return List->head;
    }
    else
    {
        for(int i=1;i <= position;i++)
            p=stack->Memory[List->head].next;
        Pointer temp=(stack->Memory[p]).next;
        (stack->Memory[p]).next=(stack->Memory[temp]).next;
        freeMemory(stack,temp);
        return (stack->Memory[p]).next;
    }
}

bool pushBack(StaticLinkedList* List,struct memoryManager* stack,ValueType value)
{
    return insert(List,stack,value,List->size);
}

bool popBack(StaticLinkedList* List,struct memoryManager* stack)
{
    erase(List,stack,List->size-1);
    return true;
}

void show(StaticLinkedList*,struct memoryManager*);