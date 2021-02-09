#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    char image[m][n];
    char c;
    while((c = getchar()) != '\n')
        ;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            char c = getchar();
            image[i][j] = c; 
        }
        getchar();
    }

    for(int i = 0; i < m; i++)
    {
        for(int k = 0, j = n - 1; k < n / 2; k++, j--)
        {
            char tmp;
            tmp = image[i][k];
            image[i][k] = image[i][j];
            image[i][j] = tmp;
        }
    }

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(image[i][j] == 'd')
                image[i][j] = 'b';
            else if(image[i][j] == 'b')
                image[i][j] = 'd';

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%c", image[i][j]);
            if(j == n - 1)
                printf("\n");
        }
    }

    return 0;
}