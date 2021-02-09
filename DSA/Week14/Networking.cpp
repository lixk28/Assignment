/*
 * @Author: Xuekun Li
 * @Date: 2020-12-05 21:14:50
 * @LastEditor: Xuekun Li
 * @LastEditTime: 2020-12-07 13:32:47
 * @Description: Try to code your bug.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#define M 10000000
using namespace std;

int **CreateGraph(int n)
{
    int **Graph = new int *[n];
    for (int i = 0; i < n; i++)
        Graph[i] = new int[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if(i == j)
                Graph[i][j] = 0;
            else
                Graph[i][j] = M;
        }

    return Graph;
}

void DeleteGraph(int **Graph, int n)
{
    for (int i = 0; i < n; i++)
        delete[] Graph[i];
    delete[] Graph;
}

int Prim(int **Graph, int v, int n)
{
    vector<int> lowcost(n, 0);
    vector<int> closest(n, 0);

    for (int i = 0; i < n; i++)
    {
        lowcost[i] = Graph[v][i];
        closest[i] = v;
    }

    int ans = 0;
    int k = 0;
    for (int i = 1; i < n; i++)
    {
        int MIN = M;
        for (int j = 0; j < n; j++)
        {
            if(lowcost[j] != 0 && lowcost[j] < MIN)
            {
                MIN = lowcost[j];
                k = j;
            }
        }

        ans += MIN;
        lowcost[k] = 0;

        for (int j = 0; j < n; j++)
        {
            if(lowcost[j] != 0 && Graph[k][j] < lowcost[j])
            {
                lowcost[j] = Graph[k][j];
                closest[j] = k;
            }
        }
    }

    return ans;
}

int main()
{
    while(true)
    {
        int n, m;
        cin >> n;
        if(n == 0)
            break;  //exit
        cin >> m;

        int **Graph = CreateGraph(n);

        while(m--)  //get edges
        {
            int v, w, weight;
            cin >> v >> w >> weight;
            if((Graph[v - 1][w - 1] == 0) || (Graph[v - 1][w - 1] > weight))
            {
                Graph[v - 1][w - 1] = weight;
                Graph[w - 1][v - 1] = weight;
            }
        }

        int ans = Prim(Graph, 0, n);

        cout << ans << endl;

        DeleteGraph(Graph, n);
    }

    return 0;
}