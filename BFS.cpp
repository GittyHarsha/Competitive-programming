/*
code by harsha_76

*/


#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int>* adj;
    
    public:
    
    Graph(int v)
    : V{v}, adj {new list<int>[v]}
    { }
    
    void addEdge(int u, int v);
    void bfs(int v);
    
};

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

void Graph::bfs(int v)
{
    vector<bool> visited(V, false);
    
    std::queue<int> q;
    visited[v]=true;
    q.push(v);
    while(!q.empty())
    {
        int s= q.front();
        cout<<s<<' ';
        q.pop();
        for(auto it = adj[s].begin();it!=adj[s].end();it++)
        {
            if(!visited[*it])
            {
                visited[*it]=true;
                q.push(*it);
            }
        }
    }
    cout<<'\n';
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    Graph g(7);
    g.addEdge(0, 1); g.addEdge(1, 2); g.addEdge(2, 3); g.addEdge(0, 4); g.addEdge(4, 5); g.addEdge(5, 6);
    g.bfs(0);
    return 0;
}