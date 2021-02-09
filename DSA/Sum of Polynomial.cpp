#include <iostream>
#include <vector>
#define JUST_CHECK
using namespace std;

typedef pair<int,int> Term; // 第一个分量表示系数，第二个分量表示指数
typedef vector<Term> Polynomial;

void Init_Polynomial(Polynomial &p, int n)
{
    for(int i = 0; i < n; i++)
    {
        int coe, exp;
        cin >> coe;
        cin >> exp;
        p.push_back(make_pair(coe, exp));
    }
}

int Exp_Compare(const Polynomial &p1, const Polynomial &p2, const unsigned int index1, const unsigned int index2)
{
    if(p1[index1].second == p2[index2].second)
        return 1;
    else if(p1[index1].second > p2[index2].second)
        return 2;
    else if(p1[index1].second < p2[index2].second)
        return 3;
    else 
        return 0;
}

Polynomial sum(const Polynomial &p, const Polynomial &q)
{
    if(p.size() == 0 && q.size() == 0)
        return p;
    if(p.size() == 0 && q.size() != 0)
        return q;
    if(q.size() == 0 && p.size() != 0)
        return p;

    Polynomial s;
    unsigned int i = 0, j = 0;
    while(i < p.size() && j < q.size())
    {
        switch (Exp_Compare(p, q, i, j))
        {
            case 1: if(p[i].first + q[j].first != 0) s.push_back(make_pair(p[i].first + q[j].first, p[i].second));
                    i++, j++;
                    break;
            case 2: if(p[i].first != 0) s.push_back(make_pair(p[i].first, p[i].second));
                    i++;
                    break;
            case 3: if(q[j].first != 0) s.push_back(make_pair(q[j].first, q[j].second));
                    j++;
                    break;
        }

        if(i == p.size() && j < q.size())
        {
            for(unsigned int k = j; k < q.size(); k++)
                s.push_back(make_pair(q[k].first, q[k].second));
        }
        else if(i < p.size() && j == q.size())
        {
            for(unsigned int k = i; k < p.size(); k++)
                s.push_back(make_pair(p[k].first, p[k].second));
        }
    }

    return s;
}

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        Polynomial p1, p2, Sum;
        int n1, n2;
        cin >> n1;
        Init_Polynomial(p1, n1);
        cin >> n2;
        Init_Polynomial(p2, n2);
    
        Sum = sum(p1, p2);
        cout << Sum.size() << endl;
        for(unsigned int i = 0; i < Sum.size(); i++)
            cout << Sum[i].first << " " << Sum[i].second << endl;
    }

    return 0;
}