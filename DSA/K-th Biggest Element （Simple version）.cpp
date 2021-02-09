#include <iostream>
#include <vector>
#include <cstddef>
using namespace std;

void quick_sort(int left, int right, vector<int> &v)
{
    if(left >= right) return;
	int i, j, flag, temp;
	i = left, j = right;
	flag = v[left];  
	while (i < j)
	{
		while (v[j] <= flag && i < j)
			j--;
		while (v[i] >= flag && i < j)
			i++;
		if(i < j)
		{
			temp = v[i];
			v[i] = v[j];
			v[j] = temp;
		}
	}
	v[left] = v[i];
	v[i] = flag;
	quick_sort(left, i - 1, v);
    quick_sort(i + 1, right, v);
}

int select_kth_biggest(vector<int> v, size_t k)
{
    quick_sort(0, v.size() - 1, v);

    return v[k - 1];
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v;
    
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }

    int num = select_kth_biggest(v, k);

    for(int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << num;


    return 0;
}