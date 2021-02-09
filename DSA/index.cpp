#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>
#include <list>
#include <string>
using namespace std;

void Insert(string key, list<pair<string, vector<int> > >& L, int line)
{
    list<pair<string, vector<int> > >::iterator it;
    it = L.begin();
    while(it != L.end() && key > (*it).first)
        it++;
    
    if(it != L.end() && key == (*it).first)
    {
        int flag = 0;
        for(int i = 0; i < ((*it).second)[i]; i++)
        {
            if(line == ((*it).second)[i])
                flag = 1;
        }
        if(flag == 0)
            ((*it).second).push_back(line);
    }
    else
    {
        vector<int> t (1, line);
        L.insert(it, pair<string, vector<int> >(key, t));
    }

}

void Search(vector<string> keys, vector<string> lines, list<pair<string, vector<int> > >& Index)
{
    for(int i = 0; i < keys.size(); i++)
    {
        string key = keys[i];
        int len = key.length();
        for(int j = 0; j < lines.size(); j++)
        {
            for(int k = 0; k < lines[j].length(); k++)
            {
                if(key == lines[j].substr(k, len))
                    Insert(key, Index, j + 1);
            }
        }
    }
}

void Print_Index(list<pair<string, vector<int> > > index)
{
    list<pair<string, vector<int> > >::iterator it;
    for(it = index.begin(); it != index.end(); it++)
    {
        cout << std::left << setw(15) << (*it).first;
        for(int i = 0; i < ((*it).second).size(); i++)
        {
            cout << ((*it).second)[i];
            if(i != ((*it).second).size() - 1)
                cout << ",";
            else 
                cout << endl;
        }
    }
}

int main()
{
    string key;
    vector<string> keys;
    cout << "Please input the number of the keys:" << endl;
    int n;
    cin >> n;
    cout << "Please input the keys:" << endl;
    while(n--)
    {
        cin >> key;
        keys.push_back(key);
    }

    string line;
    vector<string> lines;
    cout << "Please input the lines of the text:" << endl;
    cin >> n;
    cout << "Please input the text:" << endl;
    cin.get();
    while(n--)
    {   
        getline(cin, line);
        lines.push_back(line);
    }

    list<pair<string, vector<int> > > index;
    Search(keys, lines, index);
    Print_Index(index);

    return 0;
}
