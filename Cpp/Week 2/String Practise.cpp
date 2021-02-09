#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

char s[10];
string MyStringPractise(const string &s1, const string &s2)
{
    int count = 0;
    for(int i = 0; i < 3 && i < s1.size(); i++)
    {
        s[i] = s1[i];
        count++;
    }
    int index = count;
    int j;
    if(s2.size() <= 3)
        j = 0;
    else
        j = s2.size() - 3;
    for(index, j; j < s2.size(); j++, index++)
        s[index] = s2[j];
    return s;
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	cout << MyStringPractise(s1, s2) << endl;
	return 0;
}