#include <stdio.h>

typedef struct node_queue{
    int index;
    int value;
}node_queue;
node_queue new_node;
node_queue min_queue[1100000],max_queue[1100000];
int max_ans[1100000], min_ans[1100000];
int min_head = 0, min_tail = 0, max_head = 0, max_tail = 0;

typedef struct node{
    double average;
    int length;
}node_stack;
node_stack stack[1100000], now_node;
int top = 0;

int a[1100000];
int total = 0, range = 0;

int main()
{
    scanf("%d %d", &total, &range);
    for(int i = 1; i <= total; i++)
        scanf("%d", &a[i]);

    new_node.index = 1;
    new_node.value = a[1];

    min_head = 1; min_tail = 1; min_queue[min_head] = new_node; min_ans[1] = min_queue[min_head].value;
    max_head = 1; max_tail = 1; max_queue[max_head] = new_node; max_ans[1] = max_queue[max_head].value;

    for(int i =2; i <= total; i++)
    {
        new_node.index = i;
        new_node.value = a[i];

        if(min_queue[min_head].index <= i - range)
            min_head++;
        if(max_queue[max_head].index <= i - range)
            max_head++;
        
        while(new_node.value < min_queue[min_tail].value && min_tail >= min_head)
            min_tail--;
        while(new_node.value > max_queue[max_tail].value && max_tail >= max_head)
            max_tail--;

        min_queue[++min_tail] = new_node;
        max_queue[++max_tail] = new_node;

        min_ans[i] = min_queue[min_head].value;
        max_ans[i] = max_queue[max_head].value;
    }

    printf("%d", max_ans[range]);
    for(int i = range + 1; i <= total; i++)
        printf(" %d", max_ans[i]);
    printf("\n");

    printf("%d", min_ans[range]);
    for(int i = range + 1; i <= total; i++)
        printf(" %d", min_ans[i]);
    printf("\n");

    for(int i = 1; i <= total; i++)
    {
        now_node.length = 1;
        now_node.average = a[i];
        while(top)
        {
            if(now_node.average <= stack[top].average)
            {
                now_node.average = (now_node.average * (double) now_node.length + stack[top].average * (double) stack[top].length) / (now_node.length + stack[top].length);
                now_node.length = now_node.length + stack[top].length;
                top--;
            }
            else break;
        }
        stack[++top] = now_node;
    }

    for(int i = 1; i <= top; i++)
    {
        for(int j =1; j <= stack[i].length; j++)
        {
            if(i + j > 2)
                printf(" ");
            printf("%0.2lf", stack[i].average);
        }
    }

    return 0;
}