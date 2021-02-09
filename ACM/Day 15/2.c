#include <stdio.h>

long long D;
long long S[3000][3000];

int main()
{
    int n, k;
    scanf("%d %d",&n, &k);
    D = (int)(1e9+9);
    S[1][1] = 0, S[0][0] = 0;
    for(int i = 1; i <= n; i++)
    {
        S[i][i] = 1;
        S[i][1] = 1;
        S[i][0] = 0;
    }
    for(int i = 2; i <= n ; i++)
        for(int j = 1; j <= k; j++)
            S[i][j] = (S[i - 1][j] * j + S[i - 1][j - 1]) % D;
    
    printf("%lld",S[n][k]);

    return 0;
}