/*
 * @Author: Xuekun Li
 * @Date: 2020-11-18 16:53:36
 * @LastEditor: Xuekun Li
 * @LastEditTime: 2020-11-25 16:59:08
 * @Description: Try to code your bug.
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <cstddef>
using namespace std;

struct ArcNode
{
    int adjvex;
    ArcNode *nextarc;
};

struct VexNode
{
    int vertex;
    ArcNode *firstarc;
};

struct ALGraph
{
    int n;  //the number of vertex
    int e;  //the number of edge
    vector<VexNode> AdjList;    //adjacency list
};

void DFS(ALGraph &G, int v, int visited[])
{
    visited[v] = 1;
    ArcNode *curr = ((G.AdjList)[v]).firstarc;
    while(curr != NULL)
    {
        int w = curr->adjvex;
        if(visited[w] == 0)
            DFS(G, w, visited);
        curr = curr->nextarc;
    }
}

bool ExistPath(ALGraph &G, int u, int v, int visited[])
{
    DFS(G, u, visited);
    
    if(visited[v] == 1)
        return true;
    else
        return false;
}

void DeleteGraph(ALGraph &G)
{
    for (unsigned int i = 0; i < G.AdjList.size(); i++)
    {
        VexNode vertex = (G.AdjList)[i];
        ArcNode *curr = vertex.firstarc;
        while(curr != NULL)
        {
            ArcNode *temp = curr;
            curr = curr->nextarc;
            delete temp;
        }
    }
}


int main()
{
    int t;
    cin >> t;
    while(t--) 
    {
        unsigned int n, m;
        cin >> n >> m;  

        ALGraph G;
        G.n = n;
        G.e = m;

        for (unsigned int i = 1; i <= n; i++)
        {
            VexNode curr;
            curr.vertex = i - 1;
            curr.firstarc = NULL;
            (G.AdjList).push_back(curr);
        }
        
        for (unsigned int i = 1; i <= m; i++)
        {
            int vertex, adjvex;
            cin >> vertex >> adjvex;

            ArcNode *curr1 = new ArcNode;
            curr1->adjvex = adjvex - 1;
            curr1->nextarc = NULL;

            ArcNode *curr2 = new ArcNode;
            curr2->adjvex = vertex - 1;
            curr2->nextarc = NULL;

            curr1->nextarc = (G.AdjList)[vertex - 1].firstarc;
            (G.AdjList)[vertex - 1].firstarc = curr1;

            curr2->nextarc = (G.AdjList)[adjvex - 1].firstarc;
            (G.AdjList)[adjvex - 1].firstarc = curr2;
        }

        int visited[n];
        memset(visited, 0, sizeof(int) * n);

        int flag = 0;
        for (unsigned int i = 0; i < n; i++)
        {
            for (unsigned int j = 1; j < n; j++)
            {
                if(i == j)
                    continue;
                    
                if(ExistPath(G, i, j, visited) == false)
                    flag = 1;

                memset(visited, 0, sizeof(int) * n);
            }
        }

        if(flag == 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;

        DeleteGraph(G);
    }

    return 0;
}