#include<stdio.h>

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    if(n%2 != 0)
        printf("%.4f",0);
    else if(n == 0)
        printf("%.4f",1.0);
    else if(n!= 0 && n%2 == 0)
        printf("%.4f",1.0/(n+1));


    return 0;
}