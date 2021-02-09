#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct queuenode{
    int card; // A(1) or B(0)
    struct queuenode *next; // next card
}QueueNode;

typedef struct queue{
    QueueNode *front; 
    QueueNode *rear;
    int length;
}Queue;

void Init_Queue(Queue *queue);
void Pop_front(Queue *queue); // Pop the front of the queue 
int Get_topcard(Queue *queue); // get the top card of cardpile
void Push_rear(Queue *queue, int val); // Push elements at the rear
bool Is_Empty(Queue *queue);
void Destroy_Queue(Queue *queue);

int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    Queue card_pile;
    Init_Queue(&card_pile);
    int A[m]; // record the position of A cards

    for(int i=0;i<m;i++)
        scanf("%d",&A[i]);
    
    for(int i=1,j=0; i<=n; i++) 
    {
        if(i == A[j]) // meet the position of A card
        {
            Push_rear(&card_pile,1);
            j++;
        }
        else // meet the position of B card
            Push_rear(&card_pile,0);
    }

    for(int i=1;i<=k;i++)
    {
        int temp=Get_topcard(&card_pile);
        Pop_front(&card_pile);

        if(temp == 1) // A card
            Push_rear(&card_pile,1);
        else if(temp == 0) // B card
        {
            Push_rear(&card_pile,0);
            Push_rear(&card_pile,0);
        }
    }

    printf("%d\n",card_pile.length);
    Destroy_Queue(&card_pile);

    return 0;
}

void Init_Queue(Queue *queue)
{
    queue->front=NULL;
    queue->rear=NULL;
    queue->length=0;
}

bool Is_Empty(Queue *queue) // judge whether the queue is empty
{
    if(queue->length == 0)
        return true;
    else
        return false;
}

void Push_rear(Queue *queue, int val) // val=0/1 representing A/B
{
    QueueNode *temp=(QueueNode *)malloc(sizeof(QueueNode));
    temp->card=val;
    temp->next=NULL;

    if(Is_Empty(queue)) // if the queue is empty
    {
        queue->front=temp;
        queue->rear=temp;
    }
    else
    {
       queue->rear->next=temp;
       queue->rear=temp;
    }

    (queue->length)++; // the length of the queue +1
}

void Pop_front(Queue *queue)
{
    if(Is_Empty(queue)) // if the queue is empty, end
        return ;

    QueueNode *temp=queue->front;
    queue->front=temp->next;
    free(temp);

    (queue->length)--; // the length of the queue -1
}

int Get_topcard(Queue *queue)
{
    return queue->front->card;
}

void Destroy_Queue(Queue *queue)
{
    QueueNode *temp;
    while(queue->front != NULL)
    {
        temp=queue->front;
        queue->front=temp->next;
        free(temp);
    }
}