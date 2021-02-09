#include <stdlib.h>

typedef struct ListNode{
	int val;
	struct ListNode* next;
}ListNode;

ListNode** splitList1(ListNode* head)
{
    ListNode **ans = (ListNode **)malloc(sizeof(ListNode *)*2);
    if(head == NULL || head->next == NULL)
    {
        ans[0] = head;
        ans[1] = NULL;
        return ans;
    }
    
    ListNode *prev = (ListNode *)malloc(sizeof(ListNode));
    prev->next = head;
    ListNode *temp = prev;
    ListNode *slow = head;
    ListNode *fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        temp = temp->next;
    }
    if(fast != NULL)
    {
        temp = temp->next;
        slow = slow->next;
    }
    temp->next = NULL;
    
    ans[0]=head;
    ans[1]=slow;
    free(prev);

    return ans;
}

ListNode** splitList2(ListNode* head,int k)
{
    ListNode **ans = (ListNode **)malloc(sizeof(ListNode *)*2);
    if(head == NULL || k == 0)
    {
        ans[0] = head;
        ans[1] = NULL;
        return ans;
    }

    ListNode *prev = (ListNode *)malloc(sizeof(ListNode));
    prev->next = head;
    ListNode *temp = prev;
    ListNode *slow = head;
    ListNode *fast = head;

    while(k--)
        fast = fast->next;

    while(fast != NULL)
    {
        temp = temp->next;
        slow = slow->next;
        fast = fast->next;
    }
    
    temp->next = NULL;
    ans[0] = prev->next;
    ans[1] = slow;
    free(prev);

    return ans;
}

ListNode** splitList3(ListNode* head,int x)
{
    ListNode **ans = (ListNode **)malloc(sizeof(ListNode *)*2);
    if(head == NULL)
    {
        ans[0] = head;
        ans[1] = NULL;
        return ans;
    }

    ListNode *prev1 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *prev2 = (ListNode *)malloc(sizeof(ListNode));
    prev1->next = NULL;
    prev2->next = NULL;
    ListNode *curr1 = prev1;
    ListNode *curr2 = prev2;

    while(head != NULL)
    {
        if(head->val > x)
        {
            curr1->next = head;
            curr1 = curr1->next;
        }
        else 
        {
            curr2->next =head;
            curr2 = curr2->next;
        }
        head = head->next;
    }

    curr1->next = NULL;
    curr2->next = NULL;
    ans[0] = prev1->next;
    ans[1] = prev2->next;
    free(prev1);
    free(prev2);

    return ans;
}
