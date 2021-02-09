#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n][m];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);

    int b[m];
    int max = 0;
    for(int i = 0; i < n; i++)
    {
        memset(b, 0, sizeof(b));
        for(int j = i; j < n; j++)
        {
            int sum = 0;
            for(int k = 0; k < m; k++)
            {
                b[k] = b[k] + a[j][k];
                sum = sum + b[k];
                if(sum > max)
                    max = sum;
                if(sum < 0)
                    sum = 0;
            }
        }
    }

    printf("%d", max);

    return 0;
}