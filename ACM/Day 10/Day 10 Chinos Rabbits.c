#include <stdio.h>
#define N (1<<20)+1
int odd[N], even[N];

int main()
{
    int n;
    scanf("%d", &n);
    n = (1<<n);
    int odd_len = 0, even_len = 0;
    for(int i = 0; i < n; i++)
    {
        int MOFUMOFU;
        scanf("%d", &MOFUMOFU);
        if(MOFUMOFU & 1)
            odd[odd_len++] = MOFUMOFU;
        else
            even[even_len++] = MOFUMOFU;
    }
    
    int odd_index = 0, even_index = 0;
    while(odd_index < odd_len && even_index < even_len)
    {
        if(odd[odd_index] < even[even_index])
            printf("%d ", odd[odd_index++]);
        else
            printf("%d ", even[even_index++]);
    }
    
    while(odd_index < odd_len)
        printf("%d ", odd[odd_index++]);
    while(even_index < even_len)
        printf("%d ", even[even_index++]);

    return 0;
}