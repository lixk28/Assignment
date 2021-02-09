#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void DFS1(vector<vector<int>> G, int visited[], int v, int number[])
{
    static int count1 = 1;
    number[v] = count1++;
    visited[v] = 1;

    for(int &w: G[v])
    {
        if(visited[w] == 0)
            DFS1(G, visited, w, number);
    }
}

void DFS2(vector<vector<int>> G, int visited[], int v, int number[], int n)
{
    static int count2 = n;
    number[v] = count2--;
    visited[v] = 1;

    for(int &w: G[v])
    {
        if(visited[w] == 0)
            DFS2(G, visited, w, number, n);
    }
}

int main()
{
    vector<vector<int>> G(5);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int v, w;
        cin >> v >> w;
        G[v].push_back(w);
    }

    int *visited1 = new int[5];
    int *visited2 = new int[5];
    int *number1 = new int[5];
    int *number2 = new int[5];
    memset(visited1, 0, sizeof(int) * 5);
    memset(visited2, 0, sizeof(int) * 5);
    memset(number1, 0, sizeof(int) * 5);
    memset(number2, 0, sizeof(int) * 5);

    DFS1(G, visited1, 0, number1);
    DFS2(G, visited2, 0, number2, 5);

    cout << "Number1: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "vertex" << i << " ";
        cout << number1[i] << endl;
    }
    cout << endl;

    cout << "Number2: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "vertex" << i << " ";
        cout << number2[i] << endl;
    }
    cout << endl;

    delete[] visited1;
    delete[] visited2;
    delete[] number1;
    delete[] number2;

    return 0;
}