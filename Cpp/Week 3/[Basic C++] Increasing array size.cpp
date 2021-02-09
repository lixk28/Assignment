#include <iostream>
using namespace std;

int *doubleCapacity(int *list, int size)
{
    int *p;
    p = new int[2*size];
    for(int i = 0; i < 2*size; i++)
    {
        if(i < size)
            p[i] = list[i];
        else p[i] = 0;
    }
    return p;
}

int main()
{
    int list[5]={1,2,3,4,5};
    int *newlist = doubleCapacity(list,5);
    for(int i=0;i < 2*5;i++)
        cout << *(newlist+i) << " ";

    return 0;
}