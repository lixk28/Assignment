/*
 * @Author: Xuekun Li
 * @Date: 2020-11-12 21:27:11
 * @LastEditor: Xuekun Li
 * @LastEditTime: 2020-11-12 21:57:40
 * @Description: Try to code your bug.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int almatrix[500][500] = {0};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        memset(almatrix, 0, 2500 * sizeof(int));
        unsigned int n, m;
        cin >> n >> m;
        for (unsigned int i = 0; i < m; i++)
        {
            int node1, node2;
            cin >> node1 >> node2;
            almatrix[node1][node2] = 1;
            almatrix[node2][node1] = 1;
        }

        int degreesequence[n] = {0};
        
        for (unsigned int i = 0; i < n; i++)
        {
            for (unsigned int j = 0; j < n; j++)
            {
                if(almatrix[i][j] != 0)
                    degreesequence[i]++;
            }
        }

        sort(degreesequence, degreesequence + n);

        for (unsigned int i = n - 1; i >= 0; i--)
        {
            cout << degreesequence[i];
            if(i == 0)
                cout << endl;
            else
                cout << " ";
        }
    }

    
    return 0;
}
