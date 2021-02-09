#include <stdio.h>

void *(*pf[3])(char *p);
void *fun1(char *p)
{
    printf("fun1:%s\n",p);
    return p;
}

void *fun2(char *p)
{
    printf("fun2:%s\n",p);
    return p;
}

void *fun3(char *p)
{
    printf("fun3:%s\n",p);
    return p;
}

int main()
{
    pf[0] = fun1;
    pf[1] = fun2;
    pf[2] = fun3;
    (*(pf[0]))("test");
    (*(pf[1]))("test");
    (*(pf[2]))("test");

    return 0;
}
