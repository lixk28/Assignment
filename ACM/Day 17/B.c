#include <stdio.h>

int n, T;
int a[40];
int sum = 0, count = 0;

void find(int num)
{
    if(num == n + 1)
    {
        count++;
        return;
    }
    
    if(sum + a[num] <= T)
    {
        sum = sum + a[num];
        find(num+1);
        sum = sum - a[num];
    }
    find(num+1);
    return;
}

int main()
{
    scanf("%d %d", &n, &T);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    find(1);
    printf("%d", count);

    return 0;
}