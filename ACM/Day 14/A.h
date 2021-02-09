#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode{
	int val;
	struct ListNode* next;
}ListNode;

int hasRing(ListNode* head)
{
    ListNode *fast = head;
    ListNode *slow = head;
    while(slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast)
            return 1;
    }
    return 0;
}

ListNode *findMeet(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while(slow != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)  
			return slow;
    }
}

int entryVal(ListNode* head)
{
    ListNode *step1 = head;
    ListNode *step2 = findMeet(head);
    while(step1 != step2)
    {
        step1 = step1->next;
        step2 = step2->next;
    }
    return step1->val;
}

int nodeNumber(ListNode* head)
{
    int length = 1;
    ListNode *flag = findMeet(head);
    ListNode *step = flag;
    while(step->next != flag)
    {
        step = step->next;
        length++;
    }
    return length;
}