#include <iostream> 
#include <list> 
#define NIL -1 
using namespace std; 
  
class Graph 
{ 
    int V;    
    list<int> *adj;   
    void APUtil(int v, bool visited[], int disc[], int low[], int parent[], bool ap[]); 
    public: 
        Graph(int V);
        ~Graph();
        void addEdge(int v, int w);   
        int AP();
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 

Graph::~Graph()
{
    delete[] adj;
}
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); 
    adj[w].push_back(v);  
} 
  
void Graph::APUtil(int u, bool visited[], int disc[], int low[], int parent[], bool ap[]) 
{ 
    static int time = 0; 
    int children = 0; 

    visited[u] = true; 
    disc[u] = low[u] = ++time; 
  
    list<int>::iterator i; 
    for (i = adj[u].begin(); i != adj[u].end(); ++i) 
    { 
        int v = *i;  
  
        if (!visited[v]) 
        { 
            children++; 
            parent[v] = u; 
            APUtil(v, visited, disc, low, parent, ap); 
  
            low[u]  = min(low[u], low[v]); 
  
            if (parent[u] == NIL && children > 1) 
               ap[u] = true; 
            if (parent[u] != NIL && low[v] >= disc[u]) 
               ap[u] = true; 
        } 
        else if (v != parent[u]) 
            low[u]  = min(low[u], disc[v]); 
    } 
} 
  
int Graph::AP() 
{ 
    bool *visited = new bool[V]; 
    int *disc = new int[V]; 
    int *low = new int[V]; 
    int *parent = new int[V]; 
    bool *ap = new bool[V];
  
    for (int i = 0; i < V; i++) 
    { 
        parent[i] = NIL; 
        visited[i] = false; 
        ap[i] = false; 
    } 
  
    for (int i = 0; i < V; i++) 
        if (visited[i] == false) 
            APUtil(i, visited, disc, low, parent, ap);

    int count = 0;
    for (int i = 0; i < V; i++) 
        if (ap[i] == true)
            count++;

    delete[] visited;
    delete[] disc;
    delete[] low;
    delete[] parent;
    delete[] ap;
    
    return count;
} 
  
int main() 
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        Graph g(n);
        while(m--)
        {
            int a, b;
            cin >> a >> b;
            g.addEdge(a - 1, b - 1);
        }

        cout << "Number of AT:" << g.AP() << endl;
    }

    return 0; 
}