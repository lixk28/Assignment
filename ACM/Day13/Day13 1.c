#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int sum=0;
    while(n--)
    {
        int temp;
        scanf("%d",&temp);
        sum=sum^temp;
    }
    printf("%d",sum);

    return 0;
}