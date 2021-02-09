#include<iostream>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

int sumOfIntersection(const set<int>& set1, const set<int>& set2)
{
    int sum = 0;
    set<int>::iterator iter1;
    set<int>::iterator iter2;
    for(iter1 = set1.begin(); iter1 != set1.end(); iter1++)
    {
        if(set2.find(*iter1) != set2.end())
            sum = sum + *iter1;
    }
    return sum;
}


int main()
{
	//freopen("test01.in", "r", stdin);
	//freopen("test01.out", "w", stdout);

	set<int> s1,s2;
	int n,k;
	cin>>n;
	while(n--) {
		cin>>k;
		s1.insert(k);
	}
	cin>>n;
	while(n--) {
		cin>>k;
		s2.insert(k);
	}
	cout<<s1.size()<<endl;
	for(set<int>::iterator i=s1.begin();i!=s1.end();i++) {
		cout<<*i<<' ';
	}
	cout<<endl;
	cout<<s2.size()<<endl;
	for(set<int>::iterator i=s2.begin();i!=s2.end();i++) {
		cout<<*i<<' ';
	}
	cout<<endl;
	cout<<sumOfIntersection(s1,s2)<<endl;

	return 0;
}