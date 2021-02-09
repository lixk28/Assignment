#include <stdlib.h> 

typedef struct ListNode{
	int val;
	struct ListNode* next;
	struct ListNode* random; 
}ListNode;

ListNode* copyList(ListNode* head)
{
    if(head == NULL)
        return NULL;
	ListNode *curr=head;
	while(curr != NULL)
	{
		ListNode *newNode=(ListNode *)malloc(sizeof(ListNode));
		newNode->next=curr->next;
		curr->next=newNode;
		newNode->val=curr->val;
		newNode->random=NULL;
		curr=newNode->next;
	}
	
	curr=head;
	while(curr != NULL)
	{
		if(curr->random != NULL)
		{
			curr->next->random=curr->random->next;
		}
		curr=curr->next->next;
	}
	
	ListNode *ans=head->next;
	ListNode *curr1=head;
	ListNode *curr2=ans;
	while(curr1!=NULL && curr2!=NULL)
	{
		curr1->next=curr2->next;
		curr1=curr1->next;
		if(curr1 == NULL)
		{
			curr2->next=NULL;
			break;
		}
		curr2->next=curr1->next;
		curr2=curr2->next;
	}

    return ans;
}