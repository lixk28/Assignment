#include <stdio.h>
#include "A.h"

ListNode *Init_List(ListNode *head);
void Add_AtTail(ListNode *head, int val);
void Create_Loop(ListNode *head, int index);
void Free_List(ListNode *head);
void Untie(ListNode *head, int length);

int main()
{
    int length, n;
    scanf("%d %d", &length, &n);
    ListNode *List = NULL;
    List = Init_List(List);

    int index;
    if(n == 1)
        scanf("%d", &index);

    for(int i=0; i<length ;i++)
    {
        int val;
        scanf("%d", &val);
        Add_AtTail(List, val);
    }
    Create_Loop(List, index);

    if(hasRing(List))
    {
        printf("true\n");
        printf("%d\n", entryVal(List));
        printf("%d\n", nodeNumber(List));
    }
    else
        printf("false\n");

    Untie(List, length);
    Free_List(List);

    return 0;
}

ListNode *Init_List(ListNode *head)
{
    head = (ListNode *)malloc(sizeof(ListNode));
    head->next = NULL;
    return head;
}

void Add_AtTail(ListNode *head,int val)
{
    ListNode *tail = head;
    while(tail->next != NULL)
        tail = tail->next;
    ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
    temp->val = val;
    temp->next = NULL;
    tail->next = temp;
}

void Create_Loop(ListNode *head, int index)
{
    ListNode *tail = head;
    while(tail->next != NULL)
        tail = tail->next;
    
    ListNode *temp = head;
    for(int i=0; i<index ; i++)
        temp = temp->next;
    
    tail->next = temp;
}

void Untie(ListNode *head, int length)
{
    for(int i=1; i<=length; i++)
        head = head->next;
    head->next = NULL;
}

void Free_List(ListNode *head)
{
    while(head != NULL)
    {
        ListNode *temp = head;
        head = head->next;
        free(temp);
    }
}