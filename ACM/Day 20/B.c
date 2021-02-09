#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAXN (int)(1e6)

typedef struct heap 
{
    int* heap; 
    int len;
}Heap;

//1、初始化堆
void InitHeap(Heap* h)
{
    h->heap = malloc(MAXN*sizeof(int));
    h->len = 0;
}

//2、清除堆
void ClearHeap(Heap* h)
{
    if (h->heap != NULL)
    {
        free(h->heap);
        h->len = 0;
    }
}

//3、检查一个堆是否为空
int EmptyHeap(Heap* h)
{
    if (h->len == 0)
        return 1;
    else
        return 0;
}

//4、向堆中插入一个元素
void InsertHeap(Heap* h, int x)
{
    int i;
    h->heap[h->len] = x; 
    h->len++;
    i = h->len - 1; 
    while (i != 0)
    {
        int j = (i - 1) / 2; 
        if (x <= h->heap[j]) 
            break;
        h->heap[i] = h->heap[j]; 
        i = j; 
    }
    h->heap[i] = x;
}

//5、从堆中删除堆顶元素并返回
int DeleteHeap(Heap* h)
{
    int temp, x;
    int i, j;
    temp = h->heap[0]; 
    h->len--;
    if (h->len == 0) 
        return temp;
    x = h->heap[h->len]; 
    i = 0; 
    j = 2 * i + 1;
    while (j <= h->len - 1)
    {
        if (j < h->len - 1 && h->heap[j] < h->heap[j+1])
            j++;
        if (x >= h->heap[j]) 
            break;
        h->heap[i] = h->heap[j];
        i = j; 
        j = 2 * i + 1;
    }
    h->heap[i] = x; 
    return temp; 
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    while(getchar() != '\n')
        ;
    Heap heap;
    InitHeap(&heap);
    for(int i = 0; i < n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        getchar();
        InsertHeap(&heap, tmp);
    }

    while(m--)
    {
        char c;
        int x;
        scanf("%c", &c);
        if(c == 'q')
            printf("%d\n", DeleteHeap(&heap));
        else if(c == 'a')
        {
            scanf("%d", &x);
            InsertHeap(&heap, x);
        }
        while(getchar() != '\n')
            ;
    }
    while(!EmptyHeap(&heap))
        printf("%d\n", DeleteHeap(&heap));

    ClearHeap(&heap);

    return 0;
}