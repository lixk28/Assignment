#include "list.h"

List* creatList()
{
	List *head=(List *)malloc(sizeof(List));
	head->next=NULL;
	return head;
}

int getValue(List* myList,int index) 
{
	if(index<=0)
		return 0;
    if(myList == NULL)
        return 0;
	
	for(int i=1;i<index;i++)
    {
        myList=myList->next;
        if(myList == NULL)
		    return 0;
    }
    
	return myList->val;
}

void addAtHead(List* myList,int val) 
{
	List *newhead=(List *)malloc(sizeof(List));
	newhead->val=val;
	newhead->next=myList->next;
	myList->next=newhead;
}

void addAtTail(List* myList,int val) 
{
	List *tail=(List *)malloc(sizeof(List));
	tail->val=val;
	tail->next=NULL;
	while(myList->next)
		myList=myList->next;
	myList->next=tail;
}

int addAtIndex(List* myList,int index,int val) //clear1
{
	if(index <= 0)
		return 0;
		
	for(int i=1;i<index;i++)
	{
		myList=myList->next;
		if(myList == NULL)
			return 0;
	}
	
	List *node=(List *)malloc(sizeof(List));
    node->val=val;
	node->next=myList->next;
	myList->next=node;
	
	return 1;
}

int deleteAtHead(List* myList)
{
	if(myList->next == NULL)
		return 0;
        
	List *temp=myList->next;
	List *newhead=temp->next;
	free(temp);
	myList->next=newhead;
	
	return 1;
}

int deleteAtIndex(List* myList,int index) //clear1
{
	if(index <= 0)
		return 0;
	if(myList->next == NULL)
        return 0;

	List *prev=myList;
	myList=myList->next;
	index--;
	while(index--)
	{
		myList=myList->next;
		prev=prev->next;
		if(myList == NULL)
			return 0;
	}
	
	prev->next=myList->next;
	free(myList);
	
	return 1;
}

void reverseList(List* myList) //clear1
{
	if(myList->next == NULL)
		return;
	List *prev=myList;
	myList=myList->next;
	List *p1=myList,*p2=myList->next,*p3=NULL;
	while(p2 != NULL)
	{
		p1->next=p3;
		p3=p1;
		p1=p2;
		p2=p2->next;
	}
	p1->next=p3;
	prev->next=p1;
}

void printList(List* myList) //clear
{
	List *temp=myList->next;
	while(temp != NULL)
	{
		printf("%d->",temp->val);
		temp=temp->next;
	}
	printf("null\n");
}

void freeList(List* myList)
{
	List *cur=myList;
	List *temp=NULL;
	while(cur != NULL)
	{
		temp=cur->next;
		free(cur);
		cur=temp;
    }
}