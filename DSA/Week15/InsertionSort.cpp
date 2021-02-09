/*
 * @Author: Xuekun Li
 * @Date: 2020-12-09 16:24:37
 * @LastEditor: Xuekun Li
 * @LastEditTime: 2020-12-09 17:02:29
 * @Description: Try to code your bug.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void InsertionSort(vector<int> &num)
{
    for (int i = 0; i < num.size() - 1; i++)
    {
        for (int j = i + 1; j < num.size(); j++)
        {
            if(num[j] < num[i])
            {
                int temp = num[j];
                num[j] = num[i];
                num[i] = temp;
            }
        }
    }
}

int main()
{
    vector<int> num;
    int n;
    cin >> n;
    while(n--)
    {
        int temp;
        cin >> temp;
        num.push_back(temp);
    }

    InsertionSort(num);

    for(int& i: num)
        cout << i << " ";
    cout << endl;

    return 0;
}