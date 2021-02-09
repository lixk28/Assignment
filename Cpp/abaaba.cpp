#include <iostream>
using namespace std;

void exchange(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    int i, j, r, s, n, k = 0;

    cin >> n;
    int a[n];
    while(k < n)
        cin >> a[k++];

    i = n - 2;
    while(a[i] > a[i+1])
        i = i -1;

    j = n - 1;
    while(a[i] > a[j])
        j = j - 1;
    
    exchange(a+i, a+j);

    r = n - 1;
    s = i + 1;
    while(r > s)
    {
        exchange(a+r, a+s);

        r = r - 1;
        s = s + 1;
    }

    k = 0;
    while(k < n)
        cout << a[k++] << " ";

    return 0;
}