#include<stdio.h>
#include<string.h>
#define FUCK_U_TA_IM_FUCKING_LOVE_U
#define BALL_BALL_NING_ZUO_GE_REN_BA
#define PRINT_N(X) printf("%s",n ## X[row])

char n0[7][10]={"xxxxx","x...x","x...x","x...x","x...x","x...x","xxxxx"},\
    n1[7][10]={"....x","....x","....x","....x","....x","....x","....x"},\
    n2[7][10]={"xxxxx","....x","....x","xxxxx","x....","x....","xxxxx"},\
    n3[7][10]={"xxxxx","....x","....x","xxxxx","....x","....x","xxxxx"},\
    n4[7][10]={"x...x","x...x","x...x","xxxxx","....x","....x","....x"},\
    n5[7][10]={"xxxxx","x....","x....","xxxxx","....x","....x","xxxxx"},\
    n6[7][10]={"xxxxx","x....","x....","xxxxx","x...x","x...x","xxxxx"},\
    n7[7][10]={"xxxxx","....x","....x","....x","....x","....x","....x"},\
    n8[7][10]={"xxxxx","x...x","x...x","xxxxx","x...x","x...x","xxxxx"},\
    n9[7][10]={"xxxxx","x...x","x...x","xxxxx","....x","....x","xxxxx"};

void Get_C(char exp[][150],char *str,int index1,int index2,int index3);
char My_Compare(char s[]);
void Print_Ans(int ans[]);

int main()
{
    char exp[7][150]={'\0'};
    for(int i=0;i<7;i++)
        gets(exp[i]);
    
    int left=0,mid=2,right=4;
    char num[20]={'\0'};
    char str[10]={'\0'};
    for(int i=0, j=0; exp[0][left+i] != '\0' ; i+=6, j++)
    {
        Get_C(exp,str,left+i,right+i,mid+i);
        num[j]=My_Compare(str);
    }

    int num1[10]={0},num2[10]={0};
    int flag=0;
    for(int i=strlen(num)-1, j=9; ;i--,j--)
    {
        if(num[i] == '+')
        {
            flag=i;
            break;
        }
        num1[j]=num[i]-'0';
    }

    for(int i=flag-1, j=9;i>=0;i--,j--)
        num2[j]=num[i]-'0';

    int ans[10]={0};
    int temp=0;
    for(int i=9;i>=0;i--)
    {
        ans[i]=(num1[i]+num2[i]+temp)%10;
        temp=(num1[i]+num2[i]+temp)/10;
    }
    
    Print_Ans(ans);

    return 0;
}

void Get_C(char exp[][150],char *str,int index1,int index2,int index3)
{
    str[0]=exp[0][index1];
    str[1]=exp[1][index2];
    str[2]=exp[2][index1];
    str[3]=exp[3][index3];
    str[4]=exp[4][index1];
    str[5]=exp[5][index2];
    str[6]=exp[6][index1]; 
}

char My_Compare(char s[])
{
    if(!strcmp(s,".x...x."))
        return '1';
    else if(!strcmp(s,"xx.xx.x"))
        return '2';
    else if(!strcmp(s,"xx.x.xx"))
        return '3';
    else if(!strcmp(s,"xxxx.x."))
        return '4';
    else if(!strcmp(s,"x.xx.xx"))
        return '5';
    else if(!strcmp(s,"x.xxxxx"))
        return '6';
    else if(!strcmp(s,"xx...x."))
        return '7';
    else if(!strcmp(s,"xxxxxxx"))
        return '8';
    else if(!strcmp(s,"xxxx.xx"))
        return '9';
    else if(!strcmp(s,"xxx.xxx"))
        return '0';
    else if(!strcmp(s,"...x..."))
        return '+';
    else 
        return '\0';
}

void Print_Ans(int ans[])
{
    int flag=0;
    while(flag<=9 && ans[flag] == 0)
        flag++;

    if(flag == 10)
    {
        for(int i=0;i<7;i++)
            printf("%s\n",n0[i]);
        return ;
    }

    for(int row=0;row<7;row++)
    {
        for(int i=flag;i<10;i++)
        {
            switch (ans[i])
            {
                case 0:PRINT_N(0);break;
                case 1:PRINT_N(1);break;
                case 2:PRINT_N(2);break;
                case 3:PRINT_N(3);break;
                case 4:PRINT_N(4);break;
                case 5:PRINT_N(5);break;
                case 6:PRINT_N(6);break;
                case 7:PRINT_N(7);break;
                case 8:PRINT_N(8);break;
                case 9:PRINT_N(9);break;
            }
            if(i != 9)
                printf("%s",".");
        }
        printf("\n");
    }
}