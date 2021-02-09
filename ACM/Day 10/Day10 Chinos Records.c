#include<stdio.h>
#include<malloc.h>
#define JUST_CHECK

typedef struct rabbit{
    int Mao;
    int Min;
    int Zhan;
}Rabbit;

void QuickSort(Rabbit *rabbits,int begin,int end)
{
    if(begin >= end)
        return ;

    int i=begin;
    int j=end;
    Rabbit key=rabbits[begin];

    while(i<j)
    {
        while(i<j && \
                (
                    (rabbits+j)->Mao < key.Mao || \
                    ((rabbits+j)->Mao == key.Mao && (rabbits+j)->Min > key.Min) || \
                    ((rabbits+j)->Mao == key.Mao && (rabbits+j)->Min == key.Min && (rabbits+j)->Zhan <= key.Zhan) \
                )
            ) 
        j--;
        *(rabbits+i)=*(rabbits+j);

        while(i<j && \
                (
                    ((rabbits+i)->Mao > key.Mao) || \
                    ((rabbits+i)->Mao == key.Mao && (rabbits+i)->Min < key.Min) || \
                    ((rabbits+i)->Mao == key.Mao && (rabbits+i)->Min == key.Min && (rabbits+i)->Zhan >= key.Zhan) \
                )
            )
        i++;

        *(rabbits+j)=*(rabbits+i);
    }

    *(rabbits+i)=key;
    QuickSort(rabbits,begin,i-1);
    QuickSort(rabbits,i+1,end);
}
int main()
{
    int n;
    scanf("%d",&n);
    Rabbit* rabbits=(Rabbit *)malloc(sizeof(Rabbit)*n);
    for(int i=0;i<n;i++)
        scanf("%d %d %d",&rabbits[i].Zhan,&rabbits[i].Min,&rabbits[i].Mao);

    QuickSort(rabbits,0,n-1);

    for(int i=0;i<n;i++)
    {
        if(i<n-1 && (rabbits[i].Zhan == rabbits[i+1].Zhan && rabbits[i].Min == rabbits[i+1].Min && rabbits[i].Mao == rabbits[i+1].Mao))
            continue;
        else
            printf("%d %d %d\n",rabbits[i].Zhan,rabbits[i].Min,rabbits[i].Mao);
    }

    free(rabbits);
    
    return 0;
}