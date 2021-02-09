#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n, w;
    char c;
    cin>>n>>c>>w;
    
    if(n >= 0)
    {
        cout<<'+';
        cout<<setfill(c)<<setw(w-1)<<left<<n<<endl;
    }
    else
        cout<<setfill(c)<<setw(w)<<left<<n<<endl;

    return 0;
}