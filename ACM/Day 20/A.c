#include <stdio.h>


int n, m;
int set[1000007] = {0};

void init_set(int n)
{
    for(int i = 1; i <= n; i++)
        set[i] = i;
}

int find_root(int x)
{
    int y, tmp;
    y = x;
    while(y != set[y])
        y = set[y];
    while(x != y)
    {
        tmp = set[x];
        set[x] = y;
        x = tmp;
    }
    return x;
}

void connect(int i, int j)
{
    int root1, root2;
    root1 = find_root(i);
    root2 = find_root(j);
    if(root1 != root2)
        set[root1] = root2;
}

int main()
{
    scanf("%d %d", &n, &m);
    while(getchar() != '\n')
        continue;

    init_set(n);
    while(m--)
    {
        char c;
        int i, j;
        scanf("%c %d %d",&c ,&i, &j);
        while(getchar() != '\n')
            continue;

        if(c == 'c')
            connect(i, j);
        else if(c == 'q')
        {
            if(find_root(i) == find_root(j))
                printf("Connected!\n");
            else 
                printf("Not connected!\n");
        }
    }

    return 0;
}