#include <iostream>
#include <map>
using namespace std;
int main() {
    map <char, int>m;
    int i;

    //put pairs into map
    //your code
    

    char ch;
    cout <<"enter key:";
    cin >>ch;
    map<char, int>::iterator p;

    //find value given key ch
    //your code
    p = m.find(ch);

    if (p!=m.end())
        cout <<"Its ASCII value is " <<p->second;
    else
        cout <<"Key not in map." ;
    return 0;
}