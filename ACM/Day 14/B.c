#include <stdlib.h>

typedef struct ListNode{
	int val;
	struct ListNode* next;
}ListNode;

ListNode* listAdd(ListNode* list1,ListNode* list2)
{
    ListNode *LastNode = NULL;
    ListNode *head = NULL;

    int temp = 0;
    while(list1 != NULL && list2 != NULL)
    {
        ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
        newNode->val = (list1->val + list2->val + temp) % 10;
        newNode->next = NULL;
        temp = (list1->val + list2->val + temp) / 10;
        if(LastNode != NULL)
            LastNode->next = newNode;
        if(LastNode == NULL)
            head = newNode;
        LastNode = newNode;

        list1 = list1->next;
        list2 = list2->next;
    }

    if(list1 == NULL && list2 != NULL)
    {
        while(list2 != NULL)
        {
            ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
            newNode->val = (list2->val + temp) % 10;
            newNode->next = NULL;
            temp = (list2->val + temp) / 10;
            if(LastNode != NULL)
                LastNode->next = newNode;
            if(LastNode == NULL)
                head = newNode;
            LastNode = newNode;
            list2 = list2->next;
        }
    }
    else if(list2 == NULL && list1 != NULL) 
    {
        while(list1 != NULL)
        {
            ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
            newNode->val = (list1->val + temp) % 10;
            newNode->next = NULL;
            temp = (list1->val + temp) /10;
            if(LastNode != NULL)
                LastNode->next = newNode;
            if(LastNode == NULL)
                head = newNode;
            LastNode = newNode;
            list1 = list1->next;
        }
    }
    
    if(temp != 0)
    {
        ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
        newNode->val = temp;
        newNode->next = NULL;
        LastNode->next = newNode;
    }

    return head;
}
