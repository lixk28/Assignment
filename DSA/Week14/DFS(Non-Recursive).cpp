/*
 * @Author: Xuekun Li
 * @Date: 2020-12-02 13:13:56
 * @LastEditor: Xuekun Li
 * @LastEditTime: 2020-12-02 16:44:26
 * @Description: Try to code your bug.
 */
#include <iostream>
#include <stack>
using namespace std;

int **CreateGraph(int n)
{
    int **Graph = new int *[n];
    for (int i = 0; i < n; i++)
        Graph[i] = new int[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            Graph[i][j] = 0;
    
    return Graph;
}


void DeleteGraph(int **Graph, int n)
{
    for (int i = 0; i < n; i++)
        delete[] Graph[i];
    delete[] Graph;
}

void DepthFirstTraverse(int **Graph, int v, int n, int visited[])
{
    stack<int> s;
    s.push(v);
    
    while(!s.empty())
    {
        v = s.top();
        s.pop();
        
        if(visited[v] == 1)
            continue;

        visited[v] = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            if(Graph[v][i] == 1 && visited[i] == 0)
                s.push(i);
        }
    }
}

bool IsConnected(int visited[], int n)
{
    for (int i = 0; i < n; i++)
        if(visited[i] == 0) //if vertex i is not searched
            return false;

    return true;
}

int GetComponents(int **Graph, int n, int visited[])
{
    int num = 1;
    for (int i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
            num++;
            DepthFirstTraverse(Graph, i, n, visited);
        }
    }

    return num;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;

        int **Graph = CreateGraph(n);
        for (int i = 0; i < m; i++)
        {
            int v, w;
            cin >> v >> w;
            Graph[v - 1][w - 1] = Graph[w - 1][v - 1] = 1;
        }

        int *visited = new int[n];
        for (int i = 0; i < n; i++)
            visited[i] = 0;

        DepthFirstTraverse(Graph, 0, n, visited);
        
        bool connect = IsConnected(visited, n);
        if(connect == true)
            cout << "YES, 1 component." << endl;
        else
        {
            cout << "NO, ";
            int component = GetComponents(Graph, n, visited);
            cout << component << " components." << endl;
        }

        DeleteGraph(Graph, n);
        delete[] visited;
    }

    return 0;
}