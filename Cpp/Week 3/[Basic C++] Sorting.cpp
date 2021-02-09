#include <iostream>
using namespace std;

int *sort(const int * const array, int size)
{   
    int *a = new int[size];
    for(int i = 0; i < size; i++)
        a[i] = array[i];
    
    for(int i = 0; i < size - 1; i++)
    {
        int temp;
        for(int j = i + 1; j < size; j++)
        {
            if(a[j] < a[i])
            {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
    return a;
}

int main()
{
    int array[10] = {9,8,1,2,5,0,4,3,6,7};
    int *a = sort(array, 10);
    for(int i = 0; i < 10; i++)
        cout << a[i] << " ";

    return 0;
}