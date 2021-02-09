/*
 * @Author: Xuekun Li
 * @Date: 2020-11-17 19:38:01
 * @LastEditor: Xuekun Li
 * @LastEditTime: 2020-11-17 21:13:57
 * @Description: Try to code your bug.
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <cstring>
#define MAXSIZE 1000
using namespace std;

struct ArcNode
{
    int adjvex;
    ArcNode *nextarc;
    ArcNode(int _adjvex = -1, ArcNode *_nextarc = NULL)
    {
        adjvex = _adjvex;
        nextarc = _nextarc;
    }
};

struct VexNode
{
    int vertex;
    ArcNode *firstarc;
};

struct ALGraph
{
    int n;
    int e;
    VexNode firstvex[MAXSIZE];
    ALGraph(int _n = 0, int _e = 0)
    {
        n = _n;
        e = _e;
    }
};

ALGraph makeGraph()
{
    int n, m;
    cin >> n >> m;
    ALGraph G(n, m);
    for (int i = 0; i < n; i++)
    {
        (G.firstvex)[i].vertex = i;
        (G.firstvex)[i].firstarc = NULL;
    }

    for (int i = 0; i < m; i++)
    {
        int vertex, adjvertex;
        cin >> vertex >> adjvertex;

        ArcNode *temp = new ArcNode(adjvertex, NULL);
        temp->nextarc = (G.firstvex)[vertex].firstarc;
        (G.firstvex)[vertex].firstarc = temp;
    }

    return G;
}

vector<int> degreeSequence(const ALGraph &G)
{
    int res[G.n];
    memset(res, 0, sizeof(int) * G.n);

    for (int i = 0; i < G.n; i++)
    {
        ArcNode *curr = (G.firstvex + i)->firstarc;
        while(curr != NULL)
        {
            res[i]++;
            res[curr->adjvex]++;
            curr = curr->nextarc;
        }
    }

    sort(res, res + G.n);

    vector<int> ans;
    for (int i = G.n - 1; i >= 0; i--)
        ans.push_back(res[i]);

    return ans;
}

void deleteGraph(ALGraph *G)
{
    for (int i = 0; i < G->n; i++)
    {
        VexNode currvex = (G->firstvex)[i];
        ArcNode *currarc = currvex.firstarc;
        while(currarc != NULL)
        {
            ArcNode *temp = currarc;
            currarc = currarc->nextarc;
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
        ALGraph G = makeGraph();
        vector<int> ans = degreeSequence(G);

        for (unsigned int i = 0; i < ans.size(); i++)
        {
            cout << ans[i];
            if(i == ans.size() - 1)
                cout << endl;
            else
                cout << " ";
        }

        deleteGraph(&G);
    }

    return 0;
}