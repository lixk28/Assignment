#include <stdio.h>
#define JUST_CHECK

int n, count = 0;
int a[30] = {0}, b[15] = {0};
int visit[30] = {0};

void find(int index)
{
    if(index == n + 1)
    {
        count++;
        return ;
    }

    for(int i = 1; i < 2*n - b[index]; i++)
    {
        if(visit[i] == 0 && visit[i+b[index]+1] == 0)
        {
            visit[i] = 1;
            visit[i+b[index]+1] = 1;
            find(index+1);
            visit[i] = 0;
            visit[i+b[index]+1] = 0;
        }
    }
    return ;
}

int main()
{
    scanf("%d", &n);

    for(int i = 1; i <= 2*n; i++)
        scanf("%d", &a[i]);

    for(int i = 1, k = 1; i <= 2*n-1; i++)
    {
        if(a[i] == 0)
            continue;
        int flag = a[i];
        int j = i+1;
        while(a[j] != a[i])
            j++;
        b[k++] = a[i];
        a[i] = a[j] = 0;
    }
    #ifndef JUST_CHECK
        for(int i = 0; i < n; i++)
            printf("%d ", b[i]);
    #endif

    find(1);
    printf("%d", count);

    return 0;
}