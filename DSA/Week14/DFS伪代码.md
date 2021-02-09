`Algorithm: Depth First Traverse(non-recursive)`

`Input: A undirected graph G, and the source vertex v`

`Output: The sequence of depth first traversal `

~~~C++
function DFS(Graph G, vertex v)
    stack s		
    s.push(v)
    
    while(s is not empty)
        w <= s.top
        s.pop
        
        if(visited[w] == 1)
            continue
        else
            visit w
           	visited[w] <= 1
        
        for each adjacent vertex i of w
            if(visited[i] == 0)
                s.push(i)
~~~

---

`Algorithm:按深度优先遍历的次序给访问过的节点依次编号`

`Input:无向图G, 遍历的源顶点v `

`Output:顶点及其访问的次序  `

~~~C++
function DFS_Number(Graph G, vertex v)
    static int count = 1
    number[v] = count++	//number[i] is the number of i being visited
    visited[v] = 1	//visited[i] is 1 if vertex i is visited
    
    for each adjacent vertex w of v
        if(visited[w] == 0)
            DFS_Number(G, w)
~~~

---

`Algorithm:按深度优先遍历的次序给访问过的节点逆序编号`

`Input:无向图G, 遍历的源顶点v `

`Output:顶点及其访问的次序（逆序）  `

~~~C++
function DFS_Reverse_Number(Graph G, vertex v)
    static int count = G.n	//count is the number of vertices
    number[v] = count--
    visited[v] = 1	
    
    for each adjacent vertex w of v
        if(visited[w] == 0)
            DFS_Reverse_Number(G, w)
~~~

---

