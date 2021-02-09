#include <stdio.h>
#define JUST_CHECK

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int sum[n+1];
    for(int i = 1; i <= n; i++)
    {
        int tmp;
        scanf("%d", &tmp);

        if(i == 1)
            sum[i] = tmp;
        else
            sum[i] = tmp + sum[i-1];
    }
    sum[0] = 0;

    #ifndef JUST_CHECK
        for(int i = 1; i <= n; i++)
            printf("%d ", sum[i]);
    #endif

    while(m--)
    {
        int L, R;
        scanf("%d %d", &L, &R);
        printf("%d\n", sum[R] - sum[L-1]);
    }


    return 0;
}