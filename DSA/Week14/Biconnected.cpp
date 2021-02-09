/*
 * @Author: Xuekun Li
 * @Date: 2020-12-02 16:57:18
 * @LastEditor: Xuekun Li
 * @LastEditTime: 2020-12-14 13:02:14
 * @Description: Try to code your bug.
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

void Tarjan(int *p, vector<vector<int>> &Graph, int v, int Num[], int Low[], bool visited[], int parent[])
{
    static int counter = 0;
    int children = 0;

    Num[v] = Low[v] = counter++;
    visited[v] = true;

    for(auto &w: Graph[v])
    {
        if(!visited[w]) //如果(v,w)是树边
        {
            children++;
            parent[w] = v;  //设置w的父亲是v
            Tarjan(p, Graph, w, Num, Low, visited, parent); //继续dfs
            Low[v] = min(Low[v], Low[w]);   //更新Low[v]

            if(parent[v] == -1 && children >= 2) //根节点且有两棵以上的子树
                (*p)++;
            else if(parent[v] != -1 && Low[w] >= Num[v]) //不是根节点且Low[w]>=Num[v]
                (*p)++;
        }
        else if(visited[w] && parent[v] != w)
        {
            Low[v] = min(Low[v], Num[w]);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> Graph(n);
        int *Num = new int[n];
        int *Low = new int[n];
        int *parent = new int[n];
        memset(parent, -1, sizeof(int) * n);

        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            Graph[a - 1].push_back(b - 1);
            Graph[b - 1].push_back(a - 1);
        }

        bool *visited = new bool[n];
        memset(visited, false, sizeof(bool) * n);

        int p = 0;
        Tarjan(&p, Graph, 0, Num, Low, visited, parent);

        cout << "Number of AT:" << p << endl;

        delete[] Num;
        delete[] Low;
        delete[] visited;
        delete[] parent;
    }
    return 0;
}