/*
 * @Author: Xuekun Li
 * @Date: 2020-11-29 16:43:28
 * @LastEditor: Xuekun Li
 * @LastEditTime: 2020-11-29 20:04:27
 * @Description: Try to code your bug.
 */
#include <iostream>
#include <vector>
#define M 10000000
using namespace std;

size_t getMinDistIndex(vector<int> dist, vector<bool> flag)
{
    int min = M;
    size_t w = 0;
    for (size_t i = 0; i < dist.size(); i++)
    {
        if(flag[i] == false && dist[i] <= min)
        {
            min = dist[i];
            w = i;
        }
    }
    return w;
}

vector<int> Dijkstra(int **G, int s, int n)
{
    vector<int> dist(n, M);
    dist[s] = 0;

    vector<bool> flag(n, false);

    for (int i = 1; i <= n; i++)    //consider n vertices
    {
        size_t w = getMinDistIndex(dist, flag); //get the vertex w which has the minimal dist
        flag[w] = true; //vertex w is included

        for (int j = 0; j < n; j++) //find all the adjacent vertices of w
        {
            if(!flag[j] && G[w][j] > 0 && G[w][j] < M && dist[j] > dist[w] + G[w][j])
                dist[j] = dist[w] + G[w][j];
        }
    }

    return dist;
}

void print(vector<int> dist, int s)
{
    for (size_t i = 0; i < dist.size(); i++)
    {
        if(dist[i] < M)
            cout << s + 1 << "-" << i + 1 << ":" << dist[i] << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;  //the number of vertices and edges
        
        int **G = new int*[n];
        for (int i = 0; i < n; i++)
            G[i] = new int[n];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                G[i][j] = 0;

        for (int i = 1; i <= m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w; //edge (u,v) has weight w
            G[u - 1][v - 1] = w;
        }

        int s;  //source vertex
        cin >> s;
        vector<int> dist = Dijkstra(G, s - 1, n);
        print(dist, s - 1);

        for (int i = 0; i < n; i++)
            delete[] G[i];
        delete[] G;
    }

    return 0;
}