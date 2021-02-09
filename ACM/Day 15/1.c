#include <stdio.h>

long long d[10000009];

int main()
{
    int n;
    scanf("%d", &n);
    d[1]=0,d[2]=1;
    for(int i=3; i<=n; i++)
        d[i]=((i-1) * (d[i-1] + d[i-2]))%(int)(1e9+9);

    printf("%lld", d[n]);

    return 0;
}