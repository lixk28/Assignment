#include <iostream>
#include <iomanip>
#include <utility>
#include <list>
#include <string>
using namespace std;

void Delete(string& word)
{
    string::iterator it;
    for(it = word.begin(); it != word.end(); it++)
    {
        if( !( (*it >= 'a' && *it <= 'z') || (*it >= 'A' && *it <= 'Z') ) )
        {
            word.erase(it);
            it--;
        }
    }
}

void Insert(string word, list<pair<string, int> >& L)
{
    list<pair<string, int> >::iterator it;
    it = L.begin();
    while(it != L.end() && word > (*it).first)
        it++;
    
    if(it != L.end() && word == (*it).first)
        (*it).second++;
    else
        L.insert(it, pair<string, int>(word, 1));
}

void Print_List(list<pair<string, int> > L)
{
    list<pair<string, int> >::iterator it;
    for(it = L.begin(); it != L.end(); it++)
    {
        cout << std::left << setw(15) << (*it).first;
        cout << std::right << setw(3) << (*it).second << endl;
    }
}

int main()
{
    list<pair<string, int> > L;
    string word;
    while(cin >> word)  // 输入ctrl+z即可停止
    {
        Delete(word);
        Insert(word, L);
    }
    Print_List(L);

    return 0;
}


