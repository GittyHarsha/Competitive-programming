/*
code by harsha_76

*/


#include<bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, bool> visited;
    map<int, list<int>> adj;
    
    public:
    
    void addEdge(int u, int v);
    void dfs(int v);
    void bfs(int v);
    
};

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

void Graph::dfs(int v)
{
    visited[v]=true;
    cout<<v<<' ';
    
    list<int>::iterator it;
    
    for(it= adj[v].begin(); it!=adj[v].end();it++)
    {
        if(!visited[*it])
        {
            dfs(*it);
        }
        
    }
}

void Graph::bfs(int v)
{
    
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    Graph g;
    g.addEdge(0, 1); g.addEdge(1, 2); g.addEdge(2, 3); g.addEdge(0, 4); g.addEdge(4, 5); g.addEdge(5, 6);
    g.dfs(0);
    return 0;
}