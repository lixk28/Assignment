#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node* next;
}ListNode;

ListNode *Create_List();
void Init_List(ListNode *List,int length);
int Get_Position(ListNode *List,int val);
void Change(ListNode **List,int pos);
void Show(ListNode *List);
void Destroy_List(ListNode *List);

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    ListNode *List=Create_List();
    Init_List(List,n);

    for(int i=1;i<=m;i++)
    {
        int temp;
        scanf("%d",&temp);
        int pos=Get_Position(List,temp);
        Change(&List,pos);
    }

    Show(List);
    Destroy_List(List);

    return 0;
}

ListNode *Create_List()
{
    ListNode *head=(ListNode *)malloc(sizeof(ListNode));
    head->next=NULL;
    return head;
}

void Init_List(ListNode *List,int length)
{
    for(int i=1;i<=length;i++)
    {
        if(i == 1)
            List->val=1;
        else
        {
            ListNode *temp=(ListNode *)malloc(sizeof(ListNode));
            temp->val=i;
            temp->next=NULL;
            List->next=temp;
            List=List->next;
        }
    }
}

int Get_Position(ListNode *List,int val)
{
    int pos=1;
    while(List->val != val)
    {
        pos++;
        List=List->next;
    }
    return pos;
}

void Change(ListNode **List,int pos)
{
    ListNode *curr = *List;
    if(pos == 1)
        return;
    
    for(int i=1;i<pos-1;i++)
        curr=curr->next;
    ListNode *temp=curr->next;
    curr->next=curr->next->next;

    ListNode *newhead=(ListNode *)malloc(sizeof(ListNode));
    newhead->val=temp->val;
    newhead->next=*List;
    *List=newhead; 

    free(temp);
}

void Show(ListNode *List)
{
    while(List != NULL)
    {
        if(List->next == NULL)
            printf("%d\n",List->val);
        else
            printf("%d ",List->val);
        List=List->next;
    }
}

void Destroy_List(ListNode *List)
{
    while(List != NULL)
    {
        ListNode *temp=List;
        List=List->next;
        free(temp);
    }
}