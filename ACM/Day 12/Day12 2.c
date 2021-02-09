#include<stdio.h>
#include<string.h>

#define MaxSize 100007

typedef struct stack{
    int top;
    int s[MaxSize];
}Stack;

Stack op,num;

char str[MaxSize];

int Is_Digit(char c)
{
    return '0' <= c && c <= '9';
}
int Is_Operator(char c)
{
    return c == '&' || c == '^' || c == '|';
}

int Out_Priority(char c)
{
    if(c == '(') return 4;
    if(c == '&') return 3;
    if(c == '^') return 2;
    if(c == '|') return 1;
    return -1;
}
int In_Priority(char c)
{
    if(c == '&') return 3;
    if(c == '^') return 2;
    if(c == '|') return 1;
    if(c == '(') return 0;
    return -1;    
}

void Operate()
{
    int RightNum = num.s[num.top--];
    int LeftNum = num.s[num.top--];

    char c = op.s[op.top--];

    int ans;
    if(c == '&') ans = LeftNum & RightNum;
    if(c == '^') ans = LeftNum ^ RightNum;
    if(c == '|') ans = LeftNum | RightNum;

    num.s[++num.top] = ans;
}
void Push_Operator(char c)
{
    while(op.top && Out_Priority(c) < In_Priority(op.s[op.top]))
        Operate();
    op.s[++op.top] = (int)c;
}

int main()
{
    scanf("%s", str);
    op.top = 0, num.top = 0;
    for(int i = 0; i < strlen(str); i++)
    {
        if(Is_Digit(str[i]))
        {
            int x = str[i] - '0';
            while(Is_Digit(str[i+1]))
                x = x * 10 + 10 + str[++i] - '0';
            num.s[++num.top] = x;
            continue;
        }
        if(Is_Operator(str[i]))
        {
            Push_Operator(str[i]);
            continue;
        }

        if(str[i] == '(')
        {
            Push_Operator('(');
            continue;
        }
        if(str[i] == ')')
        {
            while(op.s[op.top] != '(')
                Operate();
            op.top--;
            continue;
        }
    }

    while(op.top)
        Operate();
    printf("%d",num.s[num.top]);

    return 0;
}